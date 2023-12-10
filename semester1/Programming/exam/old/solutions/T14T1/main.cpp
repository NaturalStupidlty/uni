#include <iostream>

using namespace std;

int MaxNullLength(int *ptr, int n, int &firstIndex, int &lastIndex);

int main() {
    int n, firstIndex = 0, lastIndex = 0;
    cout << "Enter array size: ";
    cin >> n;
    int *array = new int[n];
    cout << "Enter array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }
    cout << "Maximal null sequence length: " << MaxNullLength(array, n, firstIndex, lastIndex) << endl;
    if (lastIndex)
    {
        cout << "First index: " << firstIndex << " Last index: " << lastIndex;
    }
    return 0;
}

int MaxNullLength(int *ptr, int n, int &firstIndex, int &lastIndex)
{
    int maxNull = 0, counter = 0, first, last = 0;
    for (int i = 0; i < n; i++)
    {
        if (ptr[i] == 0)
        {
            counter = 1;
            first = i;
            last = i;
            for (int j = i + 1; (ptr[j] == 0) && (j < n); j++)
            {
                counter++;
                last = j;
            }
        }
        if (counter > maxNull)
        {
            maxNull = counter;
            firstIndex = first;
            lastIndex = last;
        }
        counter = 0;
    }
    return maxNull;
}