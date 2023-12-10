#include <iostream>
using namespace std;
int max(int, int);      // два різних прототипи
int max(int, int, int); // однойменних функцій
int main()
{ int a, b, c;
  cout << "Enter three integers>";
  cin >> a >> b >> c;
  cout << max(a,b) << " " << max(a,b,c) << endl;
  system("pause"); return 0;
}
int max(int x, int y) // два параметри
{return x>y ? x : y;}
int max(int x, int y, int z) // три параметри
{int t=max(x,y); return t>z ? t : z;}
