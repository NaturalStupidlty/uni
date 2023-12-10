//6.Константний вираз

#include <iostream>
#include <fstream>
#include <ctype.h>
using namespace std;

int constant(char a[], size_t s);
int integer(char a);
int sign(char a);
void RemoveValues(char array[], int& n);

int main()
{
    const int n = 255;
    char buff[n];
    ifstream fin("syntax.txt");
    fin.getline(buff, n);
    int size = strlen(buff);
    RemoveValues(buff, size); // спочатку приберемо з виразу дужки, якщо вони є
    if (constant(buff, size) == 0)
    {
        cout << "It's a constant";
    }
    else
    {
        cout << "It's not a constant";
    }
    fin.close();
    return 0;
}

int constant(char a[], size_t s)
{
    const int n = 255;
    char arr1[n];
    for (int i = 0; (i < s) && (a[i] != '/0'); i++)
    {
        if (integer(a[i]))
        {
            if (sign(a[i]) == 0)
            {
                i + 1;
                for (int j = 0; (j < s) && (a[i] != '/0'); j++, i++)
                {
                    arr1[j] = a[i];
                }
                int s1 = strlen(arr1);
                return (constant(arr1, s1));
            }
            else
            {
                return 1;
            }
        }
    }
    return 0;
}

int integer(char a)
{
    if (a == '1' || '2' || '3' || '4' || '5' || '6' || '7' || '8' || '9' || '0')
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int sign(char a)
{
    if (a == '+' || '-' || '*' || '//')
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

void RemoveValues(char array[], int &n) {
    int j = 0; 

    for (int i = 0; i < n; i++) {
        if (array[i] != ')' && '(') { 
            array[j++] = array[i]; 
        }
    }

    n = j; 
}