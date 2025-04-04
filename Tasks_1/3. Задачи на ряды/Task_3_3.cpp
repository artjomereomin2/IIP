#include <iostream>

using namespace std;

int main()
{
	int x;
	do {
		setlocale(LC_ALL, "Rus");
		int n;
		cout << "Введите n: ";
		cin >> n;
		double y1 = 0.9, y2 = 1.1, yn; // Объявляем первый, второй и n-ый член
		if (n > 0) {
			cout << "1: " << y1 << endl; // Выводим первый член
		}
		if (n > 1) {
			cout << "2: " << y2 << endl; // Выводим второй член
		}
		if (n > 2) {
			for (int i = 3; i <= n; i++) {
				yn = y2 / i + y1 / (i * i); // Вычисляем i-ый член
				cout << i << ": " << yn << endl; // Выводим i-ый член
				y1 = y2; // Изменение предыдущих значений
				y2 = yn;
			}
		}
		cout << endl << "Введите любое число для продолжения (кроме нуля): ";
		cin >> x;
	} while (x);
	return 0;
}