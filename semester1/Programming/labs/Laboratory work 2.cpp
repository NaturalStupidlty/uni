						 // Лабораторна робота №2
				// Тема: робота з багаторозрядними змінними
		// Задача: вивести на екран число N!, для заданого N < 100.

#include <iostream>
using namespace std;

const char size = 10000;

int fact(int x, int array[], int array_size);
void factorial(int N);

int main()
{
	int N;
	cout << "Enter a number: \n";
	cin >> N;
	cout << "Factorial of " << N << " is: " << endl;
	factorial(N);
	return 0;
}

void factorial(int N)
{
	const char size = 1000;
	int array[size];
	array[0] = 1;
	int array_size = 1;

	for (int x = 2; x <= N; x++)
		array_size = fact(x, array, array_size);

	for (int i = array_size - 1; i >= 0; i--)
		cout << array[i];

	cout << endl;
}

int fact(int x, int array[], int array_size)
{
	int counter = 0;
	for (int i = 0; i < array_size; i++)
	{
		int number = array[i] * x + counter;
		array[i] = number % 10;
		counter = number / 10;
	}

	while (counter)
	{
		array[array_size] = counter % 10;
		counter /= 10;
		array_size++;
	}
	return array_size;
}

				// Виконав студент ПІ-11, Ольховатий Ігор 