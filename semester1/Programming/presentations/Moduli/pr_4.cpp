#include <iostream>
typedef void (*PF)(int);
void f1(PF pf) {
  pf(5);
}
void f(int i) {
  cout << i;}
int main() {
  f1(f); return 0;
}