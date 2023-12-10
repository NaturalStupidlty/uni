#include <iostream>
using namespace std;

void code(char res[], char str[], int n);

int main() {
    char str[] = "Helloworld";
    char res[10];
    code(res, str, 10);
    cout << str << " -> " << res;
    return 0;
}

void code(char res[], char str[], int n){
    for (int i = 0; i < n; ++i) {
        int c = (int) str[i];
        if((c >= 65 && c <= 89) || (c >= 97 && c <= 121)) res[i] = (char) (c + 1);
        else if (c == 90 || c == 121) res[i] = (char) (c - 25);
    }
}