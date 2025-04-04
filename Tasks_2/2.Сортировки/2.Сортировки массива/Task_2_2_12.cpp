#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void even_oddSort(vector<int> &A, int N) {
    for (int i = 0; i < N; i++) {
        if (i % 2 == 0) {
            for (int j = 2; j < N; j += 2) {
                if (A[j] < A[j - 1]) swap(A[j], A[j - 1]);
            }
        }
        else {
            for (int j = 1; j < N; j += 2) {
                if (A[j] < A[j - 1]) swap(A[j], A[j - 1]);
            }
        }
    }
}

void even_oddSort_all(vector<vector<int>> &sorting, int N){
    vector<int> A;
    for (int i = 1; i < 2*N - 2; i++) {
        for (int j = 0; j < i + 1 and i < N or j < N and i >= N; j++) {
            if (N - 1 - i + j >= 0) A.push_back(sorting[j][N - 1 - i + j]);
            else A.push_back(0);
        }
        even_oddSort(A, A.size());
        for (int j = 0; j < i + 1 and i < N or j < N and i >= N; j++) {
            if (N - 1 - i + j >= 0) sorting[j][N - 1 - i + j] = A[j];
        }
        A.clear();
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
    int a;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            input >> a;
            vecLine.push_back(a);
        }
        sorting.push_back(vecLine);
        vecLine.clear();
    }
    even_oddSort_all(sorting, n);

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