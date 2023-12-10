#include <iostream>
#include "prefix2.h"
#include "prefix10.h"
using namespace std;
int main(){
	cout << metric::kilo(1) << " " << metric::mega(1) << endl;
	cout << binary::kilo(1) << " " << binary::mega(1) << endl;
	system("pause"); return 0;
}
