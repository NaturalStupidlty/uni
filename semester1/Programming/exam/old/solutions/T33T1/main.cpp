#include <iostream>

using namespace std;

int NumberOfDigits(int number);

int main()
{
    int number16;
    cout << "Enter a number: ";
    cin >> number16;
    cout << NumberOfDigits(number16);
    return 0;
}

int NumberOfDigits(int number)
{
    int counter = 0;
    bool arr[10] = { false };
    while (number)
    {
        int digit = number % 16;
        number /= 16;
        if (digit < 10)
        {
            arr[digit] = true;
        }
    }
    for (int i = 0; i < 10; i++)
    {
        if (arr[i])
        {
            counter++;
        }
    }
    return counter;
}
