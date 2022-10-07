#ifndef OOOP_LAB1_STIME_H
#define OOOP_LAB1_STIME_H

#include <ctime>
#include <string>

using std::string;


/** ------[ Заміна структурі tm з додатковим функціоналом ]------ **/

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

    // Отримати місяць і день з таблиці місяців
    void setYearsDay(const int *monthTable, const int *lengths, int yearDay);

public:
    // Конструктори
    STime();
    explicit STime(long long time);
    explicit STime(const tm *time);
    explicit STime(const string &value);

    // Геттери
    int getYear() const;
    int getMonth() const;
    int getDay() const;
    int getHour() const;
    int getMinute() const;
    int getSecond() const;
    int getMillisecond() const;

    // Мілісекунди з 1 січня 1 року
    long long get();

    // Повертає день у році
    int dayOfYear() const;

    // Додати дні
    void increaseDay(int days);

    // Додати місяці
    void increaseMonth(int months);

    // Додати роки
    void increaseYear(int years);

    // Відняти дні
    void decreaseDay(int days);

    // Відняти місяці
    void decreaseMonth(int months);

    // Відняти роки
    void decreaseYear(int years);

    // Вивести дату у форматі yyyy-MM-dd
    string formatDate() const;

    // Вивести дату у форматі yyyy-MM-dd hh:mm:ss
    string formatDateTime() const;

    // Отримати кількість місяців з попередньої дати
    // (ця дата-час ПОВИННА бути раніше)
    int monthsAfter(const STime &from) const;

    // Час у формі структури tm
    void asTime(tm *time) const;
};

#endif //OOOP_LAB1_STIME_H
