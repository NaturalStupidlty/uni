import socket
import json


def send_request(
    command, params=None, server_host="192.168.0.104", server_port=1488
):
    request_data = {"command": command, "params": params if params else {}}
    request_json = json.dumps(request_data)

    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        s.connect((server_host, server_port))
        s.sendall(request_json.encode("utf-8"))
        response = s.recv(1024)
        response_data = json.loads(response.decode("utf-8"))
        print(f"Response from server: {response_data}")


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
