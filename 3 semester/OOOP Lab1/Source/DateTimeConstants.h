#ifndef OOOP_LAB1_DATETIMECONSTANTS_H
#define OOOP_LAB1_DATETIMECONSTANTS_H

// Початковий рік
const int TM_START_YEAR = 1900;

// Кількість мілісекунд
const int TIME_MULTIPLIER = 1000;

const int MONTH_COUNT = 12;
const int SECS_IN_MINUTE = 60;
const int SECS_IN_HOUR = SECS_IN_MINUTE * 60;
const int SECS_IN_DAY = SECS_IN_HOUR * 24;
const long long MILLISECONDS_IN_DAY = SECS_IN_DAY * TIME_MULTIPLIER;
const long long IDENTITY_THRESHOLD = SECS_IN_MINUTE * TIME_MULTIPLIER;

// Зміщення тактів time_t для DateTime::miliseconds
const long long TIME_T_ZERO = 62167132800000;

// Довжини місяців у днях
const int MONTH_LENGTHS[]      =     {31, 28, 31, 30,   31,  30,  31,  31,  30,  31,  30,  31};
const int MONTH_LENGTHS_LEAP[] =     {31, 29, 31, 30,   31,  30,  31,  31,  30,  31,  30,  31};

// Початки місяців
const int MONTH_STARTS[]       = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};

// Початки місяців з урахуванням високосного року
const int MONTH_STARTS_LEAP[]  = {-1, 30, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};

#endif //OOOP_LAB1_DATETIMECONSTANTS_H
