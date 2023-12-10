#include <iostream>
#include <cmath>
using namespace std;

struct dot{
    double x;
    double y;
};

struct funcReturn{
    dot dots[2];
    double distance;
};

funcReturn biggestDistance(dot A[], int n1, dot B[], int n2);
double dist(dot a, dot b){ return sqrt(pow(a.x-b.x, 2)+pow(a.y-b.y, 2));}

int main() {
    dot A[] = {dot{2, 1}, dot{1, -1}, dot{-2, 0}, dot{-1, 2}};
    dot B[] = {dot{1, 12}, dot{24, -24}, dot{32, -42}, dot{-3, 10}, dot{-21, 21}};
    funcReturn a = biggestDistance(A, 4, B, 5);
    cout << a.dots[0].x << ":" << a.dots[0].y << ", " << a.dots[1].x << ":" << a.dots[1].y << " -> " << a.distance << endl;
    return 0;
}

funcReturn biggestDistance(dot A[], int n1, dot B[], int n2){
    funcReturn res{};
    res.distance = 0;
    for (int i = 0; i < n1; ++i) {
        for (int j = 0; j < n2; ++j) {
                double d = dist(A[i], B[j]);
                if (d > res.distance) {
                    res.dots[0] = A[i];
                    res.dots[1] = B[j];
                    res.distance = d;
                }
        }
    }
    return res;
}



