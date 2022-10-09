#include "../Headers/DateTime.h"
#include "../Headers/DateTimeConstants.h"
#include "../Headers/STime.h"
#include <climits>

#include "../Headers/doctest.h"

using std::string;

/** ------[ Конструктори ]------ */

DateTime::DateTime ()
{
    milliseconds = 0;
    setNow();
}

DateTime::DateTime (const DateTime &value)
{
    milliseconds = value.milliseconds;
}

DateTime::DateTime (const string &value)
{
    milliseconds = 0;
    set(value);
}

DateTime::DateTime (const time_t &time)
{
    milliseconds = 0;
    set(time);
}

DateTime::DateTime (const tm *time)
{
    milliseconds = 0;
    set(time);
}

/** ------[ Підтримка часових зон ]------ */

// Різниця між локальним часом та UTC у мілісекундах
long long getTimezone()
{
    static long long milliseconds(0);

    // Ідея полягає у тому, що ми спочатку конвертуємо поточний час
    // time_t в UTC у структуру tm, а потім назад у локальний
    time_t currentTime = time(nullptr);
    tm* utcTime = gmtime(&currentTime);

    // Не відомо, наскільки годин переводять час
    utcTime->tm_isdst = -1;
    time_t localTime = mktime(utcTime);
    milliseconds = (localTime - currentTime) * TIME_MULTIPLIER;
    return milliseconds;
}

void DateTime::toUTC()
{
    if (milliseconds != LLONG_MIN)
    {
        milliseconds += getTimezone();
    }
}

void DateTime::fromUTC()
{
    if (milliseconds != LLONG_MIN)
    {
        milliseconds -= getTimezone();
    }
}

/** ------[ Присвоєння часу ]------ */

void DateTime::setNow()
{
    set(time(nullptr));
}

void DateTime::set (const string &value)
{
    STime time(value);
    milliseconds = time.get();
}

void DateTime::set (const time_t &time)
{
    if (time > 0)
    {
        milliseconds = (long long) time * TIME_MULTIPLIER + TIME_T_ZERO;
    }
    else
    {
        milliseconds = LLONG_MIN;
    }
}

void DateTime::set (const tm *time)
{
    STime utilTime(time);
    milliseconds = utilTime.get();
}

/** ------[ Отримати час ]------ */

bool DateTime::isValid() const
{
    return milliseconds != LLONG_MIN;
}

long long DateTime::getMiliseconds() const
{
    return milliseconds;
}

time_t DateTime::asUnixTime() const
{
    if (milliseconds == LLONG_MIN)
    {
        return -1;
    }
    time_t result = (milliseconds - TIME_T_ZERO) / TIME_MULTIPLIER;
    if (result < 0)
    {
        return -1;
    }
    return result;
}

std::string DateTime::formatDate() const
{
    if (milliseconds == LLONG_MIN)
    {
        return {};
    }
    STime time(milliseconds);
    return time.formatDate();
}

std::string DateTime::formatDateTime() const
{
    if (milliseconds == LLONG_MIN)
    {
        return {};
    }
    STime time(milliseconds);
    return time.formatDateTime();
}

int DateTime::getWeekDay() const
{
    if (milliseconds != LLONG_MIN)
    {
        return (int)(milliseconds / MILLISECONDS_IN_DAY + 6) % 7;
    }
    else
    {
        return -1;
    }
}

int DateTime::getDayOfYear() const
{
    if (milliseconds == LLONG_MIN)
    {
        return -1;
    }
    STime time(milliseconds);
    return time.dayOfYear();
}

int DateTime::getWeekOfYear() const
{
    if (milliseconds == LLONG_MIN)
    {
        return -1;
    }
    STime time(milliseconds);

    int days = time.dayOfYear();
    int dayOfWeek = this->getWeekDay();

    time.decreaseMonth(time.getMonth());
    time.decreaseDay(time.getDay());
    int dayOfWeekJan1 = (time.get() / MILLISECONDS_IN_DAY + 6) % 7;

    int weekNum = ((days + 6) / 7);
    if (dayOfWeek < dayOfWeekJan1)
    {
        ++weekNum;
    }
    return (weekNum);
}

