#include <iostream>

struct Date
{
private:
    unsigned short day, month, year;
public:
    void SetDay(unsigned short d) {day = d;}
    void SetMonth(unsigned short m) {month = m;}
    void SetYear(unsigned short y) {year = y;}

    unsigned short GetDay() const {return day;}
    unsigned short GetMonth() const {return month;}
    unsigned short GetYear() const {return year;}
};

int MinimalSpringDate(Date dates[], int size);

using namespace std;

int main() {
    const int size = 5;
    int d, m, y;
    Date dates[size];
    cout << "Enter dates (day *Enter*, month *Enter*, year *Enter*): ";
    for (int i = 0; i < size; i++)
    {
        cin >> d >> m >> y;
        if (d > 0 && m > 0 && d <= 31 && m <= 12 )
        {
            dates[i].SetDay(d);
            dates[i].SetMonth(m);
            dates[i].SetYear(y);
        }
    }
    int ans = MinimalSpringDate(dates, size);
    cout << dates[ans].GetDay() << ' ';
    cout << dates[ans].GetMonth() << ' ';
    cout << dates[ans].GetYear() << ' ';
    return 0;
}

int MinimalSpringDate(Date dates[], int size)
{
    int minDay, minMonth, minYear, m, d, y, i, answer;
    bool springDate = false;
    // перевіряємо, чи взагалі є весняні дати, якщо так, то мінімальною стає перша з них
    for (i = 0; i < size; i++)
    {
        m = dates[i].GetMonth();
        d = dates[i].GetDay();
        y = dates[i].GetYear();
        if(m == 3 || m == 4 || m == 5)
        {
            minDay = d;
            minMonth = m;
            minYear = y;
            answer = i;
            springDate = true;
            break;
        }
    }
    if (springDate)
    {
        for (; i < size; i++)
        {
            m = dates[i].GetMonth();
            d = dates[i].GetDay();
            y = dates[i].GetYear();
            if(m == 3 || m == 4 || m == 5)
            {
                if (y < minYear)
                {
                    minDay = d;
                    minMonth = m;
                    minYear = y;
                    answer = i;
                }
                else if (y == minYear)
                {
                    if (m < minMonth)
                    {
                        minDay = d;
                        minMonth = m;
                        minYear = y;
                        answer = i;
                    }
                    else if (m == minMonth)
                    {
                        if (d < minDay)
                        {
                            minDay = d;
                            minMonth = m;
                            minYear = y;
                            answer = i;
                        }
                    }
                }
            }
        }
        return answer;
    }
    else
    {
        return 0;
    }
}