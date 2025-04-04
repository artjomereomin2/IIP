#include <iostream>
#include <string>

using namespace std;

class oct_int {
private:
	string count;
public:
	void set_str_to_oct(string c) {
		if (is_oct(c)) {
			count = c;
		}
		else {
			cout << "Неверный формат числа";
		}
	}
	bool is_oct(string c) {
		if (c.find_first_not_of("-01234567") != string::npos) return false;
		if (c.find('-') != 0 and c.find('-') != string::npos) return false;
		return true;
	}
	string get_str() {
		return count;
	}
	void set_dec_to_oct(int c) {
		count = "";
		bool is_neg = false;
		if (c < 0) {
			is_neg = true;
			c *= -1;
		}
		while (c != 0) {
			count = to_string(c % 8) + count;
			c /= 8;
		}
		if (is_neg) count = '-' + count;
	}
	int get_oct_to_dec() {
		int r = 0;
		int c = stoi(count);
		int i = 0;
		while (c) {
			r += (c % 10) * pow(8, i);
			i++;
			c /= 10;
		}
		return r;
	}
	oct_int plus(oct_int oct1, oct_int oct2) {
		int int1 = oct1.get_oct_to_dec();
		int int2 = oct2.get_oct_to_dec();
		int int3 = int1 + int2;
		oct_int oct3;
		oct3.set_dec_to_oct(int3);
		return oct3;
	}
	oct_int minus(oct_int oct1, oct_int oct2) {
		int int1 = oct1.get_oct_to_dec();
		int int2 = oct2.get_oct_to_dec();
		int int3 = int1 - int2;
		oct_int oct3;
		oct3.set_dec_to_oct(int3);
		return oct3;
	}
	oct_int mult(oct_int oct1, oct_int oct2) {
		int int1 = oct1.get_oct_to_dec();
		int int2 = oct2.get_oct_to_dec();
		int int3 = int1 * int2;
		oct_int oct3;
		oct3.set_dec_to_oct(int3);
		return oct3;
	}
	pair <oct_int, oct_int> delit(oct_int oct1, oct_int oct2) {
		int int1 = oct1.get_oct_to_dec();
		int int2 = oct2.get_oct_to_dec();
		int int3 = int1 / int2;
		int ost = int1 % int2;
		oct_int oct3;
		oct3.set_dec_to_oct(int3);
		oct_int ost3;
		ost3.set_dec_to_oct(ost);
		pair <oct_int, oct_int> ret {oct3, ost3};
		return ret;
	}
};

oct_int set_str_to_oct(oct_int int1) {
	cout << "Введите число в системе счисления 8: "; // set_str_to_oct
	string c;
	getline(cin, c);
	int1.set_str_to_oct(c);
	return int1;
}

void get_oct(oct_int int1) {
	cout << "Число в восьмеричной системе счисления: "; // get_str
	string s1 = int1.get_str();
	cout << s1;
}

void dec_to_oct() {
	oct_int int1;
	cout << "Введите число в десятичной системе счисления: "; // set_dec_to_oct
	int ic;
	cin >> ic;
	cin.get();
	int1.set_dec_to_oct(ic);
	get_oct(int1);
}

void oct_to_dec() {
	oct_int int1;
	int1 = set_str_to_oct(int1);
	cout << "Число в десятичной системе счисления: "; // get_oct_to_dec
	int i1 = int1.get_oct_to_dec();
	cout << i1;
}

void oct_plus_oct() {
	oct_int int1, int2, int3;
	set_str_to_oct(int1);
	set_str_to_oct(int2);
	int3 = int3.plus(int1, int2);
	get_oct(int3);
}

void oct_minus_oct() {
	oct_int int1, int2, int3;
	set_str_to_oct(int1);
	set_str_to_oct(int2);
	int3 = int3.minus(int1, int2);
	get_oct(int3);
}

void oct_mult_oct() {
	oct_int int1, int2, int3;
	set_str_to_oct(int1);
	set_str_to_oct(int2);
	int3 = int3.mult(int1, int2);
	get_oct(int3);
}

void oct_delit_oct() {
	oct_int int1, int2;
	pair <oct_int, oct_int> int3;
	set_str_to_oct(int1);
	set_str_to_oct(int2);
	int3 = int1.delit(int1, int2);
	oct_int chast = int3.first;
	oct_int ost = int3.second;
	cout << "Частное и остаток в восьмеричной системе счисления:/n";
	cout << chast.get_str() << " " << ost.get_str();
}

int main3()
{
	int x;
	do {
		setlocale(LC_ALL, "Rus");
		cout << "Введите команду (dec_to_oct, oct_to_dec, plus, minus, mult, delit):\n";
		string command;
		getline(cin, command);
		if (command == "dec_to_oct") {
			dec_to_oct();
		}
		if (command == "oct_to_dec") {
			oct_to_dec();
		}
		if (command == "plus") {
			oct_plus_oct();
		}
		if (command == "minus") {
			oct_minus_oct();
		}
		if (command == "mult") {
			oct_mult_oct();
		}
		if (command == "delit") {
			oct_delit_oct();
		}
		cout << "\nВведите любое число для продолжения (кроме нуля): ";
		cin >> x;
	} while (x);
	return 0;
}