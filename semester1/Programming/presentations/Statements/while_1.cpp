//знаходження дільників натурального число
#include <iostream>
using namespace std;
int main(){
  int num;
  cout << "Enter number:\n"; 
  cin >> num;
  int half = num /2;  //половина числа
  int div = 2;   //кандидат на дільник
  while (div <= half)
   {
   	if (!(num % div))
   		cout << div << endl;  //знайшли дільник
   	div++;
   }
   system("pause"); 
   return 0;
}