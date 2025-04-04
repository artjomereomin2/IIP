#include <iostream>

using namespace std;

int main20()
{
	int x;
	do {
		setlocale(LC_ALL, "Rus");
		int n;
		cout << "¬ведите количество строчек: ";
		cin >> n;
		for (int i = 0; i < n; i++) {
			if (i % 2) {
				for (int j = 0; j < ((i / 2) + 1); j++) {
					cout << 3 * (i / 2) << " ";
				}
			}
			else {
				for (int j = i + 2; j > 0; j-= 2) {
					cout << j << " ";
				}
			}
			cout << endl;
		}
		cout << endl << "¬ведите любое число дл€ продолжени€ (кроме нул€): ";
		cin >> x;
	} while (x);
	return 0;
}