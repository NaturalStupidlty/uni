#include <iostream>

using namespace std;

void Sort(float *array, int size);

int main() {
    int size;
    cout << "Enter array size: ";
    cin >> size;
    float * array = new float [size];
    for (int i = 0; i < size; i++)
    {
        cin >> array[i];
    }
    Sort(array, size);
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    delete[] array;
    return 0;
}

void Sort(float *array, int size)
{
    // сортування вставками (але по суті сортуємо лише 1 елемент)
    float temp;
    int index;
    for (int i = 1; i < size; i++)
    {
        temp = array[i];
        index = i - 1;
        while(index >= 0 && array[index] < temp)
        {
            array[index + 1] = array[index];
            index--;
        }
        array[index + 1] = temp;
    }
}