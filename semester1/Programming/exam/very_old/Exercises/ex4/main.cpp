#include <iostream>
using namespace std;

int sumOfDif(int A[], int n);
bool inArray(int el, int arr[], int n);

int main() {
    int n = 7;
    int A[] = {1, 3, 5, 1, 4, 3, 7};
    cout << sumOfDif(A, n);
    return 0;
}

int sumOfDif(int A[], int n){
    int summedNumbers[n];
    int c = 0;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        if(!inArray(A[i], summedNumbers, c)){
            summedNumbers[c] = A[i];
            sum += A[i];
            c++;
        }
    }
    return sum;
}

bool inArray(int el, int arr[], int n){
    for (int i = 0; i < n; ++i) {
        if(arr[i] == el) return true;
    }
    return false;
}