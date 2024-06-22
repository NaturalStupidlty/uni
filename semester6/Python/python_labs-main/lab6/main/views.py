from django.shortcuts import render

from .models import Country, City


def hello_page(request):
    return render(request, "hello.html")


def country_list(request):
    countries = Country.objects.all()
    return render(request, "country_list.html", {"countries": countries})


def city_list(request, country_id):
    cities = City.objects.filter(country_id=country_id)
    return render(request, "city_list.html", {"cities": cities})
