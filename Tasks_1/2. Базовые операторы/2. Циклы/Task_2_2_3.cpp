#include <iostream>

using namespace std;

int main()
{
	int x;
	do {
		setlocale(LC_ALL, "Rus");
		double y1 = 0.9, y2 = 1.1, yn;
		int n;
		cout << "¬ведите N: ";
		cin >> n;
		if (n >= 1) {
			cout << 1 << ": " << y1 << endl;
		}
		if (n >= 2) {
			cout << 2 << ": " << y2 << endl;
		}
		for (int i = 3; i <= n; i++) {
			yn = (1.0 / i) * y2 + (1.0 / (i * i)) * y1;
			cout << i << ": " << yn << endl;
			y1 = y2;
			y2 = yn;
		}
		cout << endl << "¬ведите любое число дл€ продолжени€ (кроме нул€): ";
		cin >> x;
	} while (x);
	return 0;
}