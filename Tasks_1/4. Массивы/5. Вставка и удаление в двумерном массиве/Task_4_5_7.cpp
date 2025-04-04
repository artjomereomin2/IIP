#include <iostream>

using namespace std;

int main7()
{
	int d;
	do {
		setlocale(LC_ALL, "Rus");
		// Инициализация матрицы
		int n;
		cout << "Введите размерность матрицы: ";
		cin >> n;
		int** m = new int* [n];
		for (int i = 0; i < n; i++) {
			m[i] = new int[2 * n];
		}
		// Ввод значений матрицы
		cout << "Введите эл-ты матрицы (через пробел, каждая строчка на отдельной строчке)\n";
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> m[i][j];
				// m[i][j] = rand() % 10;
			}
		}
		/*cout << "Матрица:\n";
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << m[i][j] << " ";
			}
			cout << endl;
		}*/

		// Изменение матрицы:
		// Поиск нечётных чисел в строках, если не нашлось ни 1, все столбцы после данного
		// сдвигаем на 1 и запоминаем это в счётчике
		int c = 0;
		bool is_chot = true;
		for (int j = 0; j < n + c; j++) {
			for (int i = 0; i < n; i++) {
				if (m[i][j] % 2 != 0) {
					is_chot = false;
					break;
				}
			}
			if (is_chot) {
				for (int i = 0; i < n; i++) {
					for (int j1 = n + c - 1; j1 >= j; j1--) {
						m[i][j1 + 1] = m[i][j1];
					}
				}
				j++;
				c++;
			}
			is_chot = true;
		}
		// Вывод изменённой матрицы
		cout << "Итоговая матрица:\n";
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n + c; j++) {
				cout << m[i][j] << " ";
			}
			cout << endl;
		}
		// Удаление матрицы и строки
		for (int i = 0; i < n; i++) {
			delete[]m[i];
		}
		delete[]m;
		cout << "Введите любое число для продолжения (кроме нуля): ";
		cin >> d;
	} while (d);
	return 0;
}