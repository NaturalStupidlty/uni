#include <iostream>
using namespace std;
void f(int a) {
  int m=0;
  cout << "n m p\n";
  while (a--) {
    static int n=0;
    int p=0;
    cout << n++ << ' ' << m++ << ' ' << p++ << endl;
  }
}

int main(){
 f(3); f(2);
 system("pause"); return 0;
}