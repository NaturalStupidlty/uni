                                // Лабораторна робота № 1
		//Тема: властивості натуральних чисел (використання основних структур управління, стандартних типів та операцій)
        //Задача: вводиться натуральне число N; m<N; Знайти числа m, сума цифр десяткового представлення яких є простим числом. 
#include <iostream> // Підключення стандартної бібліотеки
#include <cmath> // Підключення бібліотеки з математичними функціями
using namespace std; // Вказуємо простір імен

int main () {
    cout << "Enter N: \n"; // Просимо ввести число "N"
    long int N; // Ініціалізуємо змінну "N"
    cin >> N; // Вводиться число "N"
    bool pr = true; // Ініціалізуємо змінну з логічним типом данних "pr"
    long int summ = 0; // Ініціалізуємо змінну "summ", яка буде зберігати суму цифр числа
    for (int number = 1; number < N; number++, summ = 0, pr = true) { // Цикл, який перебирає всі числа від 1 до N
        int digit = number; // Ініціалізуємо змінну "digit", яка буде приймати значення змінної "number" і використовуватися для виділення останньої цифри числа
        while (digit > 0) { // Цикл, який знаходить і додає усі цифри числа
            summ += digit % 10;
            digit /= 10;
        }
        int root = sqrt(summ); // Ініціалізуємо змінну, яка буде зберігати значення квадратного кореня змінної "summ"
        int i = 2; // Ініціалізуємо змінну "і", яка буде використовуватися для перевірки числа на простоту в наступному циклі
        while ((i <= root) && pr){ // Цикл, який перевіряє, чи є сума цифр числа прости числом
            if (summ % i) // Якщо сумма цифр націло ділить на "і", тоді вона не є простим числом
                pr = false; // За цієї умови, змінна "pr" змінює своє значення
            i++;
        }
        if (pr) // У випадку, коли сума цифр числа це просте число, ми виводимо його на екран
            cout << number << " "; // Виведення числа на екран
    }
    return 0;
}

// Роботу виконав студент 1 курсу ПІ-11 Ольховатий Ігор Васильович