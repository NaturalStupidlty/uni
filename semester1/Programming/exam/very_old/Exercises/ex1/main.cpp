#include <iostream>

using namespace std;

int SumOfPrimes(int A[], int n);

int main()
{
    int n = 7;
    int A[] = {1, 2, 3, 40, 5, 6, 7};
    cout << SumOfPrimes(A, n);
    return 0;
}

int SumOfPrimes(int A[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; ++i)
    {
        bool prime = true;
        for (int j = 2; j < A[i]; ++j)
        {
            if(A[i]%j == 0)
            {
                prime = false;
            }
        }
        if(prime)
        {
            sum += A[i];
        }
    }
    return sum;
}
