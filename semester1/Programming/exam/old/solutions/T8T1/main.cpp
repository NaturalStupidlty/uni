#include <iostream>
#include <cmath>

using namespace std;

int* NotPrime(int *A, int size, int &answerSize);

int main() {
    int n, size = 0;
    cout << "Enter array size:";
    cin >> n;
    int *A = new int[n];
    cout << "Enter array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    int * answer = NotPrime(A, n, size);
    for (int i = 0; i < size; i++)
    {
        cout << answer[i] << ' ';
    }
    delete[] A;
    return 0;
}

int *NotPrime(int *A, int size, int &answerSize)
{
    int * notPrime = new int[answerSize];
    int j = 0;
    for (int i = 0; i < size; i++)
    {
        int a = A[i];
        if (a == 2 || a == 3)
        {
            continue;
        }
        else if (a == 1)
        {
            notPrime[j] = A[i];
            j++;
            continue;
        }
        int aSqrt = sqrt(a);
        bool flag = false;
        for (int k = 2; k <= aSqrt; i++)
        {
            if (A[i] % k == 0)
            {
                flag = true;
                break;
            }
        }
        if (flag)
        {
            notPrime[j] = A[i];
            j++;
        }
    }
    answerSize = j;
    return notPrime;
}