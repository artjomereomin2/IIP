#include <iostream>

using namespace std;

int main15()
{
	int d;
	do {
		setlocale(LC_ALL, "Rus");
		// Инициализация маcсива
		int n;
		cout << "Введите n: ";
		cin >> n;
		int* m = new int[2*n];
		// Ввод эл-ов массива и Х
		cout << "Введите элементы массива:" << endl;
		for (int i = 0; i < (n); i++) {
			cin >> m[i];
		}
		int x;
		cout << "Введите Х: ";
		cin >> x;
		// Изменение массива (при нахождении необходимого эл-та сдвигаем
		// все эл-ты после него на 1 вперёд и запоминаем в счётчике этот сдвиг
		int c = 0;
		for (int i = 0; i < n + c; i++) {
			if (m[i] == x) {
				for (int j = n + c - 1; j >= i; j--) {
					m[j + 1] = m[j];
				}
				c++;
				i++;
			}
		}
		// Вывод изменённого массива
		cout << "Массив c раздвоенными х:\n";
		for (int i = 0; i < n + c - 1; i++) {
			cout << m[i] << ", ";
		}
		cout << m[n + c - 1] << endl;
		// Удаление массива
		delete[]m;

		cout << "Введите любое число для продолжения (кроме нуля): ";
		cin >> d;
	} while (d);
	return 0;
}