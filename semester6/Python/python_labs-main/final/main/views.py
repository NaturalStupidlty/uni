from django.shortcuts import render

from .models import Concert, Performer


def hello_page(request):
    return render(request, "hello.html")


def events_list(request):
    return render(request, "events_list.html")


def concerts_list(request):
    concerts = Concert.objects.all()
    return render(request, "concerts_list.html", {"concerts": concerts})


def theater_plays_list(request):
    return render(request, "theater_plays_list.html")


def performers_list(request, concert_id):
    performers = Performer.objects.filter(concert_id=concert_id)
    return render(request, "performers_list.html", {"performers": performers})
