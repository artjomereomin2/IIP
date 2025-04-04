#include <iostream>

using namespace std;

int main2()
{
	int d;
	do {
		setlocale(LC_ALL, "Rus");
		// Инициализация маcсива
		int n;
		cout << "Введите n: ";
		cin >> n;
		int* m = new int[n];
		// Ввод эл-ов массива и Х
		cout << "Введите элементы массива:" << endl;
		for (int i = 0; i < (n); i++) {
			cin >> m[i];
		}
		int x;
		cout << "Введите Х: ";
		cin >> x;
		// Изменение массива (при нахождении необходимого эл-та сдвигаем
		// все эл-ты до него на 1 вперёд и запоминаем в счётчике этот сдвиг
		int c = 0;
		for (int i = 0; i < n; i++) {
			if (m[i] == x) {
				for (int j = i - 1; j>=0; j--) {
					m[j + 1] = m[j];
				}
				c++;
			}
		}
		// Вывод изменённого массива
		cout << "Массив без х:\n";
		for (int i = c; i < n - 1; i++) {
			cout << m[i] << ", ";
		}
		cout << m[n - 1] << endl;
		// Удаление массива
		delete[]m;

		cout << "Введите любое число для продолжения (кроме нуля): ";
		cin >> d;
	} while (d);
	return 0;
}