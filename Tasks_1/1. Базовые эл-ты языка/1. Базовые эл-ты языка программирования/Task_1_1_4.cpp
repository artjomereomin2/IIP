#include <iostream>
#include <cmath>
using namespace std;

double F4(double x, double y) {
    return sqrt((exp(x * x + y * y) + 5 * x) / (cos(x + y) * cos(x + y))) / 3 + x / y;
}

int main()
{
    double x, y;
    cin >> x >> y;
    cout << F4(x, y);
    return 0;
}