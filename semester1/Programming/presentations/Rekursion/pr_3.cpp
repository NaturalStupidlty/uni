#include <iostream>
using namespace std;

char digit(int v) // цифра за значенням v
//pre: 0<=v<=35
{ if(v<10) return char(int('0')+v);
  else return char(int('A')+v-10);
}

void outNP(int n, int p)
// виведення p-кових цифр числа n
//pre: n>=0 && p>=2
{ if(n >= p) outNP(n/p, p); // заглиблення 
  cout << digit(n%p);     // виводиться остання цифра
  return; 
}

int main()
{ int n, p;
  cout <<"Enter one nonnegative integer and \n"
	   <<"one integer between 2 and 36 >"; 
  cin >> n >> p;
  if (n>=0 && 2<=p && p<=36) outNP(n,p);  
  else cout<<"You enter wrong numbers";
  cout<<endl; 
  system("pause");
  return 0;
}
