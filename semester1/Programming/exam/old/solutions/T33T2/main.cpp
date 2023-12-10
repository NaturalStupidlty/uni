#include <iostream>
#include <cctype>

using namespace std;

double MyATOF(char str[]);

int main()
{
    const int n = 25;
    char str[n];
    cout << "Enter a string: ";
    cin >> str;
    cout << MyATOF(str);
    return 0;
}

double MyATOF(char str[])
{
    double number = 0, power = 1;
    unsigned short length = strlen(str);
    // здайдемо дробову частину, починаючи з кінця, поки не побачимо точку
    // поділимо її на десять у степені кількості цифр дробової частини
    // і таким же чином знайдемо цілу частину
    for (int i = length - 1; i >= 0 ; i--)
    {
        if (isdigit(str[i]))
        {
            double digit = (double)(str[i] - '0');
            number += digit * power;
            power *= 10;
        }
        else if (str[i] == '.' or str[i] == ',')
        {
            number /= power;
            power = 1;
        }
    }
    return number;
}
