from dataclasses import dataclass


@dataclass
class City:
	city_id: int
	city_name: str
	is_capital: bool
	population: int
	country_id: int


class CitiesCollection:
	def __init__(self) -> None:
		self._cities = []

	def __iter__(self) -> iter:
		return iter(self._cities)

	def __next__(self) -> City:
		return next(self._cities)

	def __getitem__(self, index: int) -> City:
		if index < 0 or index >= len(self._cities):
			raise IndexError("Index out of range")
		return self._cities[index]

	def __setitem__(self, index: int, value: City) -> None:
		if index < 0 or index >= len(self._cities):
			raise IndexError("Index out of range")
		self._cities[index] = value

	def add(self, city: City) -> None:
		if not self._city_exists(city):
			self._cities.append(city)
		else:
			raise ValueError(f"City with id {city.city_id} already exists")

	def _city_exists(self, city: City) -> bool:
		for c in self._cities:
			if c.city_id == city.city_id:
				return True
		return False

	def delete(self, city: City) -> None:
		if city in self._cities:
			self._cities.remove(city)
		else:
			raise ValueError(f"City with id {city.city_id} does not exist")

	@property
	def cities(self) -> list:
		return self._cities

	@cities.setter
	def cities(self, cities: list) -> None:
		self._cities = cities

	@property
	def cities_count(self) -> int:
		return len(self._cities)

	def get_by_id(self, city_id: int) -> City:
		for city in self._cities:
			if city.city_id == city_id:
				return city
		return None
