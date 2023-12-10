//програма, що обчислює значення простого арифметичного виразу
//на вході дійсне число, знак операції, дійсне число
//контроль на правильністіь введення дійсних чисел відсутній
#include <iostream>
using namespace std;
int main(){
  double op1, op2, res; char sign; int state=0;
  cout << "Enter double, operator (+,-,*,/), and double\n"; 
  cin >> op1 >> sign >> op2;
// обчислення
  switch (sign)  {
    case '+' : res=op1+op2; break;
    case '-' : res=op1-op2; break;
    case '*' : res=op1*op2; break;
    case '/' : if (op2 != 0) res=op1/op2; else state=1; break;
    default : state=2;
  }	
// повідомлення результату  
  switch (state)  { 
  case 0 : cout << "===\n" << res<<endl; break;
  case 1 : cout << "Division by zero/n"; break;
  default : cout << "Wrong operator\n";	
  }
 system("pause"); return 0;
}
