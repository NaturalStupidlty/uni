import json
import logging
import pika
from lab2.database import DataBase


class RabbitMQServer:
    def __init__(self, amqp_url="amqp://guest:guest@localhost/"):
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
        self.connection = pika.BlockingConnection(pika.URLParameters(amqp_url))
        self.channel = self.connection.channel()
        self.channel.queue_declare(queue="SRV.Q")
        self.channel.queue_declare(queue="CL.Q")

    def start_server(self):
        self.channel.basic_consume(
            queue="SRV.Q", on_message_callback=self.on_request, auto_ack=True
        )
        logging.info("Server is waiting for messages.")
        self.channel.start_consuming()

    def on_request(self, ch, method, properties, body):
        request_data = json.loads(body.decode())
        response = self.process_request(request_data)
        self.channel.basic_publish(
            exchange="",
            routing_key="CL.Q",
            body=json.dumps(response).encode("utf-8"),
        )
        logging.info(f"Processed request and sent response to CL.Q")

    def process_request(self, request):
        try:
            command = request["command"]
            params = request.get("params", {})
            if command in self.commands:
                response = self.commands[command](**params)
                return {"status": "success", "data": response}
            else:
                return {"status": "error", "message": "Unknown command."}
        except Exception as e:
            logging.exception("Error processing request")
            return {"status": "error", "message": str(e)}


if __name__ == "__main__":
    logging.basicConfig(level=logging.INFO)
    server = RabbitMQServer()
    server.start_server()
