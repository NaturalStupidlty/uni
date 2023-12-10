#include <iostream>
using namespace std;

//злиття двох впорядкованих масивів
#include <iostream>
using namespace std;

int main(){
 const int n=5;
 double a[n];
 double b[n];
 double c[2*n];
//введення першого масиву
 cout << "array A[5]: ";
 for (int i=0; i<n; i++)
   cin >> a[i];
 cout << endl;
//введення другого масиву
 cout << "array B[5]: ";
 for (int i=0; i<n; i++)
   cin >> b[i];
 cout << endl;
//злиття
 int i, j, k;
    i=j=k=0;
    while (i<n && j<n)
    if (a[i]<b[j]) c[k++]=a[i++];
    else c[k++]=b[j++];
    while(i<n) c[k++]=a[i++];
    while(j<n) c[k++]=b[j++];
 //виведення результату
 cout << "array C[10]: ";
 for (int i=0; i<2*n; i++)  cout << c[i] << "  " ;
 system("pause");
 return 0;
}
}