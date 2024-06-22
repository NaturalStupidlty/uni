from django.db import models


class Country(models.Model):
    country_id = models.TextField(primary_key=True)
    name = models.TextField()

    class Meta:
        db_table = "countries"


class City(models.Model):
    city_id = models.TextField(primary_key=True)
    # Django will create a field named country_id in the cities model
    # but naming country_id will result in country_id_id
    country = models.ForeignKey(Country, on_delete=models.CASCADE)
    name = models.TextField()
    population = models.IntegerField()
    is_capital = models.BooleanField()

    class Meta:
        db_table = "cities"
