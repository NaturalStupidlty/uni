#include <iostream>

using namespace std;

void RemoveElements(int *A, int &size);

int main() {
    int n;
    cout << "Enter array size: ";
    cin >> n;
    cout << "Enter array: ";
    int * A = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    RemoveElements(A, n);
    for (int i = 0; i < n; i++)
    {
        cout << A[i];
    }
    return 0;
}

void RemoveElements(int *A, int &size)
{
    int * buff = new int[size];
    int k = 0, counter = 0; // counter - кількість разів, коли видаляли елемент з масиву
    for (int i = 0; i < size; i++)
    {
        buff[k++] = A[i]; // перше входження
        int j = i + 1;
        for(; A[i] == A [j]; j++, counter++);
        i = j - 1;
    }
    size -= counter;
    for (int i = 0; i < k; i++)
    {
        A[i] = buff[i];
    }
}