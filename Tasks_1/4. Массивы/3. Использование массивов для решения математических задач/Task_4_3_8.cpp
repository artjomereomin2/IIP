#include <iostream>

using namespace std;

int main8()
{
	int x;
	do {
		setlocale(LC_ALL, "Rus");
		// Инициализация маcсивов
		int n;
		cout << "Введите n: ";
		cin >> n;
		int* p = new int[n + 1];
		int* p1 = new int[n];
		int* p_x_p1 = new int[2 * n];
		// Ввод коэффициентов
		cout << "Введите коэффициенты многочлена:" << endl;
		for (int i = 0; i < (n + 1); i++) {
			cin >> p[i];
		}
		for (int i = 0; i < 2 * n; i++) {
			p_x_p1[i] = 0;
		}
		// Заполнение 2-го массива (производная от многочлена)
		for (int i = 1; i < (n + 1); i++) {
			p1[i - 1] = p[i] * i;
		}
		// Заполнение 3-го массива (перемножение 2 многочленов)
		for (int i = 0; i < 2 * n; i++) {
			if (i < n) {
				for (int j = 0; j <= i; j++) {
					p_x_p1[i] += p[j] * p1[i - j];
				}
			}
			else {
				for (int j = i - n; j <= i and j < n; j++) {
					p_x_p1[i] += p1[j] * p[i - j];
				}
			}
		}
		// Вывод 3-го массива
		cout << "Коэффициенты произведения многочлена и его производной:\n";
		for (int i = 0; i < 2 * n - 1; i++) {
			cout << p_x_p1[i] << ", ";
		}
		cout << p_x_p1[2 * n - 1] << endl;
		// Удаление массивов
		delete[]p;
		delete[]p1;
		delete[]p_x_p1;

		cout << "Введите любое число для продолжения (кроме нуля): ";
		cin >> x;
	} while (x);
	return 0;
}