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
  if (sign=='+') res=op1+op2; 
  else if (sign=='-') res=op1-op2; 
  else if (sign=='*') res=op1*op2;
  else if (sign=='/') 
     if (op2!=0) res=op1/op2; else state=1;
  else state=2;

// повідомлення результату  
 if (state==0) cout << "===\n" << res<<endl;
 else if (state==1) cout << "Division by zero\n";
 else cout << "Wrong operator\n";
 system("pause"); return 0;
}
