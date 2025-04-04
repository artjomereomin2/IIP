#include <iostream>
#include <cmath>

using namespace std;
int main9()
{
	int n;
	do {
		setlocale(LC_ALL, "Rus");
		double x;
		cout << "Введите х: ";
		cin >> x;
		double del_0 = x * x - 9; // Знаменатель
		double kor_otr = (x - 5) / del_0; // Значение под корнем
		double nepol_ln = x * x + x * 2 + 1; // Значение под логарифмом
		if (abs(del_0) < DBL_EPSILON) {// == 0
			cout << "Деление на ноль";
		}
		else if (kor_otr < 0) { // < 0
			cout << "Корень из отрицательного числа";
		}
		else if (nepol_ln < DBL_EPSILON) { // <= 0
			cout << "Логарифм из неположительного числа";
		}
		else {
			double F = sqrt(kor_otr) + log(nepol_ln); // Значение выражения
			cout << F;
		}
		cout << endl << "Введите любое число для продолжения (кроме нуля): ";
		cin >> n;
	} while (n);
	return 0;
}