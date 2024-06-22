from lab1.src.objects import City
from lab1.src.objects import Country
from lab1.src.objects import WorldMap


if __name__ == "__main__":
    world_map1 = WorldMap()

    country1 = Country(1, "Україна")
    country2 = Country(2, "Монако")

    city1 = City(1, "Київ", True, 3000000, 1)
    city2 = City(2, "Львів", False, 600000, 1)
    city3 = City(3, "Монако", True, 74285, 2)
    city4 = City(4, "Канни", False, 38400, 2)

    world_map1.add_country(country1)
    world_map1.add_country(country2)
    world_map1.add_city(city1)
    world_map1.add_city(city2)
    world_map1.add_city(city3)
    world_map1.add_city(city4)

    assert world_map1.is_valid("assets/data.xml", "assets/scheme.xsd") is True

    world_map1.save_to_xml("assets/data1.xml")

    world_map2 = WorldMap()
    world_map2.load_from_xml("assets/data1.xml")
    world_map2.save_to_xml("assets/data2.xml")
