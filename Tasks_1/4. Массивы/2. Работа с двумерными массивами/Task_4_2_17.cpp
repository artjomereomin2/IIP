#include <iostream>

using namespace std;

int main17()
{
	int x;
	do {
		setlocale(LC_ALL, "Rus");
		// Инициализация матрицы
		int n;
		cout << "Введите размерность матрицы: ";
		cin >> n;
		int** m = new int* [n];
		for (int i = 0; i < n; i++) {
			m[i] = new int[n];
		}
		// Заполнение матрицы
		int c = n * n + ( - 1 + n) * (n % 2 == 1);
		for (int j = 0; j < n; j++) {
			c -= n;
			if (j % 2 == (n % 2 + 1) % 2) {
				for (int i = 0; i < n; i++, c--) {
					m[i][j] = c;
				}
				c++;
			}
			else {
				for (int i = 0; i < n; i++,c++) {
					m[i][j] = c;
				}
				c--;
			}
		}
		// Вывод матрицы
		cout << "Итоговая матрица:\n";
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << m[i][j] << " ";
			}
			cout << endl;
		}
		// Удаление матрицы
		for (int i = 0; i < n; i++) {
			delete[]m[i];
		}
		delete[]m;
		cout << "Введите любое число для продолжения (кроме нуля): ";
		cin >> x;
	} while (x);
	return 0;
}