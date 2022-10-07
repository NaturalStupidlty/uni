#ifndef OOOP_LAB1_DATETIME_H
#define OOOP_LAB1_DATETIME_H

#include <ctime>
#include <string>

using std::string;

/** ------[ Клас для зберігання інформації про дату й час ]------ **/

class DateTime
{
private:
    // Мілісекунди з 01.01.01
    long long int milliseconds;

public:

    /** ------[ Конструктори ]------ **/

    // Дефолтний конструктор
    // Встановлює некоректний час
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

    /** ------[ Підтримка часових зон ]------ **/

    // Конвертує локальний час в UTC
    void toUTC();

    // Конвертує UTC в локальний час
    void fromUTC();

    /** ------[ Присвоєння часу ]------ **/

    // Присвоїти значення поточного часу
    void setNow();

    // Встановити час за SQL описом
    void set (const string &value);

    // Встановити час за календарним часом time_t
    void set (const time_t &time);

    // Встановити час за структурою часу tm
    void set (const tm *time);

    /** ------[ Отримати час ]------ **/

    // Перевірка правильності дати та часу
    bool isValid() const;

    // Отримати час у мілісекундах
    long long getMiliseconds() const;

    // Отримати час в UNIX форматі
    time_t asUnixTime() const;

    // Отримати SQL опис дати (yyyy-MM-dd)
    string formatDate() const;

    // Отримати SQL опис дати (yyyy-MM-dd hh:mm:ss)
    string formatDateTime() const;

    // Отримати день тижня
    // 0 - Понеділок ... 6 - Неділя
    int getWeekDay() const;

    // Отримати день року
    int getDayOfYear() const;

    // Отримати тиждень року
    int getWeekOfYear() const;

    /** ------[ Арифметика часу ]------ **/

    // Збільшити дату на певну кількість одиниць
    DateTime& increaseBy(int seconds, int minutes, int hours, int days, int months, int years);

    // Зменшити дату на певну кількість одиниць
    DateTime& decreaseBy(int seconds, int minutes, int hours, int days, int months, int years);

    // Збільшити дату на певну кількість секунд
    DateTime& increaseBySeconds(int seconds);

    // Збільшити дату на певну кількість хвилин
    DateTime& increaseByMinutes(int minutes);

    // Збільшити дату на певну кількість годин
    DateTime& increaseByHours(int hours);

    // Збільшити дату на певну кількість днів
    DateTime& increaseByDays(int days);

    // Збільшити дату на певну кількість місяців
    DateTime& increaseByMonths(int months);

    // Збільшити дату на певну кількість років
    DateTime& increaseByYears(int years);

    // Зменшити дату на певну кількість секунд
    DateTime& decreaseBySeconds(int seconds);

    // Зменшити дату на певну кількість хвилин
    DateTime& decreaseByMinutes(int minutes);

    // Зменшити дату на певну кількість годин
    DateTime& decreaseByHours(int hours);

    // Зменшити дату на певну кількість днів
    DateTime& decreaseByDays(int days);

    // Зменшити дату на певну кількість місяців
    DateTime& decreaseByMonths(int months);

    // Зменшити дату на певну кількість років
    DateTime& decreaseByYears(int years);

    // Кількість мілісекунд між датами
    static long long int millisecondsBetween(const DateTime &date1, const DateTime &date2);

    // Кількість секунд між датами
    static int secondsBetween(const DateTime &date1, const DateTime &date2);

    // Кількість хвилин між датами
    static int minutesBetween(const DateTime &date1, const DateTime &date2);

    // Кількість годин між датами
    static int hoursBetween(const DateTime &date1, const DateTime &date2);

    // Кількість днів між датами
    static int daysBetween(const DateTime &date1, const DateTime &date2);

    // Кількість місяців між датами
    static int monthsBetween(const DateTime &date1, const DateTime &date2);

    // Кількість років між датами
    static int yearsBetween(const DateTime &date1, const DateTime &date2);

    /** ------[ Перевантаження операторів ]------ **/

    DateTime& operator - (const DateTime &date);
    DateTime& operator + (const DateTime &date);

    DateTime& operator = (const DateTime &date) = default;

    DateTime& operator = (int number);

    friend bool operator == (const DateTime &date1, const DateTime &date2);
    friend bool operator < (const DateTime &date1, const DateTime &date2);
    friend bool operator != (const DateTime &date1, const DateTime &date2);
    friend bool operator <= (const DateTime &date1, const DateTime &date2);
    friend bool operator > (const DateTime &date1, const DateTime &date2);
    friend bool operator >= (const DateTime &date1, const DateTime &date2);
};
#endif //OOOP_LAB1_DATETIME_H
