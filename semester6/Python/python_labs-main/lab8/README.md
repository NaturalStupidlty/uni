```
pip install django
django-admin startproject lab7
python manage.py startapp countries
```

### Server
```
python manage.py makemigrations
./manage.py migrate
python manage.py createsuperuser --email admin@example.com --username admin
python manage.py runserver
```

### API
```
http -a admin:password123 http://127.0.0.1:8000/countries/
```
```
http -a admin:password123 http://127.0.0.1:8000/cities/?country_id=UA
```