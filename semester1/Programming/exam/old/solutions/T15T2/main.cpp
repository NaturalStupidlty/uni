#include <iostream>

using namespace std;

char * Name(char str[], unsigned int l);

int main()
{
    const int n = 100;
    char str[n];
    cout << "Enter file path: \n";
    cin >> str;
    unsigned int l = strlen(str);
    cout << Name(str, l);
    return 0;
}

char * Name(char str[], unsigned int l)
{
    char ans[l];
    for (int i = 0; i < l; i++)
    {
        if (str[i] == '.')
        {
            while (str[i] != '\\')
            {
                i--;
            }
            int k = 0;
            for (int j = i + 1; str[j] != '.'; j++, k++)
            {
                ans[k] = str[j];
            }
            ans[k] = '\0';
            break;
        }
    }
    return ans;
}