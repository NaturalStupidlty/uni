#ifndef OOOP_LAB1_DATETIME_H
#define OOOP_LAB1_DATETIME_H

#include <ctime>
#include <string>

#include "../Headers/doctest.h"

using std::string;

/** ------[ Клас для зберігання інформації про дату й час ]------ */
class DateTime
{
private:
    /** Мілісекунди з 01.01.01 */
    long long int milliseconds;

public:
    /** ------[ Конструктори ]------ */

    /** Дефолтний конструктор
     *  Встановлює некоректний час */
    DateTime ();

    /** Конструктор копій
     *
     * @param value - об'єкт для копіювання
     */
    DateTime (const DateTime &value);

    /** Створює об'єкт за UTC часом
     *
     * @param value - час у SQL форматі опису дати "2022-10-07 00:20:21.420"
     */
    explicit DateTime (const string &value);

    /** Створює об'єкт за календарним часом
     *
     * @param time - кількість секунд, що пройшли типу time_t
     */
    explicit DateTime (const time_t &time);

    /** Створює об'єкт за структурою часу tm
     *
     * @param time - struct std::tm
     */
    explicit DateTime (const tm *time);

    /** ------[ Підтримка часових зон ]------ */

    /** Конвертує локальний час в UTC
     * DateTime не зберігає у собі часову зону
     * тому про це треба подбати перед викликом */

    void toUTC();

    /** Конвертує UTC в локальний час
     * DateTime не зберігає у собі часову зону
     * тому про це треба подбати перед викликом */
    void fromUTC();

    /** ------[ Присвоєння часу ]------ */

    /** Присвоїти значення поточного часу (UTC) */
    void setNow();

    /** Встановити час за SQL описом
     *
     * @param value - дата й час в UTC у форматі SQL: "2017-01-17 17:19:21"
     */
    void set (const string &value);

    /** Встановити час за календарним часом time_t
     *
     * @param time - значення time_t (мілісекунди від UNIX епохи)
     */
    void set (const time_t &time);

    /** Встановити час за структурою часу tm
     *
     * @param time - дата й час у вигляді структури tm
     */
    void set (const tm *time);

    /** ------[ Отримати час ]------ */

    /** Перевірка правильності дати та часу
     *
     * @return - false, якщо об'єкт не містить коректної дати і true у іншому випадку
     */
    bool isValid() const;

    /** Отримати час у мілісекундах
     *
     * @return - кількість мілісекунд з 01.01.01
     */
    long long getMiliseconds() const;

    /** Отримати час в UNIX форматі
     *
     * @return - дату й час у UNIX time_t форматі
     */
    time_t asUnixTime() const;

    /** Отримати SQL опис дати
     *
     * @return - дату у SQL форматі (yyyy-MM-dd) або пусту стрічку, якщо введена дата некоректна
     */
    string formatDate() const;

    /** Отримати SQL опис дати
     *
     * @return - дату у SQL форматі (yyyy-MM-dd hh:mm:ss) або пусту стрічку, якщо введена дата некоректна
     */
    string formatDateTime() const;

    /** Отримати день тижня
     *
     * @return - число: 0 - Понеділок ... 6 - Неділя
     */
   int getWeekDay() const;

    /** Отримати день року
     *
     * @return - порядковий номер дня у році або -1
     */
    int getDayOfYear() const;

    /** Отримати тиждень року
     *
     * @return - порядковий номер тижня у році або -1
     */
    int getWeekOfYear() const;

    /** ------[ Арифметика часу ]------ */

    /** Збільшити дату на певну кількість одиниць
     * також може грати роль функції декременту, але тоді потрібно передавати
     * їй від'ємні параметри
     *
     * @param seconds - кількість секунд
     * @param minutes - кількість хвилин
     * @param hours - кількість годин
     * @param days - кількість днів
     * @param months - кількість місяців
     * @param years - кількість років
     * @return - змінений об'єкт
     */
    DateTime& increaseBy(int seconds, int minutes, int hours, int days, int months, int years);

