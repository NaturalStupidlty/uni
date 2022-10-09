#include "../Headers/STime.h"
#include "../Headers/DateTimeConstants.h"
#include <sstream>
#include <iomanip>

using std::istringstream;
using std::ostringstream;
using std::setfill;
using std::setw;

 /** Перевірка чи рік високосний
  *
  * @param year - рік
  * @return - 1, якщо так та 0, якщо ні
  */
inline bool isLeap (int year)
{
    // За Григоріанським календарем
    return (year % 4 == 0) && ((year % 100 != 0) || (year % 400 == 0));
}

/** Кількість днів у високосному році */
inline int getLeapDays(int years)
{
    // За Григоріанським календарем
    return years / 4 - years / 100 + years / 400;
}

STime::STime():
        year(0),
        month(0),
        day(0),
        hour(0),
        minute(0),
        second(0),
        millisecond(0),
        valid(true)
{}

STime::STime(const tm *time)
{
    if (time)
    {
        year = time->tm_year + TM_START_YEAR;
        month = time->tm_mon;
        day = time->tm_mday;
        hour = time->tm_hour;
        minute = time->tm_min;
        second = time->tm_sec;
        millisecond = 0;

        valid = year >= TM_START_YEAR
                && day > 0
                && day <= MONTH_LENGTHS[month]
                && hour >= 0
                && minute >= 0
                && second >= 0;
    }
    else
    {
        memset(this, 0, sizeof(STime));
        valid = false;
    }
}

STime::STime(const string &value)
{
    // Читаємо відповідні поля зі строки
    memset (this, 0, sizeof(STime));
    char dummy;
    istringstream str(value);

    str >> year;
    valid = !str.fail();

    str >> dummy >> month;
    valid &= !str.fail();

    str >> dummy >> day;
    valid &= !str.fail();

    if (!str.eof())
    {
        // Введено також час
        if (!(str >> hour)
            || !(str >> dummy >> minute)
            || !(str >> dummy >> second))
            valid = false;

        str >> dummy >> millisecond;
    }

    // Місяці починаються з 0
    month--;
}

STime::STime (long long time): valid(true)
{
    millisecond = time % TIME_MULTIPLIER;

    // Ігноруємо мілісекунди
    time /= TIME_MULTIPLIER;

    // Секунд пройшло з початку дня
    second = time % SECS_IN_DAY;

    hour = second / SECS_IN_HOUR;
    second %= SECS_IN_HOUR;

    minute = second / SECS_IN_MINUTE;
    second %= SECS_IN_MINUTE;

    // Кількість днів з 1.01.01
    time /= SECS_IN_DAY;

    // Максимальний рік для такої кількості днів
    year = static_cast<int>(time / 365);
    year -= getLeapDays(year) / 365;

    int leap = getLeapDays(year);

    // День року для цього року
    long long days = time - year * 365 - leap;

    // День повинен бути у форматі [0; 365]
    while (days < 0)
    {
        year--;
        leap = getLeapDays(year);
        days = time - year * 365 - leap;
    }

    while (days > 365)
    {
        year++;
        leap = getLeapDays(year);
        days = time - year * 365 - leap;
    }

    // Ділимо дні на місяці
    if (isLeap(year))
    {
        setYearsDay(MONTH_STARTS_LEAP, MONTH_LENGTHS_LEAP, static_cast<int>(days));
    }
    else
    {
        setYearsDay(MONTH_STARTS, MONTH_LENGTHS, static_cast<int>(days));
    }
}

void STime::setYearsDay(const int *monthTable, const int *lengths, int yearDay)
{
    for (int i = 1; i < 13; i++)
    {
        if (yearDay <= monthTable[i])
        {
            month = i-1;
            day = yearDay - monthTable[i-1] + 1;
            break;
        }
    }

    // Корекція введення дати
    if (day > lengths[month])
    {
        day = 1;
        month++;
        if (month > 11)
        {
            year++;
            month = 0;
        }
    }
}

long long STime::get()
{
    if (!valid)
    {
        return LLONG_MIN;
    }

    year += month / MONTH_COUNT;
    month %= MONTH_COUNT;

    int monthDays;
    if (isLeap(year))
    {
        monthDays = MONTH_STARTS_LEAP[month];
    }
    else
    {
        monthDays = MONTH_STARTS[month];
    }

    // Кількість днів з 01.01.01
    long long result = year * 365           // у не високосних роках
                       + getLeapDays(year)  // днів у високосних
                       + monthDays          // день початку місяця
                       + day                // днів у місяці
                       - 1;                 // місяць починається з 1, а не 0

    result *= SECS_IN_DAY;
    result += hour * SECS_IN_HOUR;
    result += minute * SECS_IN_MINUTE;
    result += second;
    result *= TIME_MULTIPLIER;
    result += millisecond;

    return result;
}

string STime::formatDate() const
{
    ostringstream date;
    date << setfill('0') << year
        << '-' << setw(2) << (month + 1)
        << '-' << setw(2) << day;
    return date.str();
}

string STime::formatDateTime() const
{
    ostringstream date;
    date << setfill('0') << year
        << '-' << setw(2) << (month + 1)
        << '-' << setw(2) << day
        << ' ' << setw(2) << hour
        << ':' << setw(2) << minute
        << ':' << setw(2) << second;

    if (millisecond) date << '.' << setw(3) << millisecond;

    return date.str();
}

int STime::dayOfYear() const
{
    if (isLeap(year))
    {
        return MONTH_STARTS_LEAP[month] + day;
    }
    else
    {
        return MONTH_STARTS[month] + day;
    }
}

int STime::monthsAfter(const STime &from) const
{
    int result = (year - from.year) * MONTH_COUNT;
    result -= from.month - month;

    if (day < from.day)
    {
        return result - 1;
    }

    if (day == from.day)
    {
        int time = (hour * SECS_IN_HOUR + minute * SECS_IN_MINUTE + second) * TIME_MULTIPLIER + millisecond;
        int ftime = (from.hour * SECS_IN_HOUR + from.minute * SECS_IN_MINUTE + from.second) * TIME_MULTIPLIER + from.millisecond;
        if (ftime > time)
        {
            return result - 1;
        }
    }

    return result;
}

void STime::asTime(tm *time) const
{
    time->tm_year = year - TM_START_YEAR;
    time->tm_mon = month;
    time->tm_mday = day;
    time->tm_hour = hour;
    time->tm_min = minute;
    time->tm_sec = second;
}

void STime::increaseDay(int days)
{
    day += days;
}

void STime::increaseMonth(int months)
{
    month += months;
}

void STime::increaseYear(int years)
{
    year += years;
}

void STime::decreaseDay(int days)
{
    day -= days;
}

void STime::decreaseMonth(int months)
{
    month -= months;
}

void STime::decreaseYear(int years)
{
    year -= years;
}

int STime::getYear() const
{
    return this->year;
}

int STime::getMonth() const
{
    return this->month;
}

int STime::getDay() const
{
    return this->day;
}

int STime::getHour() const
{
    return this->hour;
}

int STime::getMinute() const
{
    return this->minute;
}

int STime::getSecond() const
{
    return this->second;
}

int STime::getMillisecond() const
{
    return this->millisecond;
}