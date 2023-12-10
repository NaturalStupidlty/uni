#include <iostream>
using namespace std;

int mostRepeatedDigit(char *s, int n){
    int numbers[10] = {0};
    for (int i = 0; i < n; ++i) {
        if(isdigit(s[i])) numbers[(int) s[i] - 48]++;
    }
    int maxN = 0, max = numbers[0];
    for (int i = 0; i < 10; ++i) {
        if(numbers[i] > max) {
            max = numbers[i]; maxN = i;
        }
    }
    return maxN;
}

int main() {
    std::cout << mostRepeatedDigit("2x5nb728y977727", 12) << std::endl;
    return 0;
}
