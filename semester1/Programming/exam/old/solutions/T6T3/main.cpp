#include <iostream>

using namespace std;

struct Date {
private:
    int year;
    int month;
    int day;
public:
    void SetYear(int y) {year = y;}
    void SetMonth(int m) {month = m;}
    void SetDay(int d) {day = d;}

    int GetYear() const {return year;}
    int GetMonth() const {return month;}
    int GetDay() const {return day;}
};

int DaysBetween(Date first, Date second);
int GetDays(int day, int month, int year);

// Нехай формат введення дати такий: 31 (Enter) 01 (Enter) 2021 (Enter)

int main() {
    Date first, second;
    unsigned short day1, day2, month1, month2, year1, year2;
    cout << "Enter first date: ";
    cin >> day1 >> month1 >> year1;
    first.SetDay(day1);
    first.SetMonth(month1);
    first.SetYear(year1);
    cout << "Enter second date: ";
    cin >> day2 >> month2 >> year2;
    second.SetDay(day2);
    second.SetMonth(month2);
    second.SetYear(year2);
    cout << DaysBetween(first, second);
    return 0;
}
int DaysBetween(Date first, Date second)
{
    // можливо, менш ефективно, але більш зручно для точного розрахунку
    // спочатку порахувати кількість днів у кожній даті, а потім відняти їх
    int days;
    days = abs(GetDays(first.GetDay(), first.GetMonth(), first.GetYear()) - GetDays(second.GetDay(), second.GetMonth(), second.GetYear()));
    return days;
}

int GetDays(int day, int month, int year)
{
    //для зручності будемо рахувати з березня, а не з лютого
    if (month < 3)
    {
        year--;
        month += 12;
    }
    return year * (97/400 + 365) + (153 * month - 457)/5 + day - 306;
    // 97/400 = 1/4 - 1/100 + 1/400
}