#include <iostream>
#include <cctype>

using namespace std;

bool LastWord(char str[]);

int main() {
    const int n = 100;
    char str[n];
    cout << "Enter string: ";
    cin >> str;
    if (LastWord(str))
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }
    return 0;
}

bool LastWord(char str[])
{
    int size = strlen(str), j = 0;
    char buff[size];
    //знаходимо перше слово
    for (int i = 0; isalpha(str[i]); i++)
    {
        buff[j] = str[i];
        j++;
    }
    // перевіряємо, чи вони співпадають
    for (int i = size - 1; (str[i] != '\n') && (str[i] != ' '); i--, j--)
    {
        // кінцем стрічки може бути не тільки літера, тому контроюємо цей момент
        if (!isalpha(str[i]))
        {
            i--;
            continue;
        }
        if (buff[j] != str[i])
        {
            return false;
        }
    }
    return true;
}