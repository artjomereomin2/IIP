#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <chrono>
#include <windows.h>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	system("chcp 1251");
	system("cls");
	vector <string> a {"Программист",
		"Администратор",
		"Айтишник",
		"Алгоритм",
		"Ассемблер",
		"Архиватор",
		"Библиотека",
		"Блокчейн",
		"Буржунет",
		"Валидация",
		"Тачскрин",
		"Тестировщик",
		"Транслитерация",
		"Туториал",
		"Переполнение",
		"Пинговать",
		"Повесить",
		"Эпикфейл",
		"Мейнстрим"};
	vector <string> b {
		"\t________\n\t|\n\t|\n\t|\n\t|\n\t|\n    ____|_________\n",
		"\t________\n\t|      |\n\t|\n\t|\n\t|\n\t|\n    ____|_________\n",
		"\t________\n\t|      |\n\t|      O\n\t|\n\t|\n\t|\n    ____|_________\n",
		"\t________\n\t|      |\n\t|      O\n\t|      |\n\t|      |\n\t|\n    ____|_________\n",
		"\t________\n\t|      |\n\t|      O\n\t|     /|\n\t|      |\n\t|\n    ____|_________\n",
		"\t________\n\t|      |\n\t|      O\n\t|     /|\\\n\t|      |\n\t|\n    ____|_________\n",
		"\t________\n\t|      |\n\t|      O\n\t|     /|\\\n\t|      |\n\t|     /\n    ____|_________\n",
		"\t________\n\t|      |\n\t|      O\n\t|     /|\\\n\t|      |\n\t|     / \\\n    ____|_________\n"};
	chrono::time_point<chrono::system_clock> now = chrono::system_clock::now();
	auto duration = now.time_since_epoch();
	auto nanoseconds = chrono::duration_cast<chrono::nanoseconds>(duration);
	HANDLE hSTDOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO SCRN_INFO;
    GetConsoleScreenBufferInfo(hSTDOut, &SCRN_INFO);
	int k = 0;
	bool is_win = true;

	int n = ((nanoseconds.count() % 100000) / 1000) % (a.size() + 1);
	string str = a[n];
	cout << n << " " << str << endl;
	int sLen = str.size();
	set <char> setA;
	while (k < 7) {
		cout << b[k % 7] << endl;
		is_win = true;
		for (int i = 0; i < str.size(); i++) {
			char letter = str[i];
			if (setA.find(tolower(letter)) == setA.end()) {
				cout << "_ ";
				is_win = false;
			}
			else {
				cout << letter << " ";
			}
		}
		cout << endl;
		if (is_win) {
			WORD wColour = FOREGROUND_GREEN;
			SetConsoleTextAttribute(hSTDOut,wColour|FOREGROUND_INTENSITY);
			cout << "You win!" << endl;
			SetConsoleTextAttribute(hSTDOut,
				FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE|FOREGROUND_INTENSITY);
			break;
		}
		
		string alfabet = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя";
		WORD wColour = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;
		for (int i = 0; i < 33; i++) {
			if (setA.find(alfabet[i]) != setA.end()) {
				if (str.find(alfabet[i]) == string::npos and str.find(char(toupper(alfabet[i]))) == string::npos) {
					wColour = FOREGROUND_RED;
				}
				else {
					wColour = FOREGROUND_GREEN;
				}
				SetConsoleTextAttribute(hSTDOut,wColour|FOREGROUND_INTENSITY);
			}
			cout << char(toupper(alfabet[i])) << " ";
			SetConsoleTextAttribute(hSTDOut,
				FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE|FOREGROUND_INTENSITY);
		}
		cout << endl;
		char ch;
		cin >> ch;
		ch = tolower(ch);
		bool iss = (setA.insert(ch)).second;
		if (str.find(ch) == string::npos and iss) {
			k++;
		}
		system("cls");
	}
	if (not is_win) {
	cout << b[k];
	WORD wColour = FOREGROUND_RED;
	SetConsoleTextAttribute(hSTDOut,wColour|FOREGROUND_INTENSITY);
	cout << "You lose!" << endl;
	SetConsoleTextAttribute(hSTDOut,
				FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE|FOREGROUND_INTENSITY);}
	return 0;
}