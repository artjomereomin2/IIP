#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <limits>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	int c;
	cout << "������� ���������� ����� ��� �������� �������: ";
	cin >> c;
	vector <int> a;
	cout << "������� ����� ��� �������� �������: ";
	int d;
	for (int i = 0; i < c; i++) {
		cin >> d;
		a.push_back(d);
	}
	int maxx = *max_element(a.begin(), a.end());
	int X;
	cout << "������� X: ";
	cin >> X;
	replace_if(a.begin(), a.end(), [X](int i){return i % X == 0;}, maxx);

	for (auto i = a.begin(); i != a.end(); i++) {
		cout << *i << " ";
	}
	return 0;
}