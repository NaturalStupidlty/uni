#include <iostream>

using namespace std;

void Remove(char v[], char w[]);

int main() {
    const int size = 100;
    char v[size], w[size];
    cout << "Enter first string ";
    cin >> v;
    cout << "Enter second string ";
    cin >> w;
    Remove(v, w);
    cout << v;
    return 0;
}

void Remove(char v[], char w[])
{
    int sizeV = strlen(v), sizeW = strlen(w);
    char *buff = new char[sizeV];
    for (int i = 0, k = 0; i < sizeV; i++)
    {
        if (v[i] == w[0])
        {
            bool flag = true; // true - підстрічка w міститься у v
            for (int j = 1, index = i+1; (j < sizeW) && (index < sizeV); j++, index++)
            {
                if (v[index] != w[j])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                i += sizeW - 1;
                continue;
            }
        }
        buff[k] = v[i];
        k++;
    }
    int sizeK = strlen(buff);
    for (int i = 0; i < sizeK; i++)
    {
        v[i] = buff[i];
    }
    v[sizeK] = '\0';
    delete[] buff;
}


