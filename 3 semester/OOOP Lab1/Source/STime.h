#ifndef OOOP_LAB1_STIME_H
#define OOOP_LAB1_STIME_H

#include <ctime>
#include <string>

using std::string;

// Заміна структурі tm з додатковим функціоналом
class STime
{
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
    STime();
    explicit STime(long long time);
    explicit STime(const tm *time);
    explicit STime(const string &value);

    // Мілісекунди з 1 січня 1 року
    long long get();

    // Повертає день у році
    int dayOfYear() const;

    // Додати місяці
    void incMonth(int months) { month += months; }

    // Додати роки
    void incYear(int years) { year += years; }

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
