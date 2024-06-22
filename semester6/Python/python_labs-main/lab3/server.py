import json
import logging
import socket
import threading

from lab2.database import DataBase


class Server:
    def __init__(self, host: str = "192.168.0.104", port: int = 1488):
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
        self.server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.server_socket.bind((host, port))
        self.server_socket.listen()
        logging.info(f"Server listening on {host}:{port}")
        self.accept_connections()

    def accept_connections(self):
        try:
            while True:
                connection, address = self.server_socket.accept()
                logging.info(f"Connected by {address}")
                thread = threading.Thread(
                    target=self.handle_client, args=(connection, address)
                )
                thread.start()
        finally:
            self.server_socket.close()

    def handle_client(self, connection: socket.socket, address: str):
        logging.info(f"Handling connection from {address}")
        with connection:
            while True:
                data = connection.recv(1024)
                if not data:
                    break
                request = data.decode("utf-8")
                response = self.process_request(request)
                connection.sendall(response.encode("utf-8"))

    def process_request(self, request: str) -> str:
        try:
            data = json.loads(request)
            command = data["command"]
            params = data.get("params", {})
            if command in self.commands:
                response = self.commands[command](**params)
                return json.dumps({"status": "success", "data": response})
            else:
                return json.dumps(
                    {"status": "error", "message": "Unknown command."}
                )
        except Exception as e:
            logging.exception("Error processing request")
            return json.dumps({"status": "error", "message": str(e)})


if __name__ == "__main__":
    logging.basicConfig(level=logging.INFO)
    Server()
