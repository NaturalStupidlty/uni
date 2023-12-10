#include <iostream>

using namespace std;

int IsSum(int a, int b, int n, int *ans);

int main()
{
    int a, b, n;
    cout << "Enter A: \n";
    cin >> a;
    cout << "Enter B: \n";
    cin >> b;
    cout << "Enter N: \n";
    cin >> n;
    int *answer = new int[n];
    int size = IsSum(a, b, n, answer);
    for (int i = 0; i < size; i++)
    {
        cout << answer[i] << " ";
    }
    delete[] answer;
    return 0;
}

int IsSum(int a, int b, int n, int *ans)
{
    int j = 0;
    for (int i = 2; i < n; i++)
    {
        if ((i % a == 0) || (i % b == 0) || ((i >= b) && ((i - b) % a == 0)) || ((i >= a) && ((i - a) % b == 0)))
        {
            ans[j] = i;
            j++;
        }
    }
    return j; // повертаємо розмір масива, у якому зберігаємо відповідь, щоб з ним було легше працювати
}
