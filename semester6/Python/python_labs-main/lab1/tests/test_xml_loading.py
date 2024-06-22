from xml.dom import minidom


valid_output = """Country: Україна
ID: 1
City: Київ
City: Львів
Country: Монако
ID: 2
City: Монако
City: Канни
"""


def load_xml():
	DOMTree = minidom.parse("assets/data.xml")
	collection = DOMTree.documentElement
	return collection.getElementsByTagName("Country")


def validate_data(countries):
	output = ""

	for country in countries:
		id = country.getAttribute("id")
		name = country.getAttribute('name')
		output += f"Country: {name}\n"
		output += f"ID: {id}\n"
		cities = country.getElementsByTagName("City")
		for city in cities:
			name = city.getAttribute("name")
			output += f"City: {name}\n"

	assert output == valid_output


def test_xml_loading():
	countries = load_xml()
	validate_data(countries)


if __name__ == "__main__":
	test_xml_loading()
