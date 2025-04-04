#include <iostream>
#include <string>

using namespace std;

int main3()
{
	int x;
	do {
		setlocale(LC_ALL, "Rus");
		string str, prep = ".,?!:; ", words = "";
		cout << "¬ведитее строку: \n";
		getline(cin, str);
		int i = 0, word_start = 0, word_end = 0;
		str = " " + str + " ";
		int cm = INT_MIN;
		while (true) {
			i = str.find_first_of(prep, word_end);
			if (i == string::npos) break;
			word_start = str.find_first_not_of(prep, i);
			if (word_start == string::npos) break;
			word_end = str.find_first_of(prep, word_start);
			if (word_end == string::npos) break;
			string word = str.substr(word_start, word_end - word_start);
			string ret = "";
			int c = 0;
			while (word.find_first_not_of(ret) != string::npos) {
				ret += word[word.find_first_not_of(ret)];
				c++;
			}
			if (c > cm) {
				cm = c;
				words = word + " ";
			}
			else if (c == cm) {
				words += word + " ";
			}
		}
		i = 0;
		word_start = 0;
		word_end = 0;
		words = " " + words + " ";
		while (true) {
			i = words.find_first_of(prep, word_end);
			if (i == string::npos) break;
			word_start = words.find_first_not_of(prep, i);
			if (word_start == string::npos) break;
			word_end = words.find_first_of(prep, word_start);
			if (word_end == string::npos) break;
			string word = words.substr(word_start, word_end - word_start);
			cout << "—лово с наибольшим количеством различных символов: ";
			cout << word << endl;
		}
		cout << "¬ведите любое число дл€ продолжени€ (кроме нул€): ";
		cin >> x;
		cin.get();
	} while (x);
	return 0;
}