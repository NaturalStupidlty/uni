#include <iostream>
using namespace std;

void outReverse()
{ int n;
  cin >> n;
  if(n==0) return;   // ������� 0 � ����������
  outReverse();      // ������� �� 0 � �����������
  // ���� ���������� � ������������ �������
  cout << n << " "; 
  return;
}

int main(){
  cout << "Enter some integers, tha last should be 0\n"; 
  outReverse();
  cout<<endl;
  system("pause"); return 0;
}
