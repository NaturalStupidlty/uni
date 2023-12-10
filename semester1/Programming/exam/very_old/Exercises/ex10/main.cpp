#include <iostream>
#include <cmath>
using namespace std;

void nearest(double *res, double *A, int n);

int main() {
    double res[2];
    double a[] = {12, 15.9, 21, 2, 67, 14};
    nearest(res, a, 6);
    cout << res[0] << " " << res[1] << endl;
    return 0;
}

void nearest(double *res, double *A, int n){
    int n1 = 0;
    int n2 = 0;
    double lowestDistance = INT_MAX;

    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            double dist = abs(A[i]-A[j]);
            if(dist < lowestDistance){
                n1 = i; n2 = j;
                lowestDistance = dist;
            }
        }
    }

    res[0] = n1;
    res[1] = n2;
}