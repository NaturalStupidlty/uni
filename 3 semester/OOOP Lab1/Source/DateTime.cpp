#include "DateTime.h"
#include "DateTimeConstants.h"
#include "STime.h"
#include <climits>

using namespace std;

// Різниця між локальним часом та UTC у мілісекундах
long long getTimezone()
{
    static long long tz(0);

    // Ідея полягає у тому, що ми спочатку конвертуємо поточний час
    // time_t в UTC у структуру tm, а потім назад у локальний
    time_t t = time(nullptr);
    tm* utc = gmtime(&t);

    // Не відомо, наскільки годин переводять час
    utc->tm_isdst = -1;
    time_t tu = mktime(utc);
    tz = (tu - t) * TIME_MULTIPLIER;
    return tz;
}

DateTime::DateTime ()
{
    miliseconds = 0;
    setNow();
}

DateTime::DateTime (const DateTime &value)
{
    miliseconds = value.miliseconds;
}

DateTime::DateTime (const string &value)
{
    miliseconds = 0;
    set(value);
}

DateTime::DateTime (const time_t &time)
{
    miliseconds = 0;
    set(time);
}

DateTime::DateTime (const tm *time)
{
    miliseconds = 0;
    set(time);
}

void DateTime::setNow()
{
    set(time(nullptr));
}

bool DateTime::isValid() const
{
    return miliseconds != LLONG_MIN;
}

long long DateTime::getMiliseconds() const
{
    return miliseconds;
}

void DateTime::toUTC()
{
    if (miliseconds != LLONG_MIN)
    {
        miliseconds += getTimezone();
    }
}

void DateTime::fromUTC()
{
    if (miliseconds != LLONG_MIN)
    {
        miliseconds -= getTimezone();
    }
}

std::string DateTime::formatDate() const
{
    if (miliseconds == LLONG_MIN)
    {
        return {};
    }
    STime time(miliseconds);
    return time.formatDate();
}

std::string DateTime::formatDateTime() const
{
    if (miliseconds == LLONG_MIN)
    {
        return {};
    }
    STime time(miliseconds);
    return time.formatDateTime();
}

bool DateTime::asTime(tm *time) const
{
    if (miliseconds == LLONG_MIN || !time)
    {
        return false;
    }

    STime t(miliseconds);
    t.asTime(time);

    return true;
}

void DateTime::set (const std::string &value)
{
    STime time(value);
    miliseconds = time.get();
}

void DateTime::set (const time_t &time)
{
    if (time > 0)
    {
        miliseconds = (long long) time * TIME_MULTIPLIER + TIME_T_ZERO;
    }
    else
    {
        miliseconds = LLONG_MIN;
    }
}

void DateTime::set (const tm *time)
{
    STime t(time);
    miliseconds = t.get();
}

DateTime& DateTime::incSecond(int seconds)
{
    if (miliseconds != LLONG_MIN)

    {
        miliseconds += (long long) seconds * TIME_MULTIPLIER;
    }
    return *this;
}

DateTime& DateTime::incMinute(int minutes)
{
    if (miliseconds != LLONG_MIN)
    {
        miliseconds += (long long) minutes * SECS_IN_MINUTE * TIME_MULTIPLIER;
    }
    return *this;
}

DateTime& DateTime::incHour(int hours)
{
    if (miliseconds != LLONG_MIN)
    {
        miliseconds += (long long) hours * SECS_IN_HOUR * TIME_MULTIPLIER;
    }
    return *this;
}

DateTime& DateTime::incDay(int days)
{
    if (miliseconds != LLONG_MIN)
    {
        miliseconds += (long long) days * MILLISECONDS_IN_DAY;
    }
    return *this;
}

DateTime& DateTime::incMonth(int months)
{
    if (miliseconds != LLONG_MIN)
    {
        STime time(miliseconds);
        time.incMonth(months);
        miliseconds = time.get();
    }
    return *this;
}

DateTime& DateTime::incYear(int years)
{
    if (miliseconds != LLONG_MIN)
    {
        STime time(miliseconds);
        time.incYear(years);
        miliseconds = time.get();
    }
    return *this;
}

int DateTime::getWeekDay() const
{
    if (miliseconds != LLONG_MIN)
    {
        return (int)(miliseconds / MILLISECONDS_IN_DAY + 6) % 7;
    }
    else
    {
        return -1;
    }
}

int DateTime::getDayOfYear() const
{
    if (miliseconds == LLONG_MIN)
    {
        return -1;
    }
    STime time(miliseconds);
    return time.dayOfYear();
}

int DateTime::daysBetween(const DateTime &date1, const DateTime &date2)
{
    if (date1.miliseconds == LLONG_MIN || date2.miliseconds == LLONG_MIN)
    {
        return -1;
    }
    long long diff = date1.miliseconds - date2.miliseconds;
    if (diff < 0)
    {
        diff = -diff;
    }
    return static_cast<int>(diff/MILLISECONDS_IN_DAY);
}

int DateTime::monthsBetween(const DateTime &date1, const DateTime &date2)
{
    if (date1.miliseconds == LLONG_MIN || date2.miliseconds == LLONG_MIN)
    {
        return -1;
    }
    if (date1 == date2)
    {
        return 0;
    }

    STime d1(date1.miliseconds);
    STime d2(date2.miliseconds);

    if (date1 < date2)
    {
        return d2.monthsAfter(d1);
    }
    else
    {
        return d1.monthsAfter(d2);
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

DateTime& DateTime::operator = (const DateTime &date) = default;

bool DateTime::hasTime() const
{
    return miliseconds != LLONG_MIN && (miliseconds % MILLISECONDS_IN_DAY) != 0;
}

bool DateTime::identic(const DateTime &other) const
{
    if (miliseconds == LLONG_MIN || other.miliseconds == LLONG_MIN)
    {
        return false;
    }
    if (miliseconds == other.miliseconds)
    {
        return true;
    }

    if (miliseconds > other.miliseconds)
    {
        return (miliseconds - other.miliseconds) <= IDENTITY_THRESHOLD;
    }

    return (other.miliseconds - miliseconds) <= IDENTITY_THRESHOLD;
}