    /** Зменшити дату на певну кількість одиниць
     * також може грати роль функції інкременту, але тоді потрібно передавати
     * їй від'ємні параметри
     *
     * @param seconds - кількість секунд
     * @param minutes - кількість хвилин
     * @param hours - кількість годин
     * @param days - кількість днів
     * @param months - кількість місяців
     * @param years - кількість років
     * @return - змінений об'єкт
     */
    DateTime& decreaseBy(int seconds, int minutes, int hours, int days, int months, int years);

    /** Збільшити дату на певну кількість секунд
     * також може грати роль функції декременту, але тоді потрібно передавати
     * їй від'ємний параметр seconds
     *
     * @param seconds - кількість секунд
     * @return - змінений об'єкт
     */
    DateTime& increaseBySeconds(int seconds);

    /** Збільшити дату на певну кількість хвилин
     * також може грати роль функції декременту, але тоді потрібно передавати
     * їй від'ємний параметр minutes
     *
     * @param minutes - кількість хвилин
     * @return - змінений об'єкт
     */
    DateTime& increaseByMinutes(int minutes);

    /** Збільшити дату на певну кількість годин
     * також може грати роль функції декременту, але тоді потрібно передавати
     * їй від'ємний параметр hours
     *
     * @param hours - кількість годин
     * @return - змінений об'єкт
     */
    DateTime& increaseByHours(int hours);

    /** Збільшити дату на певну кількість днів
     * також може грати роль функції декременту, але тоді потрібно передавати
     * їй від'ємний параметр days
     *
     * @param days - кількість днів
     * @return - змінений об'єкт
     */
    DateTime& increaseByDays(int days);

    /** Збільшити дату на певну кількість місяців
     * також може грати роль функції декременту, але тоді потрібно передавати
     * їй від'ємний параметр months
     *
     * @param months - кількість місяців
     * @return - змінений об'єкт
     */
    DateTime& increaseByMonths(int months);

    /** Збільшити дату на певну кількість років
     * також може грати роль функції декременту, але тоді потрібно передавати
     * їй від'ємний параметр years
     *
     * @param years - кількість років
     * @return - змінений об'єкт
     */
    DateTime& increaseByYears(int years);

    /** Зменшити дату на певну кількість секунд
     * також може грати роль функції інкременту, але тоді потрібно передавати
     * їй від'ємний параметр seconds
     *
     * @param seconds - кількість секунд
     * @return - змінений об'єкт
     */
    DateTime& decreaseBySeconds(int seconds);

    /** Зменшити дату на певну кількість хвилин
     * також може грати роль функції інкременту, але тоді потрібно передавати
     * їй від'ємний параметр minutes
     *
     * @param minutes - кількість хвилин
     * @return - змінений об'єкт
     */
    DateTime& decreaseByMinutes(int minutes);

    /** Зменшити дату на певну кількість годин
     * також може грати роль функції інкременту, але тоді потрібно передавати
     * їй від'ємний параметр hours
     *
     * @param hours - кількість годин
     * @return - змінений об'єкт
     */
    DateTime& decreaseByHours(int hours);

    /** Зменшити дату на певну кількість днів
     * також може грати роль функції інкременту, але тоді потрібно передавати
     * їй від'ємний параметр days
     *
     * @param days - кількість днів
     * @return - змінений об'єкт
     */
    DateTime& decreaseByDays(int days);

    /** Зменшити дату на певну кількість місяців
     * також може грати роль функції інкременту, але тоді потрібно передавати
     * їй від'ємний параметр months
     *
     * @param months - кількість місяців
     * @return - змінений об'єкт
     */
    DateTime& decreaseByMonths(int months);

    /** Зменшити дату на певну кількість років
     * також може грати роль функції інкременту, але тоді потрібно передавати
     * їй від'ємний параметр years
     *
     * @param years - кількість років
     * @return - змінений об'єкт
     */
    DateTime& decreaseByYears(int years);

