import random
import string
from datetime import datetime, timedelta

from database import DataBase

def random_string(length=6):
    letters = string.ascii_uppercase
    return ''.join(random.choice(letters) for i in range(length))


# Generate random date within a range
def random_date(start_date, end_date):
    delta = end_date - start_date
    int_delta = (delta.days * 24 * 60 * 60) + delta.seconds
    random_second = random.randrange(int_delta)
    return start_date + timedelta(seconds=random_second)


def main():
    db = DataBase("../assets/concerts.db")
    # Sample data for concerts
    concerts = [
        ("C001", "Rock Festival", "New York", "Rock",
         random_date(datetime(2023, 1, 1), datetime(2023, 12, 31)).strftime("%Y-%m-%d"),
         round(random.uniform(20, 100), 2)),
        ("C002", "Jazz Night", "Chicago", "Jazz",
         random_date(datetime(2023, 1, 1), datetime(2023, 12, 31)).strftime("%Y-%m-%d"),
         round(random.uniform(20, 100), 2)),
        ("C003", "Classical Evening", "Vienna", "Classical",
         random_date(datetime(2023, 1, 1), datetime(2023, 12, 31)).strftime("%Y-%m-%d"),
         round(random.uniform(20, 100), 2)),
        ("C004", "Pop Extravaganza", "Los Angeles", "Pop",
         random_date(datetime(2023, 1, 1), datetime(2023, 12, 31)).strftime("%Y-%m-%d"),
         round(random.uniform(20, 100), 2)),
        ("C005", "Hip-Hop Showdown", "Atlanta", "Hip-Hop",
         random_date(datetime(2023, 1, 1), datetime(2023, 12, 31)).strftime("%Y-%m-%d"),
         round(random.uniform(20, 100), 2)),
        ("C006", "Blues Bash", "Memphis", "Blues",
         random_date(datetime(2023, 1, 1), datetime(2023, 12, 31)).strftime("%Y-%m-%d"),
         round(random.uniform(20, 100), 2)),
        ("C007", "Country Fair", "Nashville", "Country",
         random_date(datetime(2023, 1, 1), datetime(2023, 12, 31)).strftime("%Y-%m-%d"),
         round(random.uniform(20, 100), 2)),
        ("C008", "Metal Mayhem", "London", "Metal",
         random_date(datetime(2023, 1, 1), datetime(2023, 12, 31)).strftime("%Y-%m-%d"),
         round(random.uniform(20, 100), 2)),
        ("C009", "Reggae Rhythms", "Kingston", "Reggae",
         random_date(datetime(2023, 1, 1), datetime(2023, 12, 31)).strftime("%Y-%m-%d"),
         round(random.uniform(20, 100), 2)),
        ("C010", "Indie Delight", "Seattle", "Indie",
         random_date(datetime(2023, 1, 1), datetime(2023, 12, 31)).strftime("%Y-%m-%d"),
         round(random.uniform(20, 100), 2)),
        ("C011", "Electronic Escape", "Berlin", "Electronic",
         random_date(datetime(2023, 1, 1), datetime(2023, 12, 31)).strftime("%Y-%m-%d"),
         round(random.uniform(20, 100), 2)),
        ("C012", "Folk Fest", "Dublin", "Folk",
         random_date(datetime(2023, 1, 1), datetime(2023, 12, 31)).strftime("%Y-%m-%d"),
         round(random.uniform(20, 100), 2)),
    ]

    # Sample data for performers
    performers = [
        ("P001", "C001", "The Rockers"),
        ("P002", "C001", "Guitar Heroes"),
        ("P003", "C002", "Smooth Jazz Band"),
        ("P004", "C002", "Jazz Trio"),
        ("P005", "C003", "String Quartet"),
        ("P006", "C003", "Symphony Orchestra"),
        ("P007", "C004", "Pop Stars"),
        ("P008", "C004", "Top 40 Band"),
        ("P009", "C005", "Hip-Hop Crew"),
        ("P010", "C005", "Rappers United"),
        ("P011", "C006", "Blues Legends"),
        ("P012", "C006", "Harmonica Masters"),
        ("P013", "C007", "Country Singers"),
        ("P014", "C007", "Western Band"),
        ("P015", "C008", "Metal Heads"),
        ("P016", "C008", "Heavy Metal Band"),
        ("P017", "C009", "Reggae Icons"),
        ("P018", "C009", "Rastafari Band"),
        ("P019", "C010", "Indie Artists"),
        ("P020", "C010", "Alternative Band"),
        ("P021", "C011", "EDM DJ"),
        ("P022", "C011", "Techno Group"),
        ("P023", "C012", "Folk Singers"),
        ("P024", "C012", "Traditional Band"),
    ]

    # Add concerts to the database
    for concert_code, name, place, genre, date, price in concerts:
        db.add_concert(concert_code, name, place, genre, date, price)

    # Add performers to the database
    for performer_code, concert_code, name in performers:
        db.add_performer(performer_code, concert_code, name)

    # Fetch and print all concerts
    all_concerts = db.concerts()
    print("Concerts:")
    for concert in all_concerts:
        print(concert)

    # Fetch and print all performers
    all_performers = db.performers()
    print("\nPerformers:")
    for performer in all_performers:
        print(performer)


if __name__ == "__main__":
    main()
