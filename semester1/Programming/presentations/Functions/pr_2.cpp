#include <iostream>
#include <cmath>
using namespace std;

//double dist(double a1, double b1, double a2, double b2);
double dist(double, double, double, double);
//distance from (a1,b1) to (a2,b2)

int main()
{ double x1, y1, x2, y2, x3, y3;
  cout << "Enter three pairs of coordinates: "; 
  // введення конкретних координат
  cin>>x1>>y1>>x2>>y2>>x3>>y3;
  cout << "Perimeter = " << 
    dist(x1,y1,x2,y2)+  //виклик для першої сторони
    dist(x1,y1,x3,y3)+  //виклик для другої сторони
    dist(x2,y2,x3,y3);  //виклик для третьої сторони
  system("pause"); return 0;
}
double dist(double a1, double b1, double a2, double b2)
{
  return sqrt((a1-a2)*(a1-a2)+(b1-b2)*(b1-b2));
}