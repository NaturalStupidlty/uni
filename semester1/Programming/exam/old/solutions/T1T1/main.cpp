#include <iostream>
#include <cmath>
using namespace std;

int FindMax(int n);

int main() {
    int n;
    cout << "Enter N";
    cin >> n;
    cout << FindMax(n);
    return 0;
}

int FindMax(int n)
{
    int ans, maxsum = 1, sum = 1;
    for (int i = 2; i <= n; i++)
    {
        int isqrt = sqrt(i);
        for (int j = 1; j < isqrt; j++)
        {
            if(i % j == 0)
            {
                sum += j + i/j;
            }
        }
        if (sum >= maxsum)
        {
            maxsum = sum;
            ans = i;
        }
        sum = 0;
    }
    return ans;
}