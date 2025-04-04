#include <iostream>

using namespace std;

// Рекурсивная функция
int factorial_2(int n) {
	if (n <= 2) { // Условие выхода
		return n;
	}
	return n * factorial_2(n - 2); // Рекурентное выражение 
}

int main2()
{
	int x;
	do {
		setlocale(LC_ALL, "Rus");
		// Объявление n, его ввод и вывод результата
		int n;
		cout << "Введите n: ";
		cin >> n;
		int f = 1;
		cout << "n!! = " << factorial_2(n);
		for (int i = n; i > 0; i -= 2) f *= i;
		cout << "\nНерекурсивный n!! = " << f;
		cout << "\nВведите любое число для продолжения (кроме нуля): ";
		cin >> x;
	} while (x);
	return 0;
}