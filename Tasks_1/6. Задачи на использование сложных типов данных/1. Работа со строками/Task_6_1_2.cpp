#include <iostream>
#include <string>

using namespace std;

int main22()
{
	int x;
	do {
		setlocale(LC_ALL, "Rus");
		string str, prep = ".,?!:; ";
		cout << "¬ведитее строку: \n";
		getline(cin, str);
		char l;
		cout << "¬ведите букву: ";
		cin >> l;
		int i = 0, j = 0, z = 0;
		str = " " + str + " ";
		while (true) {
			i = str.find_first_of(prep, z);
			if (i == string::npos) break;
			j = str.find_first_not_of(prep, i);
			if (j == string::npos) break;
			if (str[j] == l) {
				z = str.find_first_of(prep, j);
				if (z == string::npos) break;
				str = str.substr(0, z) + ':' + str.substr(z);
			}
			else z = j;
		}
		cout << str.substr(1, str.length() - 1) << endl;
		cout << "¬ведите любое число дл€ продолжени€ (кроме нул€): ";
		cin >> x;
		cin.get();
	} while (x);
	return 0;
}// Ty Me turokm NMKIjf? Of corsr.