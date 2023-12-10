#include <iostream>
using namespace std;

int shortestWordLength(char line[], int length);

int main() {
    cout << shortestWordLength("Hello   darkness   myn   friend", 30) <<endl;
    return 0;
}

int shortestWordLength(char line[], int length){
    int minLength = -1;
    int curLength = 0;
    bool lastCharWasSpace = false;
    for (int i = 0; i < length; ++i) {
        // пробел
        if(isspace(line[i])) {
            if(!lastCharWasSpace){
                if(curLength < minLength || minLength == -1) minLength = curLength;
                lastCharWasSpace = true;
            }
            curLength = 0;
        }
        // символ
        else {
            curLength++;
            lastCharWasSpace = false;
        }
    }
    return minLength;
}