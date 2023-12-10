#include <iostream>
#include <new>
using namespace std;

int main(){
 int n;
 int *p = 0, *q = 0;
 cout << "n= ";
 cin >> n;
 cout << endl;
 try{
  p = new int [n];
  }
  catch (bad_alloc err){
  cout << "ERROR" << endl;
  return (1);
  }
 q = p;
 cout << "array A: ";
 for (int i=0; i<n; i++)
   cin >> *q++;
 cout << endl;
 q = p;
 //виведення даних
 cout << "array A: ";
 for (int i=0; i<n; i++)  cout << *q++ << "  " ;
 delete [] p; p = 0;
 system("pause");
 return 0;
}