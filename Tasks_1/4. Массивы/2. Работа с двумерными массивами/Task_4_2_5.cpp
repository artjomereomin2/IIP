#include <iostream>

using namespace std;

int main5()
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
		// 1) Поиск номера строки с максимальной суммой
		int sm = -1, i_sm = -1;
		for (int i = 0; i < n; i++) {
			int s = 0;
			for (int j = 0; j < n; j++) {
				s += m[i][j];
			}
			if (s > sm) {
				i_sm = i;
				sm = s;
			}
		}
		// 2) Перестановка искомой и первой строк (обмен указателей)
		int* d;
		d = m[0];
		m[0] = m[i_sm];
		m[i_sm] = d;
		// Вывод изменённой матрицы
		cout << "Итоговая матрица:\n";
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n;j++) {
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