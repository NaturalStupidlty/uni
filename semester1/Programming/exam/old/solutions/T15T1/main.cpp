#include <iostream>

using namespace std;

void RemoveDuplicates(int *array, int &size);

int main() {
    int size;
    cout << "Enter array size: ";
    cin >> size;
    int *numbers = new int[size];
    cout << "Enter array: ";
    for (int i = 0; i < size; i++)
    {
        cin >> numbers[i];
    }
    RemoveDuplicates(numbers, size);
    for (int i = 0; i < size; i++)
    {
        cout << numbers[i];
    }
    delete[] numbers;
    return 0;
}

void RemoveDuplicates(int *array, int &size)
{
    int j = 0;
    int * buff = new int [size];
    for(int i = 0; i < size; i++)
    {
        bool flag = false;
        for(int k = 0; k < i; k++)
        {
            if (array[i] == array[k])
            {
                flag = true;
            }
        }
        if (!flag)
        {
            buff[j++] = array[i];
        }
    }
    size = j;
    for(int i = 0; i < j; i++)
    {
        array[i] = buff[i];
    }
}