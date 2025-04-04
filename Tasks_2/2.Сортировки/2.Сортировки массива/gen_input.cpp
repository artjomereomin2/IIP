#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");
    //system("chcp 1251");
    ofstream input("./2.Сортировки/2.Сортировки массива/input.txt");

    int n;
    cout << "Введите n: ";
    cin >> n;
    input << n << endl;

    srand(time(0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int r = rand() % 100;
            input << r << ' ';
            if (r < 10) input << ' ';
        }
        input << endl;
    }

    input.close();

    return 0;
}