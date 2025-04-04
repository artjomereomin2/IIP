#include <iostream>
#include <set>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
    int c;
	cout << "¬ведите количество чисел: ";
	cin >> c;
	set<int> two, tre;
	cout << "¬ведите числа через пробел: ";
	for (int i = 0; i < c; i++)
	{
		int n;
		cin >> n;
		if (n > 9 and n < 100) {
			while (n != 0)
			{
				int k = n % 10;
				n = n / 10;
				two.insert(k);
			}
		} else if (n > 99 and n < 1000) {
			while (n != 0)
			{
				int k = n % 10;
				n = n / 10;
				tre.insert(k);
			}
		}
	}
	for (auto i = two.begin(); i != two.end(); i++)
	{
		if (tre.count(*i) != 0) {
			cout << *i << " ";
		}
	}
	cout << endl;
    return 0;
}