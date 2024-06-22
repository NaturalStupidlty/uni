from django.urls import path
from django.conf import settings
from django.conf.urls.static import static
from . import views

urlpatterns = [
    path("", views.hello_page, name="hello_page"),
    path("events/", views.events_list, name="events_list"),
    path("concerts/", views.concerts_list, name="concerts_list"),
    path(
        "theater_plays/", views.theater_plays_list, name="theater_plays_list"
    ),
    path(
        "concerts/<str:concert_id>/performers/",
        views.performers_list,
        name="performers_list",
    ),
    path(
        "theater_plays/<str:theater_play_id>/performers/",
        views.performers_list,
        name="performers_list",
    ),
]

if settings.DEBUG:
    urlpatterns += static(
        settings.STATIC_URL, document_root=settings.STATIC_ROOT
    )
