#include <iostream>
#include <cstring>

using namespace std;

void Cipher(char str[]);

int main() {
    const int n = 100;
    char str[n];
    cout << "Enter your message: ";
    cin >> str;
    Cipher(str);
    cout << "Ciphered message: " << str;
    return 0;
}

void Cipher(char str[])
{
    int s = strlen(str);
    char buff[s];
    for (int i = 1, j = 0; j < s; j++)
    {
        buff[j] = str[i];
        if (j == (s - 2) / 2)
        {
            i++;
        }
        else if (j < (s - 1)/2)
        {
            i += 2;
        }
        else
        {
            i -= 2;
        }
    }
    for (int i = 0; i < s; i++)
    {
        str[i]=buff[i];
    }
}