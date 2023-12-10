#include <iostream>
using namespace std;

void inputPoint(double x, double y)
{ cout<<"Enter point (real coordinates x and y): ";
  cin>>x>>y;    
}

void writePoint(double x, double y)
{ cout << "(" << x << ", " << y << ")"; }

int main(){
  double x=0, y=0;
  cout << "\"Old value\": "; writePoint(x,y); cout<<endl;
  inputPoint(x,y);
  cout << "\"New value\": "; writePoint(x,y); cout<<endl;
  system("pause"); return 0;
}
