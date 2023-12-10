#include <iostream>
using namespace std;

int main(){
 int ind1, ind2;
cout << "Size n*m :";
cin >> ind1 >> ind2;

//виділення пам`яті
int **a = new int *[ind1];
for (int i = 0; i < ind1; i++)
  a[i] = new int[ind2];

//введення даних
 cout << "array A: "<< endl;
 for (int i=0; i<ind1; i++)
  for (int j=0; j<ind2; j++)
   cin >> a[i][j];
 cout << endl;

 //виведення даних
 cout << "array A: "<< endl;
 for (int i=0; i<ind1; i++){
  for (int j=0; j<ind2; j++)
  cout << a[i][j] << "  " ;
  cout << endl;
 }
//звільнення пам`яті 
for (int i = 0; i < ind1; i++)
   delete [] a[i] ;
 delete [] a;
 a = 0;
 system("pause");
 return 0;
}