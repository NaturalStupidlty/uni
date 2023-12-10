#include <iostream>
using namespace std;
int biggerThanColumnCount(double **A, int m, int n){
    int count = 0;
    for (int i = 0; i < n; ++i) {
        double sum = 0;
        for (int k = 0; k < m; ++k) {
            sum += A[k][i];
        }
        for (int j = 0; j < m; ++j) {
            if(A[j][i] > sum-A[j][i]) {
                count++;
                break;
            }
        }
    }
    return count;
}

int main() {
    int m = 4;
    int n = 3;
    double **A = new double *[m];
    for (int i = 0; i < m; ++i) {
        A[i] = new double[n];
        for (int j = 0; j < n; ++j) {
            A[i][j] = (i-j)*i;
        }
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }

    cout << biggerThanColumnCount(A, m, n) << endl;
    return 0;
}
