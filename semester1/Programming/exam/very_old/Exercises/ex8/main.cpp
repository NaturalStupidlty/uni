#include <iostream>
using namespace std;

double maxRepeated(double **A, int n, int m);
bool inArr(double el, double arr[], int len);

int main() {
    int m = 3;
    int n = 3;
    double **arr;
    arr = new double *[m];
    for (int i = 0; i < m; ++i) {
        arr[i] = new double[n];
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            arr[i][j] = i+j;
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    cout << maxRepeated(arr, n, m) << endl;

    delete [] arr;
    return 0;
}

double maxRepeated(double **A, int n, int m){
    double best = INT_MIN;
    double candidates[n*m];
    int count = 0;

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if(inArr(A[i][j], candidates, count)){
                if(A[i][j] > best) best = A[i][j];
            } else {
                candidates[count] = A[i][j];
                count++;
            }
        }
    }
    return best;
}

bool inArr(double el, double arr[], int len){
    for (int i = 0; i < len; ++i) {
        if(el == arr[i]) return true;
    }
    return false;
}