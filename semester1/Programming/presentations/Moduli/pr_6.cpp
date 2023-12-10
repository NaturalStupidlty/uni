//метод діхотомії для рівнянь f(x)=0
#include <iostream>
#include <cmath>
using namespace std;

double dicho(double, double, double (*pf)(double), double);
double kvadr(double);
double kub(double);

int main()
{
  const double eps = 0.00001;
  double a, b;
  cout << "Kvadr a="; cin >> a;
  cout << "Kvadr b="; cin >> b;
  cout << "Kvadr a=" << a << " b=" << b << " x="
       << dicho(a, b, kvadr, eps) << endl;
  cout << endl;

  cout << "Kub a="; cin >> a;
  cout << "Kub b="; cin >> b;
  cout << "Kub a=" << a << " b=" << b << " x="
       << dicho(a, b, kub, eps) << endl;

  system("pause"); return 0;
}
double dicho(double a, double b, double (*pf)(double x), double eps)
{
  double x, u, v, w;
  u = (*pf)(a);
  v = (*pf)(b);
  if (u * v > 0) {
    cout << "no solution on a=" << a << " b=" << b << endl;
	return a;
  }
  while ((fabs(b-a) > eps) && fabs(u) > eps){
        x = (a + b) / 2;
	w = (*pf)(x);
	if (u * w < 0) {
	  b = x;
	  v = w;
	}
	else {
	  a = x;
	  u = w;
	};
//	cout << "x=" << x << " f(x)=" << w << endl;
  }
  return a;
}
double kvadr(double x)
{
  return x*x + 2*x - 3;
}
double kub(double x)
{
  return x*x*x - 6*x*x + 11*x - 6;
}
