#include <iostream>

using namespace std;

int main4()
{
	int x;
	do {
		setlocale(LC_ALL, "Rus");
		int n;
		cout << "¬ведите N: ";
		cin >> n;
		cout << n << " = ";
		while (n % 2 == 0) {
			cout << 2;
			n /= 2;
			if (n != 1) {
				cout << " x ";
			}
		}
		int n1 = n;
		for (int i = 3; i <= n1 and n != 1; i += 2) {
			if (n % i == 0) {
				cout << i;
				n /= i;
				i -= 2;
				if (n != 1) {
					cout << " x ";
				}
			}
		}
		cout << endl << "¬ведите любое число дл€ продолжени€ (кроме нул€): ";
		cin >> x;
	} while (x);
	return 0;
}