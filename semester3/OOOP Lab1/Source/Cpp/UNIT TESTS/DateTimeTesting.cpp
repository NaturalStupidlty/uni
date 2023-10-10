#include "../../Headers/doctest.h"
#include "../../Headers/DateTime.h"

TEST_CASE("isValid DateTime testing")
{
    DateTime time1;
    CHECK(time1.isValid() == false);
    DateTime time2("2022-13-07 00:20:21");
    REQUIRE(time2.isValid() == true);
    CHECK(time2.formatDateTime() == "2023-01-07 00:20:21");
}

TEST_CASE("daysBetween DateTime testing")
{
    DateTime time1("2022-09-09 23:19:55");
    DateTime time2("2022-08-09 02:14:44");
    CHECK(DateTime::daysBetween(time1, time2) == 31);
}

TEST_CASE("hoursBetween DateTime testing")
{
    DateTime time1("2022-09-09 23:19:55");
    DateTime time2("2022-08-09 02:14:44");
    CHECK(DateTime::hoursBetween(time2, time1) == 765);
}

TEST_CASE("increaseBy DateTime testing")
{
    DateTime time1("2022-08-09 02:14:44");
    DateTime time2 = time1.increaseBy(69, 420, 666, 1, 2 ,3);
    CHECK(time2.formatDateTime() == "2025-11-07 03:15:53");
}

TEST_CASE("operator + DateTime testing")
{
    DateTime time1("2022-08-09 02:14:44");
    DateTime time2("3-03-29 01:01:09");
    CHECK((time2 + time1).formatDateTime() == "2025-11-07 03:15:53");
}

TEST_CASE("operator - DateTime testing")
{
    DateTime time1("2022-08-09 02:14:44");
    DateTime time2("2003-08-29 00:00:00");
    CHECK((time1 - time2).formatDateTime() == "19-02-11 02:14:44");
}

TEST_CASE("getDayOfYear DateTime testing")
{
    DateTime time("2022-10-10 00-36-55");
    CHECK(time.getDayOfYear() == 283);
}

TEST_CASE("getWeekOfYear DateTime testing")
{
    DateTime time("2022-10-10 00-36-55");
    CHECK(time.getWeekOfYear() == 42);
}

TEST_CASE("toUTC DateTime testing")
{
    DateTime time1("2022-10-10 00-36-55");
    DateTime time1Copy = time1;
    DateTime time2 = time1Copy.decreaseByHours(3);
    time1.toUTC();
    CHECK(time1 == time2);
}

TEST_CASE("fromUTC DateTime testing")
{
    DateTime time1("2022-10-10 00-36-55");
    DateTime time1Copy = time1;
    DateTime time2 = time1Copy.increaseByHours(3);
    time1.fromUTC();
    CHECK(time1 == time2);
}