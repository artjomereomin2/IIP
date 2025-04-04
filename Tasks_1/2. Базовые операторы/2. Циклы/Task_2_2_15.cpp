#include <iostream>
#include <cmath>

using namespace std;
int main15()
{
	int n;
	do {
		setlocale(LC_ALL, "Rus");
		double a, b, h;
		cout << "Введите a, b и h (через пробел): ";
		cin >> a >> b >> h;
		for (double x = a; x <= b; x += h) {
			cout << x << " - ";
			double kor_otr = x - 3; // Значение под корнем
			double del_0 = 1 - sqrt(kor_otr); // Знаменатель
			double nepol_ln = x * x - 2*x + 1; // Значение под логарифмом
			if (nepol_ln < DBL_EPSILON) { // <= 0
				cout << "Логарифм из неположительного числа";
			}
			else if (kor_otr < 0) { // < 0
				cout << "Корень из отрицательного числа";
			}
			else if (abs(del_0) < DBL_EPSILON) {// == 0
				cout << "Деление на ноль";
			}
			else {
				double F = log(nepol_ln) / del_0; // Значение выражения
				cout << F;
			}
			cout << endl;
		}
		cout << endl << "Введите любое число для продолжения (кроме нуля): ";
		cin >> n;
	} while (n);
	return 0;
}