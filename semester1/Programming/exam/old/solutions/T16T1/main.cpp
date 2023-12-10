#include <iostream>

using namespace std;

void RemoveSeries(int *array, int &size, int k);

int main() {
    int size, k;
    cout << "Enter array size:";
    cin >> size;
    int *A = new int[size];
    cout << "Enter array: ";
    for (int i = 0; i < size; i++)
    {
        cin >> A[i];
    }
    cout << "Enter k: ";
    cin >> k;
    RemoveSeries(A, size, k);
    for (int i = 0; i < size; i++)
    {
        cout << A[i];
    }
    return 0;
}

void RemoveSeries(int *array, int &size, int k)
{
    for (int i = 0, j; i < size - 1; i++)
    {
        bool flag = false;
        if (array[i] == array[i + 1])
        {
            for (j = i + 1; (j < size - 1) && (array[j] == array[j+1]); j++);
            if ((j - i + 1) >= k)
            {
                flag = true;
            }
        }
        if (flag)
        {
            for (int h = 0, l = 0; h < size; h++)
            {
                if (h < i || h > j)
                {
                    array[l] = array[h];
                    l++;
                }
            }
            size -= j - i + 1;
            break;
        }
    }
}