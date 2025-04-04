#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main4()
{
	int x;
	do {
		setlocale(LC_ALL, "Rus");
		string names[10] = { "Ералаш", "Три кота", "Леонардо. Миссия Мона Лиза", "Коати", "Плакса", "Человек-паук. Возвращение домой", "Помогите!я уменьшил свою училку!", "Уральские пельмени", "Моя пиратская свадьба", "Матрица времени"};
		string types[4] = {"Сериалы", "Мультфильмы", "Фильм", "Шоу"};
		ofstream file_out("original_file.txt");
		file_out << "date,hour:minute,name,type;\n";
		for (int date = 9; date < 16; date++) {
			double time = (rand() % 3 + 1.0) / 3;
			int inttime = time;
			int minute = (time - inttime) * 60;
			for (int hour = 6; hour < 24; hour += inttime) {
				if (date < 10) file_out << "0";
				file_out << date << ".12,";

				if (hour < 10) file_out << "0";
				file_out << hour << ':';
				if (minute < 10) file_out << "0";
				file_out << minute << ',';
				time = (rand() % 3 + 1.0) / 3;
				inttime = time;
				minute += (time - inttime) * 60;
				if (minute > 60) {
					minute -= 60;
					inttime++;
				}
				file_out << names[rand() % 10] << "," << types[rand() % 4] << endl;

			}
		}
		file_out.close();
		string str;
		ifstream fil("original_file.txt");
		ofstream out("program.txt");
		while (getline(fil, str)) {
			int idata, itime, iname, itype;
			string data, tim, name, type;
			idata = str.find(',');
			data = str.substr(0, idata);
			itime = str.find(',', idata + 1);
			tim = str.substr(idata + 1, itime - idata - 1);
			iname = str.find(',', itime + 1);
			name = str.substr(itime + 1, iname - itime - 1);
			itype = str.find(';');
			type = str.substr(iname + 1, itype - iname - 1);
			int ihour, inthour, intminute;
			string hour, minute;
			ihour = tim.find(':');
			hour = tim.substr(0, ihour);
			minute = tim.substr(ihour + 1, tim.length() - ihour - 1);
			if (minute.find_first_not_of("0123456789") == string::npos and hour.find_first_not_of("0123456789") == string::npos) {
				inthour = stoi(hour);
				if (21 > inthour and inthour >= 18) {
					out << str << endl;
				}
			}
		}
		fil.close();
		out.close();
		cout << "Введите любое число для продолжения (кроме нуля): ";
		cin >> x;
	} while (x);
	return 0;
}