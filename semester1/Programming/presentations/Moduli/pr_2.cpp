#include <iostream>
using namespace std;
int nCalls() {
  static int i=0;
  return ++i;
}
int main(){
  cout << nCalls() << endl; 
  cout << nCalls() << endl; 
  system("pause"); return 0;
}
