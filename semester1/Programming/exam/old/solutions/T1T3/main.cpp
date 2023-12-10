#include <iostream>

using namespace std;

void Remove(char v[], char w[]);

int main() {
    const int size = 100;
    char v[size], w[size];
    cout << "Enter 1 string ";
    cin >> v;
    cout << "Enter 2 string ";
    cin >> w;
    Remove(v, w);
    cout << v;
    return 0;
}

void Remove(char v[], char w[])
{
    int i, j, k;
    for (k = 0; w[k] != '\0'; k++)
    {
        for (i = j = 0; v[i] != '\0'; i++)
        {
            if (v[i] != w[k])
                v[j++] = v[i];
        }
        v[j] = '\0';
    }
}