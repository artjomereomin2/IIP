#include <iostream>
#include <fstream>
#include <set>
#include <cmath>
#include <map>
#include <string>
#include <algorithm>
//#include <sstream>

using namespace std;

int main()
{
	ifstream fle;
	fle.open("C:/Users/1/source/repos/Tasks_2/1.Работа_с_библеотекой_STL/2.Задачи_на_set_и_map/input_2.txt");
	setlocale(LC_ALL, "Rus");
	string s;
	set <string> a;
	map <int, int> b;
	while (getline(fle, s))
	//istringstream
	{
		s += "\n";
		int i_start_word, i_end_word;
		i_start_word = s.find_first_not_of(" \n");
		while (i_start_word != string::npos) {
			i_end_word = s.find_first_of(" \n", i_start_word);
			string word = s.substr(i_start_word, i_end_word - i_start_word);
			
			int n = atoi(word.c_str());
			if (b.count(n) != 0) {
				b[n]++;
			} else {
				b[n] = 1;
			}

			i_start_word = s.find_first_not_of(" \n", i_end_word);
		}
	}
	cout << "Введите k: ";
	int k;
	cin >> k;
	for (auto i = b.begin(); i != b.end(); i++)
	{
		if (i->second == k) {
			cout << i->first << " ";
		}
	}
	cout << endl;
	fle.close();
}