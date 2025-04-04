#include <iostream>

using namespace std;

// Рекурсивная функция
int binon_coef(int n, int m) {
	if (n == 0 or n == m) { // Условие выхода
		return 1;
	}
	return binon_coef(n - 1, m - 1) + binon_coef(n, m - 1); // Рекурентное выражение 
}

// Нерекурсивная функция
int factorial(int n) {
	int f = 1;
	for (int i = n; i > 0; i--) {
		f *= i;
	}
	return f;
}

int main9()
{
	int x;
	do {
		setlocale(LC_ALL, "Rus");
		// Объявление n и m, их ввод и вывод результата
		int n, m;
		cout << "Введите n и m через пробел: ";
		cin >> n >> m;
		cout << "Биномиальный коэффициент для n = " << n << " и m = " << m << " = " << binon_coef(n, m) << endl;
		
		// Вычисление нерекурсивным способом
		long double c = factorial(m) * 1.0 / (factorial(n) * factorial(m - n));
		if (m == n) {
			c = 1;
		}
		
		// Вывод кол-ва сочетаний
		cout << "Нерекурсивный биномиальный коэффициент для n = " << n << " и m = " << m << " = " << c;
		
		cout << "\nВведите любое число для продолжения (кроме нуля): ";
		cin >> x;
	} while (x);
	return 0;
}