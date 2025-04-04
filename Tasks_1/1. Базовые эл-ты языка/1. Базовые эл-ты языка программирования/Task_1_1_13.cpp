#include <iostream>
#include <cmath>
using namespace std;

int F13(int x) {
    int z = x % 10;
    int w = x / 10;
    return (31 % w) * 1000 + (48 % w) * 100 + (31 % z) * 10 + 48 % z;
}

int main()
{
    int x;
    cin >> x;
    cout << F13(x);
    return 0;
}