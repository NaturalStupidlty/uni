#include <iostream>
using namespace std;

void outReverse()
{ int n;
  cin >> n;
  if(n==0) return;   // введено 0 Ц поверненн€
  outReverse();      // введено не 0 Ц заглибленн€
  // п≥сл€ поверненн€ з рекурсивного виклику
  cout << n << " "; 
  return;
}

int main(){
  cout << "Enter some integers, tha last should be 0\n"; 
  outReverse();
  cout<<endl;
  system("pause"); return 0;
}
