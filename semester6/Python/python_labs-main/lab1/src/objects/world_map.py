from xml.dom import minidom

import lxml.etree

from .city import City, CitiesCollection
from .country import Country, CountriesCollection


class WorldMap:
    def __init__(self):
        self._countries = CountriesCollection()
        self._cities = CitiesCollection()

    def __getitem__(self, item: int) -> Country:
        return self._countries[item]

    def add_country(self, country: Country) -> None:
        self._countries.add(country)

    def add_city(self, city: City) -> None:
        self._cities.add(city)

    def get_country(self, country_id: int) -> Country:
        return self._countries.get_by_id(country_id)

    def get_city(self, city_id: int) -> City:
        return self._cities.get_by_id(city_id)

    @property
    def countries(self) -> CountriesCollection:
        return self._countries

    @countries.setter
    def countries(self, countries: CountriesCollection) -> None:
        self._countries = countries

    @property
    def cities(self) -> CitiesCollection:
        return self._cities

    @cities.setter
    def cities(self, cities: CitiesCollection) -> None:
        self._cities = cities

    @staticmethod
    def is_valid(filename, schema_path: str) -> bool:
        xml_validator = lxml.etree.XMLSchema(lxml.etree.parse(schema_path))

        xml_file = lxml.etree.parse(filename)
        is_valid = xml_validator.validate(xml_file)
        return is_valid

    def load_from_xml(self, filename):
        for country_node in minidom.parse(
            filename
        ).documentElement.getElementsByTagName("Country"):
            self._countries.add(
                Country(
                    country_node.getAttribute("id"),
                    country_node.getAttribute("name"),
                )
            )

            for city_node in country_node.getElementsByTagName("City"):
                album = City(
                    city_node.getAttribute("id"),
                    city_node.getAttribute("name"),
                    city_node.getAttribute("is_capital"),
                    city_node.getAttribute("population"),
                    country_node.getAttribute("id"),
                )
                self.cities.add(album)

    def save_to_xml(self, filename):
        doc = minidom.Document()
        root = doc.createElement("WorldMap")
        doc.appendChild(root)

        for country in self.countries:
            country_node = doc.createElement("Country")
            country_node.setAttribute("id", str(country.country_id))
            country_node.setAttribute("name", str(country.country_name))

            for city in self.cities:
                if city.country_id == country.country_id:
                    city_node = doc.createElement("City")
                    city_node.setAttribute("id", str(city.city_id))
                    city_node.setAttribute("name", str(city.city_name))
                    city_node.setAttribute("is_capital", str(city.is_capital))
                    city_node.setAttribute("population", str(city.population))
                    country_node.appendChild(city_node)

            root.appendChild(country_node)

        with open(filename, "w") as file:
            file.write(doc.toprettyxml(indent="  "))
