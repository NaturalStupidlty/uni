from dataclasses import dataclass


@dataclass
class Country:
    country_id: int
    country_name: str


class CountriesCollection:
    def __init__(self) -> None:
        self._countries = []

    def __iter__(self) -> iter:
        return iter(self._countries)

    def __next__(self) -> Country:
        return next(self._countries)

    def __getitem__(self, index: int) -> Country:
        if index < 0 or index >= len(self._countries):
            raise IndexError("Index out of range")
        return self._countries[index]

    def __setitem__(self, index: int, value: Country) -> None:
        if index < 0 or index >= len(self._countries):
            raise IndexError("Index out of range")
        self._countries[index] = value

    def add(self, country: Country) -> None:
        if not self._country_exists(country):
            self._countries.append(country)
        else:
            raise ValueError(
                f"Country with id {country.country_id} already exists"
            )

    def _country_exists(self, country: Country) -> bool:
        for c in self._countries:
            if c.country_id == country:
                return True
        return False

    def delete(self, country: Country) -> None:
        if country in self._countries:
            self._countries.remove(country)
        else:
            raise ValueError(
                f"Country with id {country.country_id} does not exist"
            )

    @property
    def countries(self) -> list:
        return self._countries

    @countries.setter
    def countries(self, countries: list) -> None:
        self._countries = countries

    @property
    def countries_count(self) -> int:
        return len(self._countries)

    def get_by_id(self, country_id: int) -> Country:
        for country in self._countries:
            if country.country_id == country_id:
                return country
        return None
