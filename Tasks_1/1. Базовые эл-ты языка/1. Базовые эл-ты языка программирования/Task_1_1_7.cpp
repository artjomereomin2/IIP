#include <iostream>
#include <cmath>
using namespace std;

double F7(double x, double y) {
    return exp(sqrt(log((x * x + y * y) / (cos(x) * cos(x) + cos(x * x)))));
}

int main()
{
    double x, y;
    cin >> x >> y;
    cout << F7(x, y);
    return 0;
}