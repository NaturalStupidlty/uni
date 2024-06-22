import Pyro4
from lab2.database import DataBase
import logging


@Pyro4.expose
class Server:
    def __init__(self):
        self._database = DataBase()
        self.commands = {
            "add_country": self._database.add_country,
            "add_city": self._database.add_city,
            "update_country": self._database.update_country,
            "update_city": self._database.update_city,
            "delete_city": self._database.delete_city,
            "delete_country": self._database.delete_country,
            "find_country_by_code": self._database.find_country_by_code,
            "find_cities_by_country": self._database.find_cities_by_country,
            "countries": self._database.countries,
            "cities": self._database.cities,
        }

    def process_request(self, command, params=None):
        if params is None:
            params = {}
        try:
            if command in self.commands:
                response = self.commands[command](**params)
                return {"status": "success", "data": response}
            else:
                return {"status": "error", "message": "Unknown command."}
        except Exception as e:
            logging.exception("Error processing request")
            return {"status": "error", "message": str(e)}


def start_server():
    server = Server()
    daemon = Pyro4.Daemon()
    uri = daemon.register(server)
    ns = Pyro4.locateNS()
    ns.register("example.server", uri)

    logging.info("Server is ready.")
    daemon.requestLoop()


if __name__ == "__main__":
    logging.basicConfig(level=logging.INFO)
    start_server()
