#include <iostream>

using namespace std;

int main9()
{
	int x;
	do {
		setlocale(LC_ALL, "Rus");
		int n;
		bool iss = true;
		cout << "¬ведите N: ";
		cin >> n;
		for (int i = 1; iss; i++) {
			for (int j = i + 1; iss; j++) {
				if ((i * i + j * j) < n) {
					cout << i << "^2 + " << j << "^2 = " << i * i + j * j << endl;
				}
				else if (j == i + 1) {
					iss = false;
				}
				else {
					break;
				}
			}
		}
		cout << endl << "¬ведите любое число дл€ продолжени€ (кроме нул€): ";
		cin >> x;
	} while (x);
	return 0;
}