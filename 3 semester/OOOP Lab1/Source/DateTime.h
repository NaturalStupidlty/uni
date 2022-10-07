#ifndef OOOP_LAB1_DATETIME_H
#define OOOP_LAB1_DATETIME_H

#include <ctime>
#include <string>

using std::string;

// Клас для зберігання інформації про дату й час
class DateTime
{
    // Мілісекунди з 01.01.01
    long long int miliseconds;

public:
    // Дефолтний конструктор
    DateTime ();

    // Конструктор копій
    DateTime (const DateTime &value);

    // Створює об'єкт за UTC часом у SQL форматі опису дати
    // "2022-10-07 00:20:21.420"
    explicit DateTime (const string &value);

    // Створює об'єкт за календарним часом time_t
    explicit DateTime (const time_t &time);

    // Створює об'єкт за структурою часу tm
    explicit DateTime (const tm *time);

    // Перевірка правильності дати та часу
    // відповідно до григоріанського календаря ???
    bool isValid() const;

    // Повертає час у мілісекундах
    long long getMiliseconds() const;

    // Конвертує локальний час в UTC
    void toUTC();

    // Конвертує UTC в локальний час
    void fromUTC();

    // Повертає час в UNIX форматі
    time_t asUnixTime() const;

    // Приймає час у вигляді структури
    bool asTime(tm *time) const;

    // Присвоїти значення поточного часу
    void setNow();

    // Чи існує час
    bool hasTime() const;

    // Встановити час за SQL описом
    void set (const string &value);

    // Встановити час за календарним часом time_t
    void set (const time_t &time);

    // Встановити час за структурою часу tm
    void set (const tm *time);

    // Отримати SQL опис дати (yyyy-MM-dd)
    string formatDate() const;

    // Отримати SQL опис дати (yyyy-MM-dd hh:mm:ss)
    string formatDateTime() const;

    // Збільшити дату на певну кількість секунд
    DateTime& incSecond(int seconds);

    // Збільшити дату на певну кількість хвилин
    DateTime& incMinute(int minutes);

    // Збільшити дату на певну кількість годин
    DateTime& incHour(int hours);

    // Збільшити дату на певну кількість днів
    DateTime& incDay(int days);

    // Збільшити дату на певну кількість місяців
    DateTime& incMonth(int months);

    // Збільшити дату на певну кількість років
    DateTime& incYear(int years);

    // Повернути день тижня 0 - Понеділок ... 6 - Неділя
    int getWeekDay() const;

    // Повернути день
    int getDayOfYear() const;

    // Кількість днів між датами
    static int daysBetween(const DateTime &date1, const DateTime &date2);

    // Кількість місяців між датами
    static int monthsBetween(const DateTime &date1, const DateTime &date2);

    // Кількість років між датами
    static int yearsBetween(const DateTime &date1, const DateTime &date2);

    // Чи відрізняються дати менше, ніж на хвилину
    bool identic(const DateTime &other) const;

    DateTime& operator = (const DateTime &date);

    friend bool operator == (const DateTime &date1, const DateTime &date2);
    friend bool operator < (const DateTime &date1, const DateTime &date2);
    friend bool operator != (const DateTime &date1, const DateTime &date2);
    friend bool operator <= (const DateTime &date1, const DateTime &date2);
    friend bool operator > (const DateTime &date1, const DateTime &date2);
    friend bool operator >= (const DateTime &date1, const DateTime &date2);
};

inline bool operator == (const DateTime &date1, const DateTime &date2)
{
    return date1.miliseconds == date2.miliseconds;
}

inline bool operator < (const DateTime &date1, const DateTime &date2)
{
    return date1.miliseconds < date2.miliseconds;
}

inline bool operator != (const DateTime &date1, const DateTime &date2)
{
    return !(date1 == date2);
}

inline bool operator <= (const DateTime &date1, const DateTime &date2)
{
    return date1 < date2 || date1 == date2;
}

inline bool operator > (const DateTime &date1, const DateTime &date2)
{
    return !(date1 <= date2);
}

inline bool operator >= (const DateTime &date1, const DateTime &date2)
{
    return !(date1 < date2);
}

#endif //OOOP_LAB1_DATETIME_H
