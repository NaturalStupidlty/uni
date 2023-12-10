#include <iostream>

using namespace std;

void ArraySort(float *A, int n);

int main() {
    int n;
    cout << "Enter array size: ";
    cin >> n;
    float *A = new float[n];
    cout << "Enter array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    ArraySort(A, n);
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    delete[]A;
    return 0;
}

void ArraySort(float *A, int n)
{
    float b;
    for (int i = 0; i < n; i++)
    {
        if (A[i] >= 0)
        {
            for (int j = 0; j < i; j++)
            {
                if (A[j] < 0)
                {
                    b = A[i];
                    A[i] = A[j];
                    A[j] = b;
                }
            }
        }
    }
}