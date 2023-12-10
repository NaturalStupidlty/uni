#include <iostream>
#include <cctype>

using namespace std;

bool IsIdentifier(char str[], int &errorIndex);

int main() {
    const int n = 50;
    int error = 0;
    char ident[n];
    cout << "Enter a string: ";
    cin >> ident;
    if (IsIdentifier(ident, error))
    {
        cout << "It is an identifier";
    }
    else
    {
        cout << "It is not an identifier" << endl;
        cout << "Error index: " << error;
    }
    return 0;
}

bool IsIdentifier(char str[], int &errorIndex)
{
    int size = strlen(str);
    if (isalpha(str[0]))
    {
        for (int i = 1; i < size; i++)
        {
            if (!isdigit(str[i]) && !isalpha(str[i]) && str[i] != '_')
            {
                errorIndex = i;
                return false;
            }
        }
        return true;
    }
    else
    {
        errorIndex = 0;
        return false;
    }
}