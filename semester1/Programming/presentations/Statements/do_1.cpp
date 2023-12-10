//обчислення квадратного кореня дійсного числа X з заданою точністю Eps
//YN1 = (YN + X / YN) / 2

#include <iostream>
#include <cmath>
using namespace std;
int main(){
  double x, eps; //число та точність
  double yp, y = 1;  //попереднє та наступне наближення
  cout << "Enter number: ";
  cin >> x;
  cout << "Enter Eps: ";
  cin >> eps; cout endl;
  do {
  	yp = y;
  	y = (yp + x / yp) / 2;
  } while (fabs(y - yp)>= eps);
  cout << "root of number: " << y << endl;
  system("pause"); 
  return 0;
}