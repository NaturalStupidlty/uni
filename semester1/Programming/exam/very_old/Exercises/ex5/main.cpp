#include <iostream>
using namespace std;

void cup(int *res, int A[], int n1, int B[], int n2);

int main() {
    int n1 = 7;
    int n2 = 5;
    int A[] = {1, 3, 6, 9, 13, 15, 21};
    int B[] = {6, 8, 10, 24, 69};
    int C[n1+n2];
    cup(C, A, n1, B, n2);
    for (int i = 0; i < n1 + n2; ++i) {
        cout << C[i] << endl;
    }
    return 0;
}

void cup(int *res, int A[], int n1, int B[], int n2){
    int aCounter = 0;
    int bCounter = 0;

    int n = n1+n2;
    for (int i = 0; i < n; ++i) {
        if (aCounter != n1 && A[aCounter] < B[bCounter]){
            res[i] = A[aCounter];
            aCounter++;
        } else {
            res[i] = B[bCounter];
            bCounter++;
        }
    }
}
