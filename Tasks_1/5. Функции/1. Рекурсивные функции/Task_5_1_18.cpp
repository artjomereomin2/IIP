#include <iostream>

using namespace std;

// Рекурсивная функция
int strings(int n, int z, char start) {
	int i, c = 1;
	if (z < n) { i = z; }
	else if (z <= n * 2) { i = n - (z - n); c -= 2; }
	else { return 0; }

	for (int j = 0; j <= (n - i); j++) cout << ' ';
	for (int j = 0; j <= i; j++) cout << start;
	for (int j = 0; j < n - i; j++) cout << '-';
	for (int j = 0; j < i * 2 + 1; j++) cout << start;
	for (int j = 0; j < n - i; j++) cout << '-';
	for (int j = 0; j <= i; j++) cout << start;
	cout << endl;
	return strings(n, z + 1, start + c); // Рекурентное выражение 
}

int main()
{
	int x;
	do {
		setlocale(LC_ALL, "Rus");
		// Объявление n, их ввод и вывод результата
		int n;
		char char_start = 'A';
		cout << "Введите количество чёрточек между А(В примере их 6): ";
		cin >> n;
		cout << "Итоговые строки:\n";
		strings(n, 0, char_start);
		cout << "Введите любое число для продолжения (кроме нуля): ";
		cin >> x;
	} while (x);
	return 0;
}