#include <iostream>
using namespace std;

struct domino{
    int left;
    int right;
};

bool Correct(domino *A, int n){
    int previous = 0;
    for (int i = 0; i < n; ++i) {
        if(A[i].left != previous && i != 0) return false;
        previous = A[i].right;
    }
    return true;
}

int main() {

    domino A[4] = {domino{1,1},domino{2,1},domino{1,2},domino{2,2}};
    cout << Correct(A, 4);
    return 0;
}
