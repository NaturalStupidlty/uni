#include <iostream>
#include <cmath>
using namespace std;

//double dist(double a1, double b1, double a2, double b2)
double dist(double, double, double, double);
//distance from (a1,b1) to (a2,b2)

void writePoint(double, double);
//write point (x, y)

int main()
{ double x1, y1, x2, y2, x3, y3;
  cout << "Enter three pairs of coordinates: "; 
  // введенн€ конкретних координат
  cin>>x1>>y1>>x2>>y2>>x3>>y3;
  cout << endl;
  cout << "Coordinates: ";
  writePoint(x1, y1);
  writePoint(x2, y2);
  writePoint(x3, y3);
  cout << endl;
  cout << "Perimeter = " << 
    dist(x1,y1,x2,y2)+  //виклик дл€ першоњ сторони
    dist(x1,y1,x3,y3)+  //виклик дл€ другоњ сторони
    dist(x2,y2,x3,y3);  //виклик дл€ третьоњ сторони
  system("pause"); return 0;
}
double dist(double a1, double b1, double a2, double b2)
{
  return sqrt((a1-a2)*(a1-a2)+(b1-b2)*(b1-b2));
}
void writePoint(double x, double y)
{ cout << У(Ф << x <<У, Ф << y << У) Ф}