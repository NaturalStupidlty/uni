//��������, �� ����'��� ������� ax+b=0
#include <iostream>
using namespace std;
int main(){
double a=0, b=0;
int n;    //������� ����'���� ������� ax+b=0; -1 ������� "���������� ������"
double x; //����'���� �������
//��������� ������� �����
cout<<"Enter coefficients a and b of equation ax+b=0 (2 reals)\n";
cin>>a>>b;
//������� �������� �����
if (a!=0) n=1;
else if (b==0) n=-1;
else n=0;
if (n==1) x=(-b)/a;
//����������� ����������
//cout<<"Equation "<<a<<"x"<<showpos<<b<<noshowpos<<"=0 ";
cout<<"Equation "<<a<<"x";
if (b>0) cout<< "+" << b;
else cout<< b; 
cout << "=0 ";
if (n==1) cout<<"has one solution "<<x<<endl;
else if (n==0) cout<<"has no solution\n";
else cout<<"has infinitely many solutions (each real is a solution)\n";
system("pause"); return 0;
}

