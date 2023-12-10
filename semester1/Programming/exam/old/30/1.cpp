#include <iostream>
using namespace std;

void shift(double *A, int n, int k);

int main() {
    double A[] = {1,2,3,4,5,6,7,8,9,10};
    shift(A, 10, 4);

    for (int i = 0; i < 10; ++i) {
        cout << A[i] << " ";
    }

    return 0;
}

void shift(double *A, int n, int k){
    if(k >= n || k < 1 || k > 4) return; // перевірка правильності даних
    double memory[4];

    for (int i = n-k; i < n; ++i) {
        memory[(i-n+k)%k] = A[i]; // запис останніх k елементів масиву у додатковий масив memory
    }

    // для кожного елементу масиву
    for (int i = 0; i < n; ++i) {
        double t = A[i];

        // перезаписуємо на його місце число, що було k індексів раніше
        A[i] = memory[i%k];

        // записуємо оригінальне число у пам'ять
        memory[i%k] = t;
    }

}