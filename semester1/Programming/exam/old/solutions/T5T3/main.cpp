#include <iostream>
#include <cctype>

using namespace std;

int WordsCounter (char str[]);

int main()
{
    const int n = 100;
    char str[n];
    cout << "Enter string: ";
    cin >> str;
    cout << WordsCounter(str);
    return 0;
}

int WordsCounter(char str[])
{
    unsigned long size = strlen(str) - 1; // -1, бо у циклі будемо розглядати елемент i+1
    int counter = 0;
    if(isalpha(str[0]))
    {
        counter++;
    }
    for (int i = 1; i < size; i++)
    {
        if (isspace(str[i]) && (isalpha(str[i+1])))
        {
            counter++;
        }
    }
    return counter;
}