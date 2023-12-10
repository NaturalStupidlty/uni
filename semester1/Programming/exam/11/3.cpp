#include <iostream>
#include <cstring>

using namespace std;

void ToBinary(char *answer, char *decimal);

int main() {
    char string[10];
    ToBinary(string, "3246");
    cout << "Answer: "<< string;
    return 0;
}

void ToBinary(char *answer, char *decimal)
{
    long number = 0, powCounter = 1; // замінемо піднесення до степеня моженням для ефективності
    int digits = strlen(decimal), binDigits = 0;
    for (int i = digits - 1; i >= 0; i--)
    {
        number += ((int) decimal[i] - 48) * powCounter;
        powCounter *= 10;
    }
    for (long i = 1; i <= number; i *= 2)
    {
        binDigits++;
    }
    answer[binDigits] = '\0';
    int k = binDigits - 1;
    while(number >= 2)
    {
        answer[k] = (number % 2) + '0';
        number /= 2;
        k--;
    }
    answer[k] = number + '0';
}