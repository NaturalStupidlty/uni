#include <iostream>
#include <cmath>

using namespace std;

void Perfect(int n, int *ptr, int &index);

int main() {
    int n, index = 0;
    // індекс буде нести інформацію про кількість знайдених елементів, що відповідають умові
    // щоб потім можна було працювати з масивом цих елементів
    cout << "Enter N: ";
    cin >> n;
    int *ptr = new int[n];
    Perfect(n, ptr, index);
    for (int i = 0; i < index; i++)
    {
        cout << ptr[i] << endl;
    }
    delete [] ptr;
    return 0;
}

void Perfect(int n, int *ptr, int &index)
{
    for (int i = 1; i < n; i++)
    {
        int sum = 1;
        double iSqrt = sqrt(i);
        for (int j = 2; j < iSqrt; j++)
        {
            if(i % j == 0)
            {
                sum += j + i/j;
            }
        }
        if (sum == i)
        {
            ptr[index]=i;
            index++;
        }
    }
}