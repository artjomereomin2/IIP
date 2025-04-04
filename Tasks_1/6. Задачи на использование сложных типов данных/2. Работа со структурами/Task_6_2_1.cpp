#include <iostream>
#include <map>
#include <list>
#include <tuple>
#include <string>

using namespace std;

class Hotel {
private:
	map <string, list<int>> dates;
	int id = -1;
	map <int, int> count_d(int year) {
		bool is_visoc = (year % 4 == 0 and (year % 100 != 0 or year % 400 == 0));
		map <int, int> count_days = {
				{1, 31}, {2, 28 + is_visoc}, {3, 31}, {4, 30}, {5, 31}, {6, 30}, {7, 31}, {8, 31}, {9, 30}, {10, 31}, {11, 30}, {12, 31}
		};
		return count_days;
	}
public:
	tuple<bool, int, int, int> is_date(string date) { // dd.mm.yyyy
		map<int, int> i = { {0, 0} };
		int iday = date.find('.');
		if (iday == string::npos) return { false, 0, 0, 0 };
		string day = date.substr(0, iday);
		if (day.find_first_not_of("0123456789") != string::npos) return { false , 0, 0, 0 };
		int imounth = date.find('.', iday + 1);
		if (imounth == string::npos) return { false, 0, 0, 0 };
		string mounth = date.substr(iday + 1, imounth - iday - 1);
		if (mounth.find_first_not_of("0123456789") != string::npos) return { false, 0, 0, 0 };
		string year = date.substr(imounth + 1, date.length() - imounth - 1);
		if (year.find_first_not_of("0123456789") != string::npos) return { false, 0, 0, 0 };
		int int_year = stoi(year);
		map <int, int> count_days = count_d(int_year);
		int int_mounth = stoi(mounth);
		if (int_mounth > 12) return { false, 0, 0, 0 };
		int int_day = stoi(day);
		if (int_day > count_days[int_mounth]) return { false, 0, 0, 0 };
		i[0] = int_day;
		i[1] = int_mounth;
		i[2] = int_year;
		return { true, int_day, int_mounth, int_year };
	}
	map <int, string> customers;
	void new_customer (string fio, string d_of_come, int c) {
		tuple<bool, int, int, int> iss_d = is_date(d_of_come);
		bool is_d = get<0>(iss_d);
		int day = get<1>(iss_d), mounth = get<2>(iss_d), year = get<3>(iss_d);
		map <int, int> count_days = count_d(year);
		string date = to_string(day) + '.' + to_string(mounth) + '.' + to_string(year);

		if (is_d) {
			id += 1;
			customers[id] = fio;
			for (int i = 0; i < c; i++, day++) {
				if (day > count_days[mounth]) {
					day = 1;
					mounth++;
					if (mounth > 12) {
						mounth = 1;
						year++;
						count_days = count_d(year);
					}
				}
				date = to_string(day) + '.' + to_string(mounth) + '.' + to_string(year);
				if (dates.count(d_of_come)) {
					dates[date].push_back(id);
				}
				else {
					list<int> emp = { id };
					dates[date] = emp;
				}
			}
		}
		else cout << "Некорректная дата" << endl;
	}
	list<int> customers_at_day(string date) {
		list <int> l;
		tuple<bool, int, int, int> iss_d = is_date(date);
		bool is_d = get<0>(iss_d);
		int day = get<1>(iss_d), mounth = get<2>(iss_d), year = get<3>(iss_d);
		if (is_d) {
			string date = to_string(day) + '.' + to_string(mounth) + '.' + to_string(year);
			if (dates.count(date)) return dates[date];
			else {
				cout << "Нет посетителей в этот день" << endl;
				return l;
			}
		}
		cout << "Некорректная дата" << endl;
		return l;
	}
};

int main1()
{
	int x;
	do {
		setlocale(LC_ALL, "Rus");
		int c;
		cout << "Введите количество посетителей: ";
		cin >> c;
		Hotel hotel_hasbeen;
		for (int i = 0; i < c; i++) {
			string fio;
			cout << "Введите ФИО " << i + 1 << " посетителя:\n";
			cin.get();
			getline(cin, fio);
			string date;
			cout << "Введите его дату прибытия (В фомате dd.mm.yyyy):\n";
			getline(cin, date);
			while (!get<0>(hotel_hasbeen.is_date(date))) {
				cout << "Некорректная дата, попробуйте ещё раз" << endl;
				cout << "Введите его дату прибытия (В фомате dd.mm.yyyy):\n";
				getline(cin, date);
			}
			int count;
			cout << "Введите количество дней, проведённых им в отеле:\n";
			cin >> count;
			hotel_hasbeen.new_customer(fio, date, count);
		}
		cout << "Введите количество проверяемых дат: ";
		cin >> c;
		cin.get();
		for (int i = 0; i < c; i++) {
			string date;
			cout << "Введите дату (В фомате dd.mm.yyyy):\n";
			getline(cin, date);
			list<int> custom = hotel_hasbeen.customers_at_day(date);
			if (!custom.empty()) {
				cout << "Посетители в этот день:\n";
				int j = 1;
				for (auto iter = custom.begin(); iter != custom.end(); iter++, j++) {
					cout << j << " посетитель: " << hotel_hasbeen.customers[*iter] << endl;
				}
			}

		}
		cout << "Введите любое число для продолжения (кроме нуля): ";
		cin >> x;
	} while (x);
	return 0;
}