#include <iostream>
#include "points.h"
using namespace std;

int main(){
  double x=0, y=0;
  cout << "\"Old value\": "; writePoint(x,y); cout<<endl;
  inputPoint(x,y);
  cout << "\"New value\": "; writePoint(x,y); cout<<endl;
  system("pause"); return 0;
}
