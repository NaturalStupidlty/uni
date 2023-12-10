//злиття двох впорядкованих масивів
#include <iostream>
using namespace std;
const int l=5;
double merge(int n, double a[l], double b[l], double c[2*l])
{
    int i, j, k;
    i=j=k=0;
    while (i<n && j<n)
    if (a[i]<b[j]) c[k++]=a[i++];
    else c[k++]=b[j++];
    while(i<n) c[k++]=a[i++];
    while(j<n) c[k++]=b[j++];
}

int main(){
 double aa[l];
 double bb[l];
 double cc[2*l];
//введення першого масиву
 cout << "array A: ";
 for (int i=0; i<l; i++)
   cin >> aa[i];
 cout << endl;
//введення другого масиву
 cout << "array B: ";
 for (int i=0; i<l; i++)
   cin >> bb[i];
 cout << endl;
//злиття
 merge(l, aa, bb, cc);
 //виведення даних
 cout << "array C: ";
 for (int i=0; i<2*l; i++)  cout << cc[i] << "  " ;
 system("pause");
 return 0;
}