import os
import sqlite3


class DataBase:
    def __init__(self, db_path="assets/countries_and_cities.db"):
        os.makedirs(os.path.dirname(db_path), exist_ok=True)
        self._connection = sqlite3.connect(db_path, check_same_thread=False)
        self._cursor = self._connection.cursor()
        self._create_tables()

    def _create_tables(self):
        self._cursor.execute(
            """
        CREATE TABLE IF NOT EXISTS countries (
            country_id TEXT PRIMARY KEY,
            name TEXT NOT NULL
        )
        """
        )

        self._cursor.execute(
            """
        CREATE TABLE IF NOT EXISTS cities (
            city_id TEXT PRIMARY KEY,
            country_id TEXT NOT NULL,
            name TEXT NOT NULL,
            population INTEGER,
            is_capital BOOLEAN,
            FOREIGN KEY (country_id) REFERENCES countries (country_id)
        )
        """
        )
        self._connection.commit()

    def add_country(self, country_code, name):
        self._cursor.execute(
            "INSERT INTO countries (country_id, name) VALUES (?, ?)",
            (country_code, name),
        )
        self._connection.commit()

    def add_city(self, city_code, country_code, name, population, is_capital):
        self._cursor.execute(
            "INSERT INTO cities (city_id, country_id, name, population, is_capital) VALUES (?, ?, ?, ?, ?)",
            (city_code, country_code, name, population, is_capital),
        )
        self._connection.commit()

    def update_country(self, country_code, name):
        self._cursor.execute(
            "UPDATE countries SET name = ? WHERE country_id = ?",
            (name, country_code),
        )
        self._connection.commit()

    def update_city(
        self, city_code, country_code, name, population, is_capital
    ):
        self._cursor.execute(
            "UPDATE cities SET country_id = ?, name = ?, population = ?, is_capital = ? WHERE city_id = ?",
            (country_code, name, population, is_capital, city_code),
        )
        self._connection.commit()

    def delete_city(self, city_code):
        self._cursor.execute(
            "DELETE FROM cities WHERE city_id = ?", (city_code,)
        )
        self._connection.commit()

    def delete_country(self, country_code):
        self._cursor.execute(
            "DELETE FROM countries WHERE country_id = ?", (country_code,)
        )
        self._connection.commit()

    def find_country_by_code(self, country_code):
        self._cursor.execute(
            "SELECT * FROM countries WHERE country_id = ?", (country_code,)
        )
        country = self._cursor.fetchone()
        return country

    def find_cities_by_country(self, country_code):
        self._cursor.execute(
            "SELECT * FROM cities WHERE country_id = ?", (country_code,)
        )
        cities = self._cursor.fetchall()
        return cities

    def countries(self):
        self._cursor.execute("SELECT * FROM countries")
        return self._cursor.fetchall()

    def cities(self, country_code: str = None):
        if country_code:
            self._cursor.execute(
                "SELECT * FROM cities WHERE country_id = ?", (country_code,)
            )
        else:
            self._cursor.execute("SELECT * FROM cities")
        return self._cursor.fetchall()

    def __del__(self):
        self._connection.close()
