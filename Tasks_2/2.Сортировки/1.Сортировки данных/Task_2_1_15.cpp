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
    string name_a = a[0];
    string name_b = b[0];
    int experience_a = stoi(a[3]);
    int experience_b = stoi(b[3]);
    string date_a = a[2];
    string date_b = b[2];
    string year_str_a = date_a.substr(date_a.find_last_of(".") + 1, 4);
    string year_str_b = date_b.substr(date_b.find_last_of(".") + 1, 4);
    int year_a = stoi(year_str_a);
    int year_b = stoi(year_str_b);

    return name_a > name_b or (name_a == name_b and experience_a > experience_b) or (name_a == name_b and experience_a == experience_b and year_a > year_b);
}

void insertionSort(vector<vector<string>> &sorting, int N){
    for (int i = 1; i < N; i++) {
        int j = i;
        while (j > 0 and sravn(sorting[j - 1], sorting[j])) {
            swap(sorting[j], sorting[j - 1]);
            j--;
        }
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
    int experience;
    int salary;
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

    insertionSort(sorting, sorting.size());

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