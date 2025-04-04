#include <iostream>

using namespace std;

double eps = 0.000001;

class Treangle {
private:
	double x1, y1, x2, y2, x3, y3;
public:
	Treangle(double xone, double yone, double xtwo, double ytwo, double xtre, double ytre) {
		x1 = xone;
		x2 = xtwo;
		x3 = xtre;
		y1 = yone;
		y2 = ytwo;
		y3 = ytre;
	}
	bool is_in(double x, double y) {
		// 1-2
		double k = (y1 - y2) / (x1 - x2);
		double b = y1 - k * x1;
		if (y3 - k * x3 + b > eps) {
			if (y - k * x + b < eps) {
				return false;
			}
		}
		else if (y3 - k * x3 + b < eps * -1) {
			if (y - k * x + b > eps * -1) {
				return false;
			}
		}
		// 2-3
		k = (y2 - y3) * 1.0 / (x2 - x3);
		b = y2 - k * x2;
		if (y1 - k * x1 + b > eps) {
			if (y - k * x + b < eps) {
				return false;
			}
		}
		else if (y1 - k * x1 + b < eps * -1) {
			if (y - k * x + b > eps * -1) {
				return false;
			}
		}
		// 3-1
		k = (y3 - y1) * 1.0 / (x3 - x1);
		b = y1 - k * x1;
		if (y2 - k * x2 + b > eps) {
			if (y - k * x + b < eps) {
				return false;
			}
		}
		else if (y2 - k * x2 + b < eps * -1) {
			if (y - k * x + b > eps * -1) {
				return false;
			}
		}
		return true;
	}
};

int main2()
{
	int x;
	do {
		setlocale(LC_ALL, "Rus");
		double x1, y1, x2, y2, x3, y3;
		cout << "Введите координаты вершин треугольника (каждая точка на отдельной строке)" << endl;
		cin >> x1 >> y1;
		cin >> x2 >> y2;
		cin >> x3 >> y3;
		double l1 = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
		double l2 = sqrt((x2 - x3) * (x2 - x3) + (y2 - y3) * (y2 - y3));
		double l3 = sqrt((x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1));
		if (-1 * (max(max(l1, l2), l3) - (l1 + l2 + l3 - max(max(l1, l2), l3))) > eps) {
			Treangle treang(x1, y1, x2, y2, x3, y3);
			cout << "Введите количество проверяемых точек: ";
			int n;
			cin >> n;
			cout << "Введите точки (каждая на отдельной строке)\n";
			double* dot = new double[2 * n];
			double x, y;
			for (int i = 0; i < n; i++) {
				dot[2 * i] = dot[2 * i + 1] = DBL_MAX;
				cin >> x >> y;
				if (treang.is_in(x, y)) {
					dot[i] = x;
					dot[i + 1] = y;
				}
			}
			int c = 0;
			cout << "Точек внутри треугольника: ";
			for (int i = 0; i < n; i++) {
				if (dot[2 * i] != DBL_MAX) {
					c += 1;
				}
			}
			cout << c << endl;
		}
		else {
			cout << "Треугольник вырожденный\n";
		}
		cout << "Введите любое число для продолжения (кроме нуля): ";
		cin >> x;
	} while (x);
	return 0;
}