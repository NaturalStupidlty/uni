#include <iostream>
#include <cmath>

struct dot{
    double x;
    double y;
};

struct funcReturn{
    dot dots[3];
    double perimeter;
};

funcReturn biggestPerimeter(dot dots[], int n);
double dist(dot a, dot b){ return sqrt(pow(a.x-b.x, 2)+pow(a.y-b.y, 2));}

int main() {
    dot dots[] = {dot{2, 1}, dot{1, -1}, dot{2, -2}, dot{-2, 0}, dot{-1, 2}};
    funcReturn a = biggestPerimeter(dots, 5);
    std::cout << a.dots[0].x << ":" <<a.dots[0].y << std::endl;
    std::cout << a.dots[1].x << ":" <<a.dots[1].y << std::endl;
    std::cout << a.dots[2].x << ":" <<a.dots[2].y << std::endl;
    std::cout << a.perimeter << std::endl;
    return 0;
}

funcReturn biggestPerimeter(dot dots[], int n){
    funcReturn res{};
    res.perimeter = 0;
    for (int i = 0; i < n-2; ++i) {
        for (int j = i+1; j < n-1; ++j) {
            for (int k = j+1; k < n; ++k) {
                double per = dist(dots[i], dots[j])+dist(dots[j], dots[k])+dist(dots[k], dots[i]);
                if (per > res.perimeter) {
                    res.dots[0] = dots[i];
                    res.dots[1] = dots[j];
                    res.dots[2] = dots[k];
                    res.perimeter = per;
                }
            }
        }
    }
    return res;
}



