#include <iostream>
#include <string>

using namespace std;
int main3()
{
	int n;
	do {
		setlocale(LC_ALL, "Rus");
		int a, x, y;
		cout << "Введите A: ";
		cin >> a;
		cout << "Введите Х: ";
		cin >> x;
		cout << "Введите Y: ";
		cin >> y;
		int s = a / 10 + a % 10; // Сумма последних 2 цифр а
		int f = a / 10; // Первая цифра а
		if ((a / 10 == 0) or (a / 100 != 0) or (x / 10 != 0) or (y / 10 != 0)) { // Проверка, является ли а однозначным или трёх- и более значным, и являются ли х и у неоднозначными
			string a1 = "некорректный ввод";
			cout << a1;
		}
		else if (s % x == 0) {
			if (f < y) {
				int a1 = abs(f - 5) * 10 + abs(a % 10 - 5);
				cout << a1;
			}
			else if (f > y) {
				int a1 = (f + 5) % 10 * 10 + (a % 10 + 5) % 10;
				cout << a1;
			}
			else {
				int a1 = (f + 2) % 10 * 10 + (a % 10 + 2) % 10;
				cout << a1;
			}
		}
		else if (s % x) {
			if (f < y) {
				int a1 = abs(f - 4) * 10 + abs(a % 10 - 4);
				cout << a1;
			}
			else if (f > y) {
				int a1 = (f + 4) % 10 * 10 + (a % 10 + 4) % 10;
				cout << a1;
			}
			else {
				int a1 = (f + 2) % 10 * 10 + (a % 10 + 2) % 10;
				cout << a1;
			}
		}
		cout << endl << "Введите любое число для продолжения (кроме нуля): ";
		cin >> n;
	} while (n);
	return 0;
}