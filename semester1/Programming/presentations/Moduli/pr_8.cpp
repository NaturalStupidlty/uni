#include <iostream>
using namespace std;
int boxVol(int length=1, int width=1, int height=1)
{return length * width * height;}

int main() {
   cout << "V() = " << boxVol() << endl << endl
	<< "V(10) = " << boxVol(10) << endl << endl
	<< "V(10, 5) = " << boxVol(10, 5) << endl << endl
	<< "V(10, 5, 2) = " << boxVol(10, 5, 2) << endl;
system("pause"); return 0;
}