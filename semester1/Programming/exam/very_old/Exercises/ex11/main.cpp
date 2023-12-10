#include <iostream>
using namespace std;

void decimalRepresentation(char *res, int N);

int main() {
        int N = 47;
        char res[N+3];
        decimalRepresentation(res, N);
        std::cout << res << std::endl;
 

    return 0;
}

void decimalRepresentation(char *res, int N){
    res[0] = '0';
    res[1] = '.';
    int c = 2;

    int remainders[N];
    int quotients[N];
    int r = 0;

    int dividend = 10;
    quotients[r] = 0;
    remainders[r] = 1;
    r++;
    // ---------
    while (true) {
        // добавляем нули к делимому если надо
        while (N > dividend && dividend != 0) {
            dividend *= 10;
            quotients[r] = 0;
            remainders[r] = -1;
            r++;
        }

        // делим
        int quotient = dividend / N;
        int remainder = dividend % N;
        dividend = remainder*10;
        quotients[r] = quotient;
        remainders[r] = remainder;
        r++;

        int found = -1; // ищем, был ли уже такой остаток
        for (int i = 0; i < r-1; ++i) {
            if (remainders[i] == remainder) found = i;
        }
        if (found != -1) {
            // если остаток был, перезаписываем все частные
            for (int i = 1; i < found+1; ++i) {
                res[c] = (char) (quotients[i] + 48);
                c++;
            }
            res[c] = '*';
            c++;
            for (int i = found+1; i < r; ++i) {
                res[c] = (char) (quotients[i] + 48);
                c++;
            }
            res[c] = '*';
            return;
        }
    }


}
