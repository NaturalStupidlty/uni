//����������� ������� ������������ �����
#include <iostream>
using namespace std;
int main(){
  int num;
  cout << "Enter number:\n"; 
  cin >> num;
  int half = num /2;  //�������� �����
  int div = 2;   //�������� �� ������
  while (div <= half)
   {
   	if (!(num % div))
   		cout << div << endl;  //������� ������
   	div++;
   }
   system("pause"); 
   return 0;
}