import Pyro4


def send_request(command, params=None):
    if params is None:
        params = {}
    server = Pyro4.Proxy(
        "PYRONAME:example.server"
    )  # get a Pyro proxy to the server
    response = server.process_request(command, params)
    print(f"Response from server: {response}")


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
