#include <iostream>
using namespace std;

int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
struct date{
    int day;
    int month;
    int year;
};

long daysAnnoDomini(date d);
date daysToDate(long d);
date subtractDates(date a, date b);

int main() {
    date one{1, 1, 1970};
    date two{19, 12, 2020};
    date three = subtractDates(one, two);
    cout << abs(daysAnnoDomini(one) - daysAnnoDomini(two)) << endl;
    cout << three.year << " years, " << three.month << " months, " << three.day << " days." << endl;
    return 0;
}

long daysAnnoDomini(date d){
    long res = 0;
    res += d.year*365;
    // res += d.year/4;
    int month = d.month-1;
    for (int i = 0; i < month; ++i) {
        res += days[i];
    }
    res += d.day;
    return res;
}

date daysToDate(long d){
    date res;
    res.year = d/365;
    res.month = (d%365)/31;
    res.day = d-res.year*365-res.month*31;
    return res;
}

date subtractDates(date a, date b){
    return daysToDate(abs(daysAnnoDomini(a) - daysAnnoDomini(b)));
}