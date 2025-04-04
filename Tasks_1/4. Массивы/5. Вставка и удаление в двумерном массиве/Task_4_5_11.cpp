#include <iostream>

using namespace std;

int main11()
{
	int d;
	do {
		setlocale(LC_ALL, "Rus");
		// Инициализация матрицы и строки
		int n;
		cout << "Введите размерность матрицы: ";
		cin >> n;
		int** m = new int* [n];
		for (int i = 0; i < n; i++) {
			m[i] = new int[n];
		}
		// Ввод значений матрицы
		// cout << "Введите эл-ты матрицы (через пробел, каждая строчка на отдельной строчке)\n";
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				// cin >> m[i][j];
				m[i][j] = rand() % 10;
			}
		}
		cout << "Матрица:\n";
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << m[i][j] << " ";
			}
			cout << endl;
		}
		// Изменение матрицы:
		// 1) Поиск значения минимума
		int mi = INT_MAX;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (m[i][j] < mi) {
					mi = m[i][j];
				}
			}
		}
		// 2) Поиск минимума в строках, если нашёлся хоть 1 все строки до данной
		// сдвигаем на 1 и запоминаем это в счётчике
		int c = 0;
		bool is_min = false;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (m[i][j] == mi) {
					is_min = true;
					break;
				}
			}
			if (is_min) {
				for (int j = i - 1; j >= 0; j--) {
					m[j + 1] = m[j];
				}
				c++;
				is_min = false;
			}
		}
		// Вывод изменённой матрицы
		cout << "Итоговая матрица:\n";
		for (int i = c; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << m[i][j] << " ";
			}
			cout << endl;
		}
		// Удаление матрицы
		for (int i = c; i < n; i++) {
			delete[]m[i];
		}
		delete[]m[0];
		delete[]m;
		cout << "Введите любое число для продолжения (кроме нуля): ";
		cin >> d;
	} while (d);
	return 0;
}