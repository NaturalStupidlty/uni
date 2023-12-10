#include <iostream>
#include <cstdlib>

using namespace std;

int Solve(char str[], int s);

int main() {
    const int n = 100;
    char str[n];
    cout << "Enter string: ";
    cin >> str;
    int s = strlen(str);
    cout << Solve(str, s);
    return 0;
}

int Solve(char str[], int s)
{
    int answer = atoi(str);
    char buff[1];
    for (int i = 1; i < s; i++)
    {
        if (str[i] == '+')
        {
            buff[0] = str[i+1];
            answer += atoi(buff);
        }
        else
        {
            buff[0] = str[i+1];
            answer -= atoi(buff);
        }
    }
    return answer;
}