#include <iostream>
using namespace std;

int countGrowthZones(double *A, int n);

int main() {
    double A[] = {1,2,1,2};
    std::cout << countGrowthZones(A, 4) << std::endl;
    return 0;
}

int countGrowthZones(double *A, int n){
    int zones = 0;
    bool lastWasGrowing = false;
    for (int i = 0; i < n-1; i++) {
        if(A[i+1]-A[i] > 0){
            if(!lastWasGrowing){
                zones++;
                lastWasGrowing = true;
            }
        } else {
            lastWasGrowing = false;
        }
    }
    return zones;
}