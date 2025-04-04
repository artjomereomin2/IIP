#include <iostream>
#include <list>
#include <algorithm>
#include <numeric>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	int c1, c2, d;
	cout << "Введите количество чисел для создания вектора 1: ";
	cin >> c1;
	cout << "Введите количество чисел для создания вектора 2: ";
	cin >> c2;
	list <int> a1, a2, a;
	cout << "Введите числа для создания вектора 1: ";
	for (int i = 0; i < c1; i++) {
		cin >> d;
		a1.push_back(d);}
	cout << "Введите числа для создания вектора 2: ";
	for (int i = 0; i < c2; i++) {
		cin >> d;
		a2.push_back(d);
	}
	int maxx = *max_element(a2.begin(), a2.end());
	int X;
	cout << "Введите X: ";
	cin >> X;

	a1.remove_if([](int i){return i % 2 != 0;});
	for (auto i = a1.begin(); i != a1.end(); i++) {
		cout << *i << " ";
	}
	cout << endl;
	a1.sort();

	for (auto i = a1.begin(); i != a1.end(); i++) {
		cout << *i << " ";
	}
	cout << endl;

	replace_if(a2.begin(), a2.end(), [X](int i){return i % X == 0;}, maxx);
	for (auto i = a2.begin(); i != a2.end(); i++) {
		cout << *i << " ";
	}
	cout << endl;
	a2.sort();

	for (auto i = a2.begin(); i != a2.end(); i++) {
		cout << *i << " ";
	}
	cout << endl;

	a1.merge(a2);
	for (auto i = a1.begin(); i != a1.end(); i++) {
		cout << *i << " ";
	}
	cout << endl;

	cout << "Введите новый элемент в списке: ";
	cin >> d;
	a.push_back(d);
	a1.merge(a);

	for (auto i = a1.begin(); i != a1.end(); i++) {
		cout << *i << " ";
	}
	return 0;
}