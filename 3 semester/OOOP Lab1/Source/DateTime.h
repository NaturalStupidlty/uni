#ifndef OOOP_LAB1_DATETIME_H
#define OOOP_LAB1_DATETIME_H

#include <iostream>
#include <ctime>

class DateTime
{
private:
    time_t timeStamp;
    tm* dateTimeStructure;
public:
    // Дефолтний конструктор, що створює об'єкт
    // за поточним локальним часом
    DateTime();

    // Створення об'єкту за календарним часом
    DateTime(time_t time);

    // Створення об'єкту за структурою часу
    DateTime(tm* timeStructure);

    // Створення об'єкту за описом
    DateTime(
            int tm_sec,
            int tm_min,
            int tm_hour,
            int tm_mday,
            int tm_mon,
            int tm_year,
            int tm_wday = 0,
            int tm_yday = 0,
            int tm_isdst = 0);

    // Показати час
    void show();
};
 class DateAndTime{

 };

#endif //OOOP_LAB1_DATETIME_H
