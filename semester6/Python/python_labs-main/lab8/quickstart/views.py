from rest_framework import viewsets, permissions
from .models import Country, City
from .serializers import CountrySerializer, CitySerializer


class CountryViewSet(viewsets.ModelViewSet):
    """
    API endpoint that allows countries to be viewed or edited.
    """

    queryset = Country.objects.all()
    serializer_class = CountrySerializer
    permission_classes = [permissions.IsAuthenticated]


class CityViewSet(viewsets.ModelViewSet):
    """
    API endpoint that allows cities to be viewed or edited.
    """

    queryset = City.objects.all()
    serializer_class = CitySerializer
    permission_classes = [permissions.IsAuthenticated]

    def get_queryset(self):
        """
        Optionally restricts the returned cities to a given country,
        by filtering against a 'country_id' query parameter in the URL.
        """
        queryset = super().get_queryset()
        country_id = self.request.query_params.get("country_id")
        if country_id is not None:
            queryset = queryset.filter(country__country_id=country_id)
        return queryset
