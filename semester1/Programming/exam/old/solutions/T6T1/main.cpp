#include <iostream>
#include <cmath>

using namespace std;

int PrimeSum(int * ptr, int n);

int main() {
    int n;
    cout << "Enter array size (n): ";
    cin >> n;
    int * ptr = new int[n];
    cout << "Enter array: ";
    for (int i = 0; i< n; i++)
    {
        cin >> ptr[i];
    }
    cout << PrimeSum(ptr, n);
    delete[] ptr;
    return 0;
}

int PrimeSum(int *ptr, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        int a = ptr[i];
        if (a == 2 || a == 3)
        {
            sum += a;
            continue;
        }
        else if (a == 1)
        {
            continue;
        }
        bool flag = true;
        int aSqrt = int(sqrt(a));
        for (int j = 2; j <= aSqrt; i++)
        {
            if (a % j == 0)
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            sum += a;
        }
    }
    return sum;
}