#include <iostream>
using namespace std;

int find(char *a, int n1, char *b, int n2, int n);

int main() {

    char str1[] = "absdefg";
    char str2[] = "asdabsdefgasfg";
    char *pstr1 = str1;
    char *pstr2 = str2;

    cout << find(pstr1, 7, pstr2, 14, 12);

//    char a[4] = "ABC";
//    char b[10] = "aaaaABCaa";
//    std::cout << find(a, 2, b, 9, 7) << std::endl;
    return 0;
}

int find(char *a, int n1, char *b, int n2, int n){
    if(n > n2) n = n2;
    int aCounter = 0;

    for (int i = 0; i < n; ++i) {
        if(b[i] == a[aCounter]){
            if(aCounter == n1-1) return i - n1 + 1;
            aCounter++;
        } else {
            aCounter = 0;
        }
    }
    return -1;
}