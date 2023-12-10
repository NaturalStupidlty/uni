#include <iostream>

using namespace std;

void FindNumbers(int n, int *ptr, int &index);

int main() {
    int n, index = 0;
    // індекс буде нести інформацію про кількість знайдених елементів, що відповідають умові
    cout << "Enter N: ";
    cin >> n;
    int *ptr = new int[n];
    FindNumbers(n, ptr, index);
    for (int i = 0; i < index; i++)
    {
        cout << ptr[i] << endl;
    }
    delete [] ptr;
    return 0;
}

void FindNumbers(int n, int *ptr, int &index)
{
    for (int i = 1; i < n; i++)
    {
        int digit, reversed = 0, num = i;
        do
        {
            digit = num % 10;
            reversed = (reversed * 10) + digit;
            num /= 10;
        }
        while (num);
        if (reversed == i)
        {
            int iSquared = i*i; // щоб не рахувати квадрат і 2 рази
            reversed = 0, num = iSquared;
            do
            {
                digit = num % 10;
                reversed = (reversed * 10) + digit;
                num /= 10;
            }
            while (num);
            if (reversed == iSquared)
            {
                ptr[index]=i;
                index++;
            }
        }
    }
}
