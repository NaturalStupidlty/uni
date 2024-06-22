import os
import sqlite3


class DataBase:
    def __init__(self, db_path):
        os.makedirs(os.path.dirname(db_path), exist_ok=True)
        self._connection = sqlite3.connect(db_path, check_same_thread=False)
        self._cursor = self._connection.cursor()
        self._create_tables()

    def _create_tables(self):
        self._cursor.execute(
            """
            CREATE TABLE IF NOT EXISTS events (
                event_id TEXT PRIMARY KEY,
                name TEXT NOT NULL,
                place TEXT NOT NULL,
                date TEXT NOT NULL,
                price REAL NOT NULL,
                type TEXT NOT NULL  -- 'concert' or 'theater_play'
            )
            """
        )

        self._cursor.execute(
            """
            CREATE TABLE IF NOT EXISTS concerts (
                concert_id TEXT PRIMARY KEY,
                genre TEXT NOT NULL,
                FOREIGN KEY (concert_id) REFERENCES events (event_id)
            )
            """
        )

        self._cursor.execute(
            """
            CREATE TABLE IF NOT EXISTS theater_plays (
                play_id TEXT PRIMARY KEY,
                play_type TEXT NOT NULL,
                FOREIGN KEY (play_id) REFERENCES events (event_id)
            )
            """
        )

        self._cursor.execute(
            """
            CREATE TABLE IF NOT EXISTS performers (
                performer_id TEXT PRIMARY KEY,
                event_id TEXT NOT NULL,
                name TEXT NOT NULL,
                FOREIGN KEY (event_id) REFERENCES events (event_id)
            )
            """
        )
        self._connection.commit()

    def add_event(self, event_id, name, place, date, price, event_type):
        self._cursor.execute(
            "INSERT INTO events (event_id, name, place, date, price, type) VALUES (?, ?, ?, ?, ?, ?)",
            (event_id, name, place, date, price, event_type),
        )
        self._connection.commit()

    def add_concert_specifics(self, concert_id, genre):
        self._cursor.execute(
            "INSERT INTO concerts (concert_id, genre) VALUES (?, ?)",
            (concert_id, genre),
        )
        self._connection.commit()

    def add_theater_play_specifics(self, play_id, play_type):
        self._cursor.execute(
            "INSERT INTO theater_plays (play_id, play_type) VALUES (?, ?)",
            (play_id, play_type),
        )
        self._connection.commit()

    def add_performer(self, performer_id, event_id, name):
        self._cursor.execute(
            "INSERT INTO performers (performer_id, event_id, name) VALUES (?, ?, ?)",
            (performer_id, event_id, name),
        )
        self._connection.commit()

    def update_concert(self, concert_id, name, place, genre, date, price):
        # Update event details
        self._cursor.execute(
            "UPDATE events SET name = ?, place = ?, date = ?, price = ? WHERE event_id = ?",
            (name, place, date, price, concert_id),
        )
        # Update concert-specific details
        self._cursor.execute(
            "UPDATE concerts SET genre = ? WHERE concert_id = ?",
            (genre, concert_id),
        )
        self._connection.commit()

    def update_performer(self, performer_id, event_id, name):
        self._cursor.execute(
            "UPDATE performers SET event_id = ?, name = ? WHERE performer_id = ?",
            (event_id, name, performer_id),
        )
        self._connection.commit()

    def delete_performer(self, performer_id):
        self._cursor.execute(
            "DELETE FROM performers WHERE performer_id = ?", (performer_id,)
        )
        self._connection.commit()

    def delete_concert(self, concert_id):
        self._cursor.execute(
            "DELETE FROM concerts WHERE concert_id = ?", (concert_id,)
        )
        self._cursor.execute(
            "DELETE FROM events WHERE event_id = ?", (concert_id,)
        )
        self._connection.commit()

    def find_concert_by_code(self, concert_id):
        self._cursor.execute(
            "SELECT events.*, concerts.genre FROM events JOIN concerts ON events.event_id = concerts.concert_id WHERE concerts.concert_id = ?",
            (concert_id,),
        )
        concert = self._cursor.fetchone()
        return concert

    def find_performers_by_event(self, event_id):
        self._cursor.execute(
            "SELECT * FROM performers WHERE event_id = ?", (event_id,)
        )
        performers = self._cursor.fetchall()
        return performers

    def events(self):
        self._cursor.execute("SELECT * FROM events")
        return self._cursor.fetchall()

    def theater_plays(self):
        self._cursor.execute(
            "SELECT events.*, theater_plays.play_type FROM events JOIN theater_plays ON events.event_id = theater_plays.play_id"
        )
        return self._cursor.fetchall()

    def concerts(self):
        self._cursor.execute(
            "SELECT events.*, concerts.genre FROM events JOIN concerts ON events.event_id = concerts.concert_id"
        )
        return self._cursor.fetchall()

    def performers(self, event_id: str = None):
        if event_id:
            self._cursor.execute(
                "SELECT * FROM performers WHERE event_id = ?", (event_id,)
            )
        else:
            self._cursor.execute("SELECT * FROM performers")
        return self._cursor.fetchall()

    def __del__(self):
        self._connection.close()
