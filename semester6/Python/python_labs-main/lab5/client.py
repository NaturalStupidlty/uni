import json
import pika
import uuid


def send_request(
    command, params=None, amqp_url="amqp://guest:guest@localhost/"
):
    connection = pika.BlockingConnection(pika.URLParameters(amqp_url))
    channel = connection.channel()
    channel.queue_declare(queue="SRV.Q")
    channel.queue_declare(queue="CL.Q")

    corr_id = str(uuid.uuid4())
    request_data = {"command": command, "params": params if params else {}}
    channel.basic_publish(
        exchange="",
        routing_key="SRV.Q",
        body=json.dumps(request_data).encode("utf-8"),
    )
    print(f"Sent {command} to SRV.Q")

    def on_response(ch, method, properties, body):
        response = json.loads(body.decode())
        print(f"Response from server: {response}")
        connection.close()

    channel.basic_consume(
        queue="CL.Q", on_message_callback=on_response, auto_ack=True
    )
    channel.start_consuming()


if __name__ == "__main__":
    # Example usage
    send_request(
        "add_country", {"country_code": "US", "name": "United States"}
    )
    send_request(
        "add_city",
        {
            "city_code": "NYC",
            "country_code": "US",
            "name": "New York City",
            "population": 8419000,
            "is_capital": True,
        },
    )
