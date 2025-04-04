#include <iostream>

using namespace std;

int main8()
{
	int x;
	do {
		setlocale(LC_ALL, "Rus");
		int n, d = 0, cv = 0;
		cout << "¬ведите N: ";
		cin >> n;
		cout << d << "*" << d << "=" << cv << endl;
		cv++;
		d++;
		for (int i = 1; d <= n; i += 2, d++, cv += i) {
			cout << d << "*" << d << "=" << cv << endl;
		}
		cout << endl << "¬ведите любое число дл€ продолжени€ (кроме нул€): ";
		cin >> x;
	} while (x);
	return 0;
}