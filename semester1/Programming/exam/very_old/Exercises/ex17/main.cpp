#include <iostream>
using namespace std;

int maxOwnDividersSum(int n){
    int maxSum = 1;
    int res = 1;
    for (int i = n; i > n/2; --i) {
        // i - число
        int sum = 0;
        for (int j = 1; j < n; ++j) {
            if (i%j==0) sum += j;
        }
        if(sum > maxSum) {
            maxSum = sum;
            res = i;
        }
    }
    return res;
}

int main() {
    int i = 17662;
    cout << i<<") "<<maxOwnDividersSum(i) << endl;
//    for (int i = 2; i < 130; ++i) {
//        cout << i<<") "<<maxOwnDividersSum(i) << endl;
//    }
//    double max = 0;
//    for (double i = 3; i < 10000; i+=1) {
//        if(maxOwnDividersSum(i)/i>max) {
//            cout << i << ") "<<maxOwnDividersSum(i) << " -> "<<maxOwnDividersSum(i)/i<<endl;
//            max = maxOwnDividersSum(i)/i;
//        }
//    }
    return 0;
}
