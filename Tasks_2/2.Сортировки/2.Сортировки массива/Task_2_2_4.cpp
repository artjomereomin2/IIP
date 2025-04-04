#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void insertionSort(vector<int> &sorting, int N){
    for (int i = 1; i < N; i++) {
        int j = i;
        while (j > 0 and sorting[j] < sorting[j - 1]) {
            swap(sorting[j], sorting[j - 1]);
            j--;
        }
    }
}

void blockSort(vector<int> &sorting, int N) {
    if (N >= 1 and N <= 3) {
        insertionSort(sorting, N);
    }
    else if (N > 3) {
        int P = N / 2;
        int maxx = INT_MIN, minn = INT_MAX;
        for (int i = 0; i < N; i++) {
            if (sorting[i] > maxx) {
                maxx = sorting[i];
            }
            if (sorting[i] < minn) {
                minn = sorting[i];
            }
        }
        vector<vector<int>> baskets;
        for (int i = 0; i < P; i++) {
            vector<int> vec;
            baskets.push_back(vec);
        }
        int m = (maxx - minn) / P;
        for (int i = 0; i < N; i++) {
            int k = (sorting[i] - minn) / m;
            if (k >= P) {
                k = P - 1;
            }
            baskets[k].push_back(sorting[i]);
        }
        for (int i = 0; i < P; i++) {
            blockSort(baskets[i], baskets[i].size());
        }
        int ind = 0;
        for (int i = 0; i < P; i++) {
            for (int j = 0; j < baskets[i].size(); j++) {
                sorting[ind] = baskets[i][j];
                ind++;
            }
        }
    }
}

void blockSort_all(vector<vector<int>> &sorting, int N){
    for (int i = 0; i < N; i++) {
        blockSort(sorting[i], N);
    }
}

int main()
{
    setlocale(LC_ALL, "Rus");
    //system("chcp 1251");
    ifstream input("./2.Сортировки/2.Сортировки массива/input.txt");
    ofstream output("output.txt");

    int n;
    input >> n;

    vector <int> vecLine;
    vector <vector <int>> sorting;

    int i = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int a;
            input >> a;
            vecLine.push_back(a);
        }
        sorting.push_back(vecLine);
        vecLine.clear();
    }
    blockSort_all(sorting, n);

    for (int i = 0; i != n; i++) {
        for (int j = 0; j != n; j++) {
            int s = sorting[i][j];
            output << s << ' ';
            if (s < 10) output << ' ';
        }
        output << endl;
    }

    input.close();
    output.close();

    return 0;
}