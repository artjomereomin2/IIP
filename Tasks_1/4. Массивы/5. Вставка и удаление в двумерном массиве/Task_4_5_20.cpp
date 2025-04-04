#include <iostream>

using namespace std;

int main()
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
			m[i] = new int[n];
		}
		// Ввод значений матрицы и Х
		cout << "Введите эл-ты матрицы (через пробел, каждая строчка на отдельной строчке)\n";
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				// cin >> m[i][j];
				m[i][j] = rand() % 90 + 10;
			}
		}
		cout << "Матрица:\n";
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << m[i][j] << " ";
			}
			cout << endl;
		}
		int x;
		cout << "Введите Х: ";
		cin >> x;
		// Изменение матрицы:
		// Поиск чисел, оканчивающихся на Х в столбцах, если не нашлось ни 1, все столбцы до данного
		// сдвигаем на 1 и запоминаем это в счётчике
		int c = 0;
		bool is_x = false;
		for (int j = 0; j < n; j++) {
			for (int i = 0; i < n; i++) {
				if (m[i][j] % 10 == x) {
					is_x = true;
					break;
				}
			}
			if (is_x) {
				for (int i = 0; i < n; i++) {
					for (int j1 = j - 1; j1 >= 0; j1--) {
						m[i][j1 + 1] = m[i][j1];
					}
				}
				c++;
				is_x = false;
			}
		}
		// Вывод изменённой матрицы
		cout << "Итоговая матрица:\n";
		for (int i = 0; i < n; i++) {
			for (int j = c; j < n; j++) {
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