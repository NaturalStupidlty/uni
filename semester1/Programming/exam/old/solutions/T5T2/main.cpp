#include <iostream>

using namespace std;

void FindMatrix(float **A, float *B, int s);

int main() {
    int n;
    cout << "Enter n:";
    cin >> n;
    float **A = new float*[n];
    for(int i = 0; i < n; ++i){
        A[i] = new float[n];
    }
    cout << "Enter matrix: ";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> A[i][j];
        }
    }
    int size = 2*n-1;
    float *B = new float[size];
    FindMatrix(A, B, n);
    for (int i = 0; i < size; i++)
    {
        cout << B[i] << " ";
    }\
    delete [] B;
    for (int i = 0; i < n; i++)
    {
        delete [] A[i];
    }
    return 0;
}

void FindMatrix(float **A, float *B, int s)
{
    int k, l = 0, size = 2*s -1;
    float sum;
    for (int i = 0; i < size; i++)
    {
        sum = 0;
        k = i;
        if (i >= s)
        {
            k = s - 1;
            l++;
        }
        int length = l - 1;
        for (int j = k; j > length; j--)
        {
            sum += A[k+l-j][j];
        }
        B[i] = sum;
    }
}