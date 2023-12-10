#include <iostream>
#include <algorithm>

using namespace std;

void FindMatrix(int** A, int** B, int n);

int main()
{
    int n;
    cout << "Enter matrix (NxN) size : \n";
    cin >> n;
    cout << "Enter matrix : \n";
    int **A = new int*[n];
    for(int i = 0; i < n; ++i)
    {
        A[i] = new int[n];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> A[i][j];
        }
    }
    int **B = new int*[n];
    for(int i = 0; i < n; ++i)
    {
        B[i] = new int[n];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << A[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
    FindMatrix(A, B, n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << B[i][j] << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < n; i++)
    {
        delete [] A[i];
        delete [] B[i];
    }
    return 0;
}

void FindMatrix(int** A, int** B, int n)
{
    for (int i = 0; i < n; i++)                                 // заповнюємо діагональ
    {
        B[i][i] = A[i][i];
    }
    for (int k = 1; k < n; k++)
    {
        for (int i = k, j = 0; i < n; i++, j++)
        {
            B[i][j] = min(A[i][j], min(B[i-1][j], B[i][j+1]));
        }
        int size = n - k;
        for (int i = 0; i < size; i++)
        {
            int j = i + k;
            B[i][j] = min(A[i][j], min(B[i][j-1], B[i+1][j]));

        }
    }
}