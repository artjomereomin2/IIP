#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void merge(vector<int> &A, int l, int r, int m, bool third) {
    if (l >= r or m < l or m > r) return;
    if (r - l + 1 == 2) {
        if (A[l] > A[r] && (!third) or A[l] < A[r] && third) swap(A[l], A[r]);
        return;
    }
    vector <int> buf;
    int i = l, j = m + 1;
    while (true) {
        if (i > m) {
            for (int j1 = j; j1 <= r; j1++) buf.push_back(A[j1]);
            break;
        }
        else if (j > r) {
            for (int i1 = i; i1 <= m; i1++) buf.push_back(A[i1]);
            break;
        }
        else if (A[i] > A[j] && (!third) or A[i] < A[j] && third) {
            buf.push_back(A[j]);
            j++;
        }
        else {
            buf.push_back(A[i]);
            i++;
        }
    }
    for (int i = 0; i < buf.size(); i++) {
        A[l + i] = buf[i];
    }
}

void mergeSort(vector<int> &A, int l, int r, bool third) {
    if (l >= r) return;
    int m = (l + r) / 2;
    mergeSort(A, l, m, third);
    mergeSort(A, m + 1, r, third);
    merge(A, l, r, m, third);
}

void mergeSort_all(vector<vector<int>> &sorting, int N){
    bool third;
    for (int i = 0; i < N; i++) {
        third = ((i + 1) % 3 == 0);
        mergeSort(sorting[i], 0, N - 1, third);
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
    mergeSort_all(sorting, n);

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