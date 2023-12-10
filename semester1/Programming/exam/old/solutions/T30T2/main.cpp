#include <iostream>

char * Merger(char s1[], char s2[], unsigned int n1, unsigned int n2);

using namespace std;

int main() {
    const int size = 100;
    unsigned int n1, n2;
    char s1[size], s2[size];
    cout << "Enter N1, N2: ";
    cin >> n1 >> n2;
    cout << "Enter S1: ";
    cin >> s1;
    cout << "Enter S2: ";
    cin >> s2;
    cout << Merger(s1, s2, n1, n2);
    return 0;
}

char * Merger(char s1[], char s2[], unsigned int n1, unsigned int n2)
{
    char ans[n1+n2];
    int i = 0, s2Size = strlen(s2);
    for (; i < n1; i++)
    {
        ans[i] = s1[i];
    }
    for (int j = s2Size - (int)n2; j < s2Size; i++, j++)
    {
        ans[i] = s2[j];
    }
    ans[i]= '\0';
    return ans;
}