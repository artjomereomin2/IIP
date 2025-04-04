#include <iostream>
#include <cmath>
using namespace std;

int F17(int x) {
    int f = x / 100;
    int s = (x / 10) % 10;
    int t = x % 10;
    return ((f + s + t) % 10) * 100 + ((f * s * t) / 100) * 10 + (s + t) % f;
}

int main()
{
    int x;
    cin >> x;
    cout << F17(x);
    return 0;
}