/** ------[ Арифметика часу ]------ **/

DateTime &DateTime::increaseBy(int seconds, int minutes, int hours, int days, int months, int years)
{
    this->increaseBySeconds(seconds);
    this->increaseByMinutes(minutes);
    this->increaseByHours(hours);
    this->increaseByDays(days);
    this->increaseByMonths(months);
    this->increaseByYears(years);
    return *this;
}

DateTime& DateTime::increaseBySeconds(int seconds)
{
    if (milliseconds != LLONG_MIN)

    {
        milliseconds += (long long) seconds * TIME_MULTIPLIER;
    }
    return *this;
}

DateTime& DateTime::increaseByMinutes(int minutes)
{
    if (milliseconds != LLONG_MIN)
    {
        milliseconds += (long long) minutes * SECS_IN_MINUTE * TIME_MULTIPLIER;
    }
    return *this;
}

DateTime& DateTime::increaseByHours(int hours)
{
    if (milliseconds != LLONG_MIN)
    {
        milliseconds += (long long) hours * SECS_IN_HOUR * TIME_MULTIPLIER;
    }
    return *this;
}

DateTime& DateTime::increaseByDays(int days)
{
    if (milliseconds != LLONG_MIN)
    {
        milliseconds += (long long) days * MILLISECONDS_IN_DAY;
    }
    return *this;
}

DateTime& DateTime::increaseByMonths(int months)
{
    if (milliseconds != LLONG_MIN)
    {
        STime time(milliseconds);
        time.increaseMonth(months);
        milliseconds = time.get();
    }
    return *this;
}

DateTime& DateTime::increaseByYears(int years)
{
    if (milliseconds != LLONG_MIN)
    {
        STime time(milliseconds);
        time.increaseYear(years);
        milliseconds = time.get();
    }
    return *this;
}

DateTime &DateTime::decreaseBy(int seconds, int minutes, int hours, int days, int months, int years)
{
    this->decreaseBySeconds(seconds);
    this->decreaseByMinutes(minutes);
    this->decreaseByHours(hours);
    this->decreaseByDays(days);
    this->decreaseByMonths(months);
    this->decreaseByYears(years);
    return *this;
}

DateTime& DateTime::decreaseBySeconds(int seconds)
{
    if (milliseconds != LLONG_MIN)

    {
        milliseconds -= (long long) seconds * TIME_MULTIPLIER;
    }
    return *this;
}

DateTime& DateTime::decreaseByMinutes(int minutes)
{
    if (milliseconds != LLONG_MIN)
    {
        milliseconds -= (long long) minutes * SECS_IN_MINUTE * TIME_MULTIPLIER;
    }
    return *this;
}

DateTime& DateTime::decreaseByHours(int hours)
{
    if (milliseconds != LLONG_MIN)
    {
        milliseconds -= (long long) hours * SECS_IN_HOUR * TIME_MULTIPLIER;
    }
    return *this;
}

DateTime& DateTime::decreaseByDays(int days)
{
    if (milliseconds != LLONG_MIN)
    {
        milliseconds -= (long long) days * MILLISECONDS_IN_DAY;
    }
    return *this;
}

DateTime& DateTime::decreaseByMonths(int months)
{
    if (milliseconds != LLONG_MIN)
    {
        STime time(milliseconds);
        time.increaseMonth(months);
        milliseconds = time.get();
    }
    return *this;
}

DateTime& DateTime::decreaseByYears(int years)
{
    if (milliseconds != LLONG_MIN)
    {
        STime time(milliseconds);
        time.increaseYear(years);
        milliseconds = time.get();
    }
    return *this;
}

