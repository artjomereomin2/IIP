#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>
#include <cmath>

using namespace std;

bool sravn(vector<string> a, vector<string> b){
    return stoi(a[4]) > stoi(b[4]) or (stoi(a[4]) == stoi(b[4]) and a[0] > b[0]);
}

void ShellSort(vector<vector<string>> &sorting, int N){
    int i = 1;
    for (; (pow(3, i) - 1) <= N; i++);
    int step = pow(3, i) - 1;
    while (step >= 1) {
        for (int i = 0; i < N - step; i++) {
            int j = i;
            while (j >= 0 and sravn(sorting[j], sorting[j + step])) {
                swap(sorting[j], sorting[j + step]);
                j -= step;
            }
        }
        step++;
        step /= 3;
        step--;
        if (step == 0) step = 1;
    }
}

int main()
{
    setlocale(LC_ALL, "Rus");
    //system("chcp 1251");
    ifstream input("./Tasks_2/2.Сортировки/1.Сортировки данных/input.txt");
    ofstream output("output.txt");

    string name;
    string profession;
    string date;
    string line;
    string experience_str;
    string salary_str;
    vector <vector <string>> sorting;

    int i = 0;

    while (getline(input, line)) {
        istringstream iss (line);
        getline(iss, name, ';');
        getline(iss, profession, ';');
        getline(iss, date, ';');
        getline(iss, experience_str, ';');
        getline(iss, salary_str, '\n');
        
        vector<string> listLine;

        listLine.push_back(name);
        listLine.push_back(profession);
        listLine.push_back(date);
        listLine.push_back(experience_str);
        listLine.push_back(salary_str);

        sorting.push_back(listLine);

        i++;
    }

    ShellSort(sorting, sorting.size());

    for (auto i = sorting.begin(); i != sorting.end(); i++) {
        vector<string> vi = *i;
        for (auto j = vi.begin();j < vi.end();j++) {
            output << *j << " ";
        }
        output << endl;
    }


    input.close();
    output.close();

    return 0;
}