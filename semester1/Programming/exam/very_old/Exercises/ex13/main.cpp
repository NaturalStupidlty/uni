#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

struct fR{double min; int pos;};
void display(char *s, double *a, int n){cout <<s<<": ";for (int i = 0; i < n; ++i) {cout << a[i] << " ";} cout << endl;}
fR minLocalMax(double *A, int n);

int main() {
    srand(time(0));
    int n = 10;
    double A[n];
    for (int i = 0; i < n; ++i) {
      A[i] = rand() % 10;
    }
    fR res = minLocalMax(A, n);
    cout << res.min << ", pos "<<res.pos<<endl;
    return 0;
}

fR minLocalMax(double *A, int n){
    display("Input", A, n);
    double min = INT_MAX;
    int pos = -1;

    double ass[n];
    for (int i = 0; i < n; ++i) {
        // local max
        double localMax = A[i];
        if(i != 0) localMax = max(localMax, A[i-1]);
        if(i != n-1) localMax = max(localMax, A[i+1]);
        //
        if(localMax < min) {
            min = localMax;
            pos = i;
        }
        ass[i] = localMax;
    }
    display("Local", ass, n);
    return fR{min, pos};
}