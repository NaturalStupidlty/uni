from django.urls import path
from django.conf import settings
from django.conf.urls.static import static
from . import views

urlpatterns = [
    path("", views.hello_page, name="hello_page"),
    path("countries/", views.country_list, name="country_list"),
    path(
        "countries/<str:country_id>/cities/", views.city_list, name="city_list"
    ),
]

if settings.DEBUG:
    urlpatterns += static(
        settings.STATIC_URL, document_root=settings.STATIC_ROOT
    )
