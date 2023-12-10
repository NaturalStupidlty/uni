//Цикл з параметром
#include <iostream>
int main()
{
	int i = 1, n = 0;
	long int fact = 1;
	std::cout << "n = ";
	std::cin >> n;
	std::cout << std::endl;
	
	for(i=1; i <= n; i++) fact *= i;
	
	std::cout << "n! = " << fact << std::endl;
	std::cin.ignore(200,'\n').get();
	return 0;
}