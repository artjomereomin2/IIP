#include <iostream>

using namespace std;

int main8()
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
		// Ввод значений матрицы
		cout << "Введите эл-ты матрицы (через пробел, каждая строчка на отдельной строчке)\n";
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> m[i][j];
			}
		}
		// Изменение матрицы:
		// 1) Поиск номера строки с максимальным эл-ом
		int ma = INT_MIN, i_ma = -1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (m[i][j] > ma) {
					i_ma = i;
					ma = m[i][j];
				}
			}
		}
		// 2) Поиск номера строки с минимальным эл-ом
		int mi = INT_MAX, i_mi = -1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (m[i][j] < mi) {
					i_mi = i;
					mi = m[i][j];
				}
			}
		}
		// 3) Перестановка искомых строк (обмен указателей)
		int* d;
		d = m[i_mi];
		m[i_mi] = m[i_ma];
		m[i_ma] = d;
		// Вывод изменённой матрицы
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