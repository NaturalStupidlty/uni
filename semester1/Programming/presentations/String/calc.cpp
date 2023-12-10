//простий калькулятор
#include <iostream>
#include <cstring>
using namespace std;

double atoff(char s[]){
 double val, pw;
 int i, sign;
 //пропуск порожніх символів
 for (i = 0; s[i] == ' ' || s[i] == '\n'|| s[i] == '\t'; i++);
 //знак числа
 sign = 1;
 if (s[i] == '+'||s[i] == '-') sign = (s[i++] =='+')? 1 : -1;
 //ціла частина
 for(val = 0; s[i] >= '0' && s[i] <= '9'; i++)
   val = 10 * val + s[i] - '0';
 if (s[i] == '.') i++;
 //дробова частина
 for (pw = 1; s[i] >= '0' && s[i] <= '9'; i++){
   val = 10 * val + s[i] - '0';
   pw *= 10;
   }
 return sign * val / pw;
}

int main(){
 const int l = 20;
 double sum = 0;
 char str[l], ch = 'Y';

 while (ch == 'Y'){
    cout << "number: ";
    cin >> str;
    cout << endl;
    cout << "SUM= " << (sum += atoff(str)) << endl;
    cout << "Continue  Y / N  :  ";
    cin >>ch;
    cout << endl;
 }
 system("pause");
 return 0;
}