    /** Кількість мілісекунд між датами
     *
     * @param date1 - перша дата
     * @param date2 - друга дата
     * @return - кількість мілісекунд між двома датами або -1
     */
    static long long int millisecondsBetween(const DateTime &date1, const DateTime &date2);

    /** Кількість секунд між датами
     *
     * @param date1 - перша дата
     * @param date2 - друга дата
     * @return - кількість повних секунд між двома датами або -1
     */
    static int secondsBetween(const DateTime &date1, const DateTime &date2);

    /** Кількість хвилин між датами
     *
     * @param date1 - перша дата
     * @param date2 - друга дата
     * @return - кількість повних хвилин між двома датами або -1
     */
    static int minutesBetween(const DateTime &date1, const DateTime &date2);

    /** Кількість годин між датами
     *
     * @param date1 - перша дата
     * @param date2 - друга дата
     * @return - кількість повних годин між двома датами або -1
     */
    static int hoursBetween(const DateTime &date1, const DateTime &date2);

    /** Кількість днів між датами
     *
     * @param date1 - перша дата
     * @param date2 - друга дата
     * @return - кількість повних днів між двома датами або -1
     */
   static int daysBetween(const DateTime &date1, const DateTime &date2);

    /** Кількість місяців між датами
     *
     * @param date1 - перша дата
     * @param date2 - друга дата
     * @return - кількість повних місяців між двома датами або -1
     */
    static int monthsBetween(const DateTime &date1, const DateTime &date2);

    /** Кількість років між датами
     *
     * @param date1 - перша дата
     * @param date2 - друга дата
     * @return - кількість повних років між двома датами або -1
     */
    static int yearsBetween(const DateTime &date1, const DateTime &date2);

    /** ------[ Перевантаження операторів ]------ */

    /** Віднімання
     *
     * @param date - від'ємник
     * @return - змінений об'єкт
     */
    DateTime& operator - (const DateTime &date);

    /** Додавання
     *
     * @param date - доданок
     * @return - змінений об'єкт
     */
    DateTime& operator + (const DateTime &date);

    /** Присвоєння
     *
     * @param date - значення об'єкту
     * @return - змінений об'єкт
     */
    DateTime& operator = (const DateTime &date) = default;

    /** Присвоєння
     *
     * @param date - значення в мілісекундах
     * @return - змінений об'єкт
     */
    DateTime& operator = (int numberOfMilliseconds);

    /** Перевірка на рівність
     *
     * @param date1 - перший об'єкт
     * @param date2 - другий об'єкт
     * @return - true, якщо об'єкти рівні та false, якщо ні
     */
    friend bool operator == (const DateTime &date1, const DateTime &date2);

    /** Менше
     *
     * @param date1 - перший об'єкт
     * @param date2 - другий об'єкт
     * @return - true, якщо перший об'єкт менше за другий та false в іншому випадку
     */
    friend bool operator < (const DateTime &date1, const DateTime &date2);

    /** Не рівне
     *
     * @param date1 - перший об'єкт
     * @param date2 - другий об'єкт
     * @return - true, якщо об'єкти не рівні та false, якщо рівні
     */
    friend bool operator != (const DateTime &date1, const DateTime &date2);

    /** Менше-рівне
     *
     * @param date1 - перший об'єкт
     * @param date2 - другий об'єкт
     * @return - true, якщо перший об'єкт менший або рівний за другий та false, якщо більший
     */
    friend bool operator <= (const DateTime &date1, const DateTime &date2);

    /** Більше
     *
     * @param date1 - перший об'єкт
     * @param date2 - другий об'єкт
     * @return - true, якщо перший об'єкт більший за другий та false в іншому випадку
     */
    friend bool operator > (const DateTime &date1, const DateTime &date2);

    /** Більше-рівне
     *
     * @param date1 - перший об'єкт
     * @param date2 - другий об'єкт
     * @return - true, якщо перший об'єкт більший або рівний за другий та false, якщо менший
     */
    friend bool operator >= (const DateTime &date1, const DateTime &date2);
};
#endif //OOOP_LAB1_DATETIME_H
