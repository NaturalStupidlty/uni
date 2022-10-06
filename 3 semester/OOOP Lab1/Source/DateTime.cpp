#include "DateTime.h"

using std::cout;
using std::endl;

void DateTime::show()
{
    char* dt = asctime(this->dateTimeStructure);
    cout << dt << endl;
}

DateTime::DateTime()
{
    this->timeStamp = time(nullptr);
    this->dateTimeStructure = localtime(&timeStamp);
}

DateTime::DateTime(time_t time)
{
    this->timeStamp = time;
    this->dateTimeStructure = localtime(&timeStamp);
}

DateTime::DateTime(tm* timeStructure)
{
    this->dateTimeStructure = timeStructure;
    this->timeStamp = mktime(dateTimeStructure);
}

DateTime::DateTime(int tm_sec,
                   int tm_min,
                   int tm_hour,
                   int tm_mday,
                   int tm_mon,
                   int tm_year,
                   int tm_wday,
                   int tm_yday,
                   int tm_isdst)
{
    time_t now = time(nullptr);
    tm *newDateTime = localtime(&now);
    // seconds of minutes from 0 to 61
    newDateTime->tm_sec = tm_sec;
    // minutes of hour from 0 to 59
    newDateTime->tm_min = tm_min;
    // hours of day from 0 to 24
    newDateTime->tm_hour = tm_hour;
    // day of month from 1 to 31
    newDateTime->tm_mday = tm_mday;
    // month of year from 0 to 11
    newDateTime->tm_mon = tm_mon;
    // year since 1900
    newDateTime->tm_year = tm_year;
    // days since sunday
    if (tm_wday)
    {
        newDateTime->tm_wday = tm_wday;
    }
    // days since January 1st
    if (tm_yday)
    {
        newDateTime->tm_yday = tm_yday;
    }
    // hours of daylight savings time
    if (tm_isdst)
    {
        newDateTime->tm_isdst = tm_isdst;
    }
    this->dateTimeStructure = newDateTime;
}
