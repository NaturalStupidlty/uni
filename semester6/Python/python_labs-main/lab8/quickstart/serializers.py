from rest_framework import serializers
from .models import Country, City


class CountrySerializer(serializers.HyperlinkedModelSerializer):
    class Meta:
        model = Country
        fields = ["url", "country_id", "name"]


class CitySerializer(serializers.HyperlinkedModelSerializer):
    class Meta:
        model = City
        fields = [
            "url",
            "city_id",
            "country",
            "name",
            "population",
            "is_capital",
        ]
