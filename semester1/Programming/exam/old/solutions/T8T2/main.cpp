#include <iostream>

using namespace std;

bool sim(char s[], int i, int j);

int main() {
    const int n = 100;
    char s[n];
    cout << "Enter: ";
    cin >> s;
    int i, j;
    cout << "Enter: i, j: ";
    cin >> i >> j;
    if(sim(s,i,j))
    {
        cout << "Yes!";
    }
    else
    {
         cout << "No";
    }
    return 0;
}

bool sim(char s[], int i, int j)
{
    if ((s[i] == s[j]) && (j-i <= 2))
    {
        return true;
    }
    else if (s[i] == s[j])
    {
        return sim(s, i+1, j-1);
    }
    else
    {
        return false;
    }
}