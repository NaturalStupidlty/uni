//���������� �������
#include <iostream>
using namespace std;
int main(){
 const int n = 20;
 int b[n];
 int i;

 for (i=0; i<n; i++) cin >> b[i]; //�������� �����
 //����������
 for (i=0; i<n; i++){
   int imin = i;
   for (int j=i+1; j<n; j++) //������ ����� ����������
      if (b[j] < b[imin]) imin = j;
   int a = b[i]; //���� ����������
   b[i] = b[imin];
   b[imin] = a;
 }
 //��������� �����
 for (i=0; i<n; i++)  cout << b[i] << "  " ;

 system("pause");
 return 0;
}

//����������?
//������ ���������� ?