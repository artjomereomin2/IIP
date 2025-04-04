#include <iostream>
#include <cmath>

using namespace std;

// Рекурсивная функция
double sqrt_rec(int n, int i) {
	if (i == n) { // Условие выхода
		return sqrt(1 + n);
	}
	return sqrt(1 + i * sqrt_rec(n, i + 1)); // Рекурентное выражение 
}

int main11()
{
	int x;
	do {
		setlocale(LC_ALL, "Rus");
		// Объявление n, его ввод и вывод результата
		int n;
		cout << "Введите n: ";
		cin >> n;
		cout << "Данный корень = " << sqrt_rec(n, 2);
		cout << "\nВведите любое число для продолжения (кроме нуля): ";
		cin >> x;
	} while (x);
	return 0;
}