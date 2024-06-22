from django.db import models


class Event(models.Model):
    event_id = models.TextField(primary_key=True)
    name = models.TextField()
    place = models.TextField()
    date = models.DateField()
    price = models.DecimalField(max_digits=10, decimal_places=2)

    class Meta:
        abstract = True


class Concert(Event):
    genre = models.TextField()

    class Meta:
        db_table = "concerts"


class TheaterPlay(Event):
    play_type = models.TextField()

    class Meta:
        db_table = "theater_plays"


class Performer(models.Model):
    performer_id = models.TextField(primary_key=True)
    event = models.ForeignKey("Event", on_delete=models.CASCADE)
    name = models.TextField()

    class Meta:
        db_table = "performers"
