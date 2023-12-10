#include <iostream>
using namespace std;

int main(){
 int n;
 int *p = 0, *q = 0;
 cout << "n= ";
 cin >> n;
 cout << endl;
 p = new int [n];
 q = p;
 cout << "array A: ";
 for (int i=0; i<n; i++)
   cin >> *q++;
 cout << endl;
 q = p;
 //виведення даних
 cout << "array A: ";
 for (int i=0; i<n; i++)  cout << *q++ << "  " ;
 delete [] p;
 system("pause");
 p = 0;return 0;
}