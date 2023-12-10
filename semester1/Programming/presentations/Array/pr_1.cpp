//сортування вибором
#include <iostream>
using namespace std;
int main(){
 const int n = 20;
 int b[n];
 int i;

 for (i=0; i<n; i++) cin >> b[i]; //введення даних
 //сортування
 for (i=0; i<n; i++){
   int imin = i;
   for (int j=i+1; j<n; j++) //шукаємо номер найменшого
      if (b[j] < b[imin]) imin = j;
   int a = b[i]; //обмін елементами
   b[i] = b[imin];
   b[imin] = a;
 }
 //виведення даних
 for (i=0; i<n; i++)  cout << b[i] << "  " ;

 system("pause");
 return 0;
}

//Зауваження?
//Можливі покращення ?