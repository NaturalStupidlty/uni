#include <iostream>

using namespace std;

int * GetIndexArray(float *array, int s);

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
    int *answer = GetIndexArray(A, n);
    for (int i = 0; i < n; i++)
    {
        cout << answer[i] << " ";
    }
    delete []A;
    return 0;
}

int * GetIndexArray(float *array, int s)
{
    int *I = new int[s];
    // моя ідея полягає у тому, щоб спочатку створити масив з послідовними номерами єлементів
    // а потім використати сортування масиву, але сортувати не даний масив
    // а саме масив з індексами
    // (для прикладу, тут використане сортування методом вибору)
    for(int i = 0; i < s; i++)
    {
        I[i] = i;
    }
    for (int i = 0; i < s - 1; i++)
    {
        int smallestIndex = i;
        for (int j = i + 1; j < s; ++j) {
            if (array[I[j]] < array[I[smallestIndex]])
                smallestIndex = j;
        }
        swap(I[i], I[smallestIndex]);
    }
    return I;
}