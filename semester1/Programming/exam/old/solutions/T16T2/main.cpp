#include <iostream>

using namespace std;

unsigned int Brackets(char str[]);

int main()
{
    const int n = 100;
    char str[n];
    cout << "Enter string: ";
    cin >> str;
    if (Brackets(str))
    {
        cout << "Incorrect. First error:" << Brackets(str);
    }
    else
    {
        cout << "Correct!";
    }
    return 0;
}

unsigned int Brackets(char str[])
{
    int strSize = strlen(str), counter = 0, error = 0;
    // error - порядковий номер символа "(", якому не відповідає ")"
    char lastSymbol = '0';
    for (int i = 0; i < strSize; i++)
    {
        if (str[i] == '(')
        {
            counter++; lastSymbol = '(';
        }
        else if (str[i] == ')')
        {
            if (counter) {
                counter--;
                if (lastSymbol != '(')
                {
                    return error;
                }
            }
            else
            {
                return error;
            }
            lastSymbol = ')';
            error = i;
        }
    }
    // функція повертає індекс помилки або 0, якщо їх немає
    return counter;
}