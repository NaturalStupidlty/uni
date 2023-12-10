#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

void decimalToBinary(char *res, char *dec);

int main() {
    char a[100];
    decimalToBinary(a, "3246");
    cout << "res: "<<a<<endl;
    return 0;
}

void decimalToBinary(char *res, char *dec){
    int digits = strlen(dec);
    long d = 0;
    for (int i = 0; i < digits; ++i) {
        d += ((int) dec[i]-48)*pow(10, digits-i-1);
    }
    int binDigits = 0;
    for (long i = 1; i <= d; i*=2) {
        binDigits++;
    }
    res[binDigits] = '\0';
    int c = binDigits-1;

    while(d >= 2){
        res[c] = (d%2)+'0';
        d /= 2;
        c--;
    }
    res[c] = d+'0';
}