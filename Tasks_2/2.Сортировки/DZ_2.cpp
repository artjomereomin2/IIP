#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

void MSDSort(vector<int> &A, int n, int k) {
    vector<vector<int>> B;
    for (int i = 0; i < 10; i++) {
        vector<int> vecl;
        B.push_back(vecl);
    }
    for (int j = 0; j < n; j++) {
        int cur = (A[j] % int(pow(10, k + 1))) / int(pow(10, k));
        B[cur].push_back(A[j]);
    }
    for (int j = 0; j < 10; j++) {
        for (int l = 0; l < B[j].size(); l++) {
            int r = B[j][l];
        }
        if (B[j].size() > 1) MSDSort(B[j], B[j].size(), k - 1);
    }
    int ind = 0;
    for (int j = 0; j < 10; j++) {
        for (int k = 0; k < B[j].size(); k++) {
            A[ind] = B[j][k];
            ind++;
        }
        B[j].clear();
    }
}

int main()
{
    setlocale(LC_ALL, "Rus");
    //system("chcp 1251");

    cout << "¬ведите n: ";
    int n;
    cin >> n;

    vector <int> sorting;

    int i = 0;
    int k = 0;

    srand(time(0));

    for (int i = 0; i < n; i++) {
        int r = rand() % int(pow(10, (rand() % 5) + 1));
        sorting.push_back(r);
        cout << r << ' ';
        while (r >= pow(10, k + 1)) {
            k++;
        }
    }
    cout << endl;

    MSDSort(sorting, n, k);

    for (int i = 0; i != n; i++) {
        int s = sorting[i];
        cout << s << ' ';
    }

    return 0;
}