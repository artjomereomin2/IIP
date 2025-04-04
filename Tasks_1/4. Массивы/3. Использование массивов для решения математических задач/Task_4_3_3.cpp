#include <iostream>

using namespace std;

int main()
{
	int x;
	do {
		setlocale(LC_ALL, "Rus");
		// Инициализация маcсива
		int n;
		cout << "Введите n: ";
		cin >> n;
		int* p = new int[n + 1];
		int* p1 = new int[n];
		int* p_p_p1 = new int[n + 1];
		// Ввод коэффициентов
		cout << "Введите коэффициенты многочлена:" << endl;
		for (int i = 0; i < (n + 1); i++) {
			cin >> p[i];
		}
		// Заполнение 2-го массива (на место i-го коэффициента записывается i-й коэффициент производной от многочлена, 0-й коэффициент удаляется
		for (int i = 1; i < (n + 1); i++) {
			p1[i - 1] = p[i] * i;
		}
		// Заполнение 3-го массива
		for (int i = 0; i < n; i++) {
			p_p_p1[i] = p[i] + p1[i];
		}
		p_p_p1[n] = p[n];
		// Вывод изменённого массива
		cout << "Коэффициенты:\n";
		for (int i = 0; i < n; i++) {
			cout << p_p_p1[i] << ", ";
		}
		cout << p_p_p1[n] << endl;
		// Удаление массива
		delete[]p;
		delete[]p1;
		delete[]p_p_p1;

		cout << "Введите любое число для продолжения (кроме нуля): ";
		cin >> x;
	} while (x);
	return 0;
}