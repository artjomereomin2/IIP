#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <cmath>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");
    vector <vector <double>> a;
    int c;
    cout << "Введите количество точек: ";
    cin >> c;
    for (int i = 0; i < c; i++) {
        cout << "Введите координаты точки через пробел: ";
        vector <double> b(3);
        cin >> b[0] >> b[1] >> b[2];
        a.push_back(b);
    }
    vector <double> X(3);
    cout << "Введите координаты точки X через пробел: ";
    cin >> X[0] >> X[1] >> X[2];

    function <vector<double> (vector <double>)> minus = [X](vector <double> b) {
        vector <double> c(3);
        for (int i = 0; i < 3; i++) {
            c[i] = b[i] - X[i];
        }
        return c;
    };

    function <double (vector <double>)> distance = [X](vector <double> b) {
        double x = b[0], y = b[1], z = b[2];
        return sqrt(inner_product(b.begin(), b.end(), b.begin(), 0.0));
    };
    double max = 0;
    for (auto i = a.begin(); i != a.end(); i++) {
        double d = distance(minus(*i));
        if (d > max) {
            max = d;
        }
    }
    cout << "Максимальное расстояние от точки X до остальных точек: " << max << endl;
	return 0;
}