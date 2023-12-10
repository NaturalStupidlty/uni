#include <iostream>
#include <cctype>

using namespace std;

void CapitalLetters(char str[]);

int main() {
    const int n = 50;
    char str[n];
    cout << "Enter a string: ";
    cin >> str;
    CapitalLetters(str);
    cout << str;
    return 0;
}

void CapitalLetters(char str[])
{
    int length = strlen(str);
    if (isalpha(str[0]))
    {
        str[0] = toupper(str[0]);
    }
    for (int i = 1; i < length - 1; i++)
    {
        if ((str[i] == ' ' && isalpha(str[i+1]) && islower(str[i+1])))
        {
            str[i+1] = toupper(str[i+1]);
        }
    }
}