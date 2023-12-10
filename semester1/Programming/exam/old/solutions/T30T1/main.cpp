#include <iostream>

void ArrayShift(float *A, int k, int size);

using namespace std;

int main() {
    int size, k;
    cout << "Enter array size: ";
    cin >> size;
    float *A = new float [size];
    cout << "Enter array: ";
    for (int i = 0; i < size; i++)
    {
         cin >> A[i];
    }
    cout << "Enter k: ";
    cin >> k;
    ArrayShift(A, k, size);
    for (int i = 0; i < size; i++)
    {
        cout << A[i] << ' ';
    }
    delete[] A;
    return 0;
}

void ArrayShift(float *A, int k, int size)
{
    // перевірка помилок
    if( k < 1 || k > 4 || k >= size)
    {
        return;
    }
    float buff[4], temp;
    // записуємо в буфер частину масиву, яка зсунеться
    for (int i = size - k; i < size; i++)
    {
        buff[(i - size + k) % k] = A[i];
    }
    // переписуємо массив
    for (int i = 0; i < size; i++)
    {
        temp = A[i];
        A[i] = buff[i % k];
        buff[i % k] = temp;
    }
}