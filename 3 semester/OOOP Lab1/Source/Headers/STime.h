#ifndef OOOP_LAB1_STIME_H
#define OOOP_LAB1_STIME_H

#include <ctime>
#include <string>

using std::string;

/** ------[ Заміна структурі tm з додатковим функціоналом ]------ */

class STime
{
private:
    int year{};
    int month{};
    int day{};
    int hour{};
    int minute{};
    int second{};
    int millisecond{};
    bool valid;

    /** Установити місяць і день за таблицею місяців
     *
     * @param monthTable - масив (таблиця місяців)
     * @param lengths - масив (довжини місяців)
     * @param yearDay - номер дня у році
     */
    void setYearsDay(const int *monthTable, const int *lengths, int yearDay);

public:
    /** Конструктори */

    /** Дефолтний конструктор */
    STime();

    /** Створює об'єкт за кількістю мілісекунд
     *
     * @param time - кількість мілісекунд
     */
    explicit STime(long long time);

    /** Створює об'єкт за календарним часом
     *
     * @param time - кількість секунд, що пройшли типу time_t
     */
    explicit STime(const tm *time);

    /** Створює об'єкт за UTC часом
     *
     * @param value - час у SQL форматі опису дати "2022-10-07 00:20:21.420"
     */
    explicit STime(const string &value);

    /** Геттери */

    /** Отримати роки
     *
     * @return - кількість років
     */
    int getYear() const;

    /** Отримати місяці
     *
     * @return - кількість місяців
     */
    int getMonth() const;

    /** Отримати дні
     *
     * @return - кількість днів
     */
    int getDay() const;

    /** Отримати години
     *
     * @return - кількість годин
     */
    int getHour() const;

    /** Отримати хвилини
     *
     * @return - кількість хвилин
     */
    int getMinute() const;

    /** Отримати секунди
     *
     * @return - кількість секунд
     */
    int getSecond() const;

    /** Отримати мілісекунди
     *
     * @return - кількість мілісекунд
     */
    int getMillisecond() const;

    /** Знайти кількість мілісекунд з 1 Січня 1 року
     *
     * @return - кількість мілісекунд з 01.01.01
     */
    long long get();

    /** Отримати день року
     *
     * @return - порядковий номер дня у році
     */
    int dayOfYear() const;

    /** Збільшити дату на певну кількість днів
     * також може грати роль функції декременту, але тоді потрібно передавати
     * їй від'ємний параметр days
     *
     * @param days - кількість днів
     */
    void increaseDay(int days);

    /** Збільшити дату на певну кількість місяців
     * також може грати роль функції декременту, але тоді потрібно передавати
     * їй від'ємний параметр months
     *
     * @param months - кількість місяців
     */
    void increaseMonth(int months);

    /** Збільшити дату на певну кількість років
     * також може грати роль функції декременту, але тоді потрібно передавати
     * їй від'ємний параметр years
     *
     * @param years - кількість років
     */
    void increaseYear(int years);

    /** Зменшити дату на певну кількість днів
     * також може грати роль функції інкременту, але тоді потрібно передавати
     * їй від'ємний параметр days
     *
     * @param days - кількість днів
     */
    void decreaseDay(int days);

    /** Зменшити дату на певну кількість місяців
     * також може грати роль функції інкременту, але тоді потрібно передавати
     * їй від'ємний параметр months
     *
     * @param months - кількість місяців
     */
    void decreaseMonth(int months);

    /** Зменшити дату на певну кількість років
     * також може грати роль функції інкременту, але тоді потрібно передавати
     * їй від'ємний параметр years
     *
     * @param years - кількість років
     */
    void decreaseYear(int years);

    /** Отримати SQL опис дати
     *
     * @return - дату у SQL форматі (yyyy-MM-dd)
     */
    string formatDate() const;

    /** Отримати SQL опис дати й часу
     *
     * @return дату й час у SQL форматі (yyyy-MM-dd hh:mm:ss)
     */
    string formatDateTime() const;

    /** Отримати кількість місяців з попередньої дати
     * (ця дата-час ПОВИННА бути раніше)
     *
     * @param from - попередня дата, від якої будемо рахувати
     * @return - кількість місяців, що пройшли з дати from
     */
    int monthsAfter(const STime &from) const;

    /** Отримати час за структурою tm
     *
     * @param time - struct std::tm
     */
    void asTime(tm *time) const;
};

#endif //OOOP_LAB1_STIME_H
