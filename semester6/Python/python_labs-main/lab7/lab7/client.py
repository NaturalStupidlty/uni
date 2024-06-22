from suds.client import Client
from suds.cache import NoCache

my_client = Client("http://127.0.0.1:8000/soap_service/?WSDL", cache=NoCache())

print(my_client)
print(
    "Function find_country_by_code: ",
    my_client.service.find_country_by_code("DE"),
)
print(
    "Function find_cities_by_country: ",
    my_client.service.find_cities_by_country("DE"),
)
