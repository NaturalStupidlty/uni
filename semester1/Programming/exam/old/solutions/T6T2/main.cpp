#include <iostream>

using namespace std;

char* FindPeriod(int n);

int main()
{
    int n;
    cout << "Enter N:";
    cin >> n;
    char* answer = FindPeriod(n);
    cout << "Period:  " << answer;
    return 0;
}
char* FindPeriod(int n)
{
    int* rest = new int[n+1];
    int* period = new int[n+1];
    char* str = new char[n];
    int numerator = 1, r, position, length = 1;
    do
    {
        r = numerator % n;
        rest[length] = r;
        numerator /= n;
        period[length] = numerator;
        numerator = 10 * r;
        length++;
        for(int i = 0; i < length - 1; i++)
        {
            if(rest[i] == r)
            {
                position = i;
            }
        }
    }
    while(!position);
    str[0] = '.', str[1] = '*';
    for (int i = 2; i < length; i++)
    {
        str[i] = period[i] + '0';
    }
    str[length] = '*';
    delete[] rest;
    delete[] period;
    return str;
}
