#include <iostream>
using namespace std;

int main() {
 const int n = 4, m = 5; //розміри матриці
 int b[n][m];
 int i, j;
 cout << "array " << n << " * " << m << endl; 
 //введення матриці
 for (i = 0; i < n; i++)
  for (j = 0; j < m; j++) cin >> b[i][j];

 int inn = -1, maxnul = 0; //номер рядка та кількість 0

 for (i = 0; i < n; i++) {   //перегляд матриці рядками
  int kl = 0;    //кількість 0 у i-тому рядку
  for (j = 0; j < m; j++)   //перебір елементів у рядку
   if (b[i][j] == 0) kl++;
  if (kl > maxnul)
    {inn = i; maxnul = kl;}
 }
 if (maxnul == 0) cout << "absent" << endl;
 else cout << "n = " << (inn + 1) << " number = " << maxnul << endl;
 return 0;
} 