long long int DateTime::millisecondsBetween(const DateTime &date1, const DateTime &date2)
{
    if (date1.milliseconds == LLONG_MIN || date2.milliseconds == LLONG_MIN)
    {
        return -1;
    }
    long long diff = date1.milliseconds - date2.milliseconds;
    if (diff < 0)
    {
        diff = -diff;
    }
    return diff;
}

int DateTime::secondsBetween(const DateTime &date1, const DateTime &date2)
{
    if (date1.milliseconds == LLONG_MIN || date2.milliseconds == LLONG_MIN)
    {
        return -1;
    }
    long long diff = date1.milliseconds - date2.milliseconds;
    if (diff < 0)
    {
        diff = -diff;
    }
    return static_cast<int>(diff/TIME_MULTIPLIER);
}

int DateTime::minutesBetween(const DateTime &date1, const DateTime &date2)
{
    if (date1.milliseconds == LLONG_MIN || date2.milliseconds == LLONG_MIN)
    {
        return -1;
    }
    long long diff = date1.milliseconds - date2.milliseconds;
    if (diff < 0)
    {
        diff = -diff;
    }
    return static_cast<int>(diff/(SECS_IN_MINUTE * TIME_MULTIPLIER));
}

int DateTime::hoursBetween(const DateTime &date1, const DateTime &date2)
{
    if (date1.milliseconds == LLONG_MIN || date2.milliseconds == LLONG_MIN)
    {
        return -1;
    }
    long long diff = date1.milliseconds - date2.milliseconds;
    if (diff < 0)
    {
        diff = -diff;
    }
    return static_cast<int>(diff/(SECS_IN_HOUR * TIME_MULTIPLIER));
}

int DateTime::daysBetween(const DateTime &date1, const DateTime &date2)
{
    if (date1.milliseconds == LLONG_MIN || date2.milliseconds == LLONG_MIN)
    {
        return -1;
    }
    long long diff = date1.milliseconds - date2.milliseconds;
    if (diff < 0)
    {
        diff = -diff;
    }
    return static_cast<int>(diff/MILLISECONDS_IN_DAY);
}

int DateTime::monthsBetween(const DateTime &date1, const DateTime &date2)
{
    if (date1.milliseconds == LLONG_MIN || date2.milliseconds == LLONG_MIN)
    {
        return -1;
    }
    if (date1 == date2)
    {
        return 0;
    }

    STime utilDate1(date1.milliseconds);
    STime utilDate2(date2.milliseconds);

    if (date1 < date2)
    {
        return utilDate2.monthsAfter(utilDate1);
    }
    else
    {
        return utilDate1.monthsAfter(utilDate2);
    }
}

int DateTime::yearsBetween(const DateTime &date1, const DateTime &date2)
{
    int months = monthsBetween(date1, date2);
    if (months <= 0)
    {
        return months;
    }
    else
    {
        return months / MONTH_COUNT;
    }
}

/** ------[ Перевантаження операторів ]------ **/

DateTime &DateTime::operator - (const DateTime &date)
{
    STime time(date.milliseconds);
    this->decreaseBy(time.getSecond(), time.getMinute(), time.getHour(), time.getDay(), time.getMonth(), time.getYear());
    return *this;
}

DateTime &DateTime::operator + (const DateTime &date)
{
    STime time(date.milliseconds);
    this->increaseBy(time.getSecond(), time.getMinute(), time.getHour(), time.getDay(), time.getMonth(), time.getYear());
    return *this;
}

DateTime &DateTime::operator = (int numberOfMilliseconds)
{
    this->milliseconds = (long long int)numberOfMilliseconds;
    return *this;
}

inline bool operator == (const DateTime &date1, const DateTime &date2)
{
    return date1.milliseconds == date2.milliseconds;
}

inline bool operator < (const DateTime &date1, const DateTime &date2)
{
    return date1.milliseconds < date2.milliseconds;
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
