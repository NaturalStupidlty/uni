#include <iostream>
using namespace std;
void f(int, int*, int&);
int main() {
int i=1, j=2, k=3;
 cout << "i j k\n";
 cout << i << ' ' << j << ' ' << k << endl;
 f(i, &j, k);
 cout << i << ' ' << j << ' ' << k << endl;
 system("pause");return 0;
}
void f(int i, int* j, int& k) {
 i++; (*j)++; k++;
}
