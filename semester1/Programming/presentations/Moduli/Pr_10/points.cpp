#include <iostream>
using namespace std;

void inputPoint(double &x, double &y)
{ cout<<"Enter point (real coordinates x and y): ";
  cin>>x>>y;    
}

void writePoint(double x, double y)
{ cout << "(" << x << ", " << y << ")"; }

