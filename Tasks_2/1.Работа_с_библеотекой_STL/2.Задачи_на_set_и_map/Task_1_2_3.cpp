#include <iostream>
#include <fstream>
#include <cmath>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	ifstream fle;
	fle.open("C:/Users/1/source/repos/Tasks_2/1.Работа_с_библеотекой_STL/2.Задачи_на_set_и_map/input_3.txt");
	setlocale(LC_ALL, "Rus");
	string s;
	set <string> a;
	set <string> b;
	while (getline(fle, s))
	{
		s += "\n";
		int i_start_word, i_end_word, i_start_l = 0, i_end_l = s.find_first_of(".!?");
		while (i_start_l != string::npos) {	
			i_start_word = s.find_first_not_of(" .!?", i_start_l);
			while (i_start_word < i_end_l and i_start_word != string::npos) {
				i_end_word = s.find_first_of(" .!?", i_start_word);
				string word = s.substr(i_start_word, i_end_word - i_start_word);

				transform(word.begin(), word.end(), word.begin(), ::tolower);
				if (s[i_end_l] == '!' and b.find(word) == b.end()) {
					a.insert(word);
				} else {
					b.insert(word);
				}
				
				i_start_word = s.find_first_not_of(" .!?", i_end_word);
			}
			i_start_l = i_end_l;
			i_end_l = s.find_first_of(".!?", i_start_l + 1);
		}
	}
	for (auto i = a.begin(); i != a.end(); i++)
	{
		cout << *i << endl;
	}
	cout << endl;
	fle.close();
}