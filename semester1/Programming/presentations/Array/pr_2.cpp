#include <iostream>
using namespace std;

int main() {
 const int n = 4, m = 5; //������ �������
 int b[n][m];
 int i, j;
 cout << "array " << n << " * " << m << endl; 
 //�������� �������
 for (i = 0; i < n; i++)
  for (j = 0; j < m; j++) cin >> b[i][j];

 int inn = -1, maxnul = 0; //����� ����� �� ������� 0

 for (i = 0; i < n; i++) {   //�������� ������� �������
  int kl = 0;    //������� 0 � i-���� �����
  for (j = 0; j < m; j++)   //������ �������� � �����
   if (b[i][j] == 0) kl++;
  if (kl > maxnul)
    {inn = i; maxnul = kl;}
 }
 if (maxnul == 0) cout << "absent" << endl;
 else cout << "n = " << (inn + 1) << " number = " << maxnul << endl;
 return 0;
} 