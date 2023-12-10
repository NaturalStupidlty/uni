//масив покажчиків на функції
#include <iostream>
using namespace std;
void func1(int);
void func2(int);
void func3(int);

int main()
{
  void (*f[3])(int) = {func1, func2, func3};
  int choice;
  cout << "type number 0 - 2, finish - 3 :";
  cin >> choice;
  while (choice >= 0 && choice < 3) {
    (*f[choice])(choice);
	cout << "type number 0 - 2, finish - 3 :";
    cin >> choice;
  }
  cout << "You type 3 => finish" << endl;
  system("pause"); return 0;
}

void func1(int a)
{ cout << "You type " << a << " => function1" << endl << endl;
}

void func2(int a)
{ cout << "You type " << a << " => function2" << endl << endl;
}

void func3(int a)
{ cout << "You type " << a << " => function3" << endl << endl;
}
