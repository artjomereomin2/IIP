#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <algorithm>
#include <sstream>

using namespace std;

void quickSort(vector<vector<string>> &sorting, int L, int R){
    int i = L;
    int j = R;
    int m = stoi(sorting[(L + R) / 2][4]);
    while (i <= j) {
        while (stoi(sorting[i][4]) < m) {
            i++;
        }
        while (stoi(sorting[j][4]) > m) {
            j--;
        }
        if (i <= j) {
            swap(sorting[i], sorting[j]);
            i++;
            j--;
        }
    }
    if (L < j) {
        quickSort(sorting, L, j);
    }
    if (i < R) {
        quickSort(sorting, i, R);
    }

}

int main()
{
    setlocale(LC_ALL, "Rus");
    //system("chcp 1251");
    ifstream input("./2.Сортировки/1.Сортировки данных/input.txt");
    ofstream output("output.txt");

    string name;
    string profession;
    string date;
    string line;
    string experience_str;
    string salary_str;

    vector <vector<string>> sorting;

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

    quickSort(sorting, 0, sorting.size() - 1);


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