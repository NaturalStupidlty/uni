#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int n = 5;

void compute(double *S, double **A);

int main() {
    double S[59];
    // generating
    srand(time(0));
    double **A = new double *[n];
    for (int i = 0; i < n; ++i) {
        A[i] = new double [n];
    }
    cout << "Randomising...\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            A[i][j] = rand() % 10;
        }
    }
    // input
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
    cout << "==================================\n";
    // f
    compute(S, A);
    // output
    for (int i = 0; i < 2*n-1; ++i) {
        cout << S[i] << " ";
    }

    return 0;
}

void compute(double *S, double **A){
    int sCounter = 0;
    // нижняя половина и главная диагональ
    for (int i = n-1; i >= 0; --i) {
        double s = 1;
        for (int p = i; p < n; ++p) {
            s *= A[p][p-i];
        }
        S[sCounter] = s; sCounter++;
    }
    // верхняя половина
    for (int i = 1; i < n; ++i) {
        double s = 1;
        for (int p = i; p < n; ++p) {
            s *= A[p-i][p];
        }
        S[sCounter] = s; sCounter++;
    }
}
