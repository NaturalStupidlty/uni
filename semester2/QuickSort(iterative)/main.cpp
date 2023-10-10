#include <iostream>
#include <cstdlib>

using namespace std;

void QuickSort(int * array, size_t size);
void Swap(int & a, int & b);

int main()
{
    const int n = 100;
    int *test = new int[n];
    for (int i = 0; i < n; i++)
    {
        test[i] = rand() % 100;
    }
    QuickSort(test, n);
    for (int i = 0; i < n; i++)
    {
        cout << test[i] << ' ' << endl;
    }
    return 0;
}

void QuickSort (int * array, size_t size)
{
    const int n = 1000;
    int leftStack[n], rightStack[n], base;
    leftStack[1] = 0;
    rightStack[1] = size - 1;
    for(int i, j, left, right, pos = 1, mid; pos;)
    {
        left = leftStack[pos];
        right = rightStack[pos];
        --pos;
        while (left < right)
        {
            mid = (left + right) >> 1;
            i = left; j = right; base = array[mid];
            while (i <= j)
            {
                while (array[i] < base or base < array[j])
                {
                    if (array[i] < base)
                    {
                        i++;
                    }
                    else
                    {
                        j--;
                    }
                }
                if (i <= j)
                {
                    Swap(array[i], array[j]);
                    i++;
                    j--;
                }
            }
            if (i < mid)
            {
                if (i < right)
                {
                    pos++;
                    leftStack[pos] = i;
                    rightStack[pos] = right;
                }
                right = j;
            }
            else
            {
                if (j > left)
                {
                    pos++;
                    leftStack[pos] = left;
                    rightStack[pos] = j;
                }
                left = i;
            }
        }
    }
}

void Swap(int & a, int & b)
{
    int temp = a;
    a = b;
    b = temp;
}
