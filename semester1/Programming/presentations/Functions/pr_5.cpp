#include <iostream>
using namespace std;
void swap(int&, int&); // прототип функції обміну
int main(){
  int a, b, c;
  cout << "Enter three integers: "; 
  cin>>a>>b>>c;
  if(a>b) swap(a,b);
  if(b>c) swap(b,c);
  if(a>b) swap(a,b);
  cout<<a<<' '<<b<<' '<<c<<'\n'; 
  system("pause"); return 0;
}
void swap(int& x, int& y)
{ int t=x; x=y; y=t; }
