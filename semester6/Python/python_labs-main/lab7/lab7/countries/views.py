from django.shortcuts import get_object_or_404
from django.views.decorators.csrf import csrf_exempt
from spyne.application import Application
from spyne.decorator import rpc
from spyne.model.primitive import Unicode, Integer, String
from spyne.protocol.soap import Soap11
from spyne.server.django import DjangoApplication
from spyne.service import ServiceBase

from .models import Country, City


class SoapService(ServiceBase):
    @rpc(String, _returns=String)
    def find_country_by_code(ctx, country_code):
        country = get_object_or_404(Country, pk=country_code)
        return country.name

    @rpc(String, _returns=String)
    def find_cities_by_country(ctx, country_code):
        country = get_object_or_404(Country, pk=country_code)
        cities = City.objects.filter(country=country)
        return ", ".join(city.name for city in cities)


soap_app = Application(
    [SoapService],
    tns="django.soap.example",
    in_protocol=Soap11(validator="lxml"),
    out_protocol=Soap11(),
)

django_soap_application = DjangoApplication(soap_app)
soap_application = csrf_exempt(django_soap_application)
