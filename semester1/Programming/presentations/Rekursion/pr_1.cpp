#include <iostream>
using namespace std;
int f(int x)
{ return ++x; }
int g(int& x)
{ return x/=2;  }
int main(){
  int a=12;
  cout << f(g(a)) << ' ';   
  cout << a << endl; 
  system("pause"); return 0;
}
