#include <iostream>

using namespace std;

int main12()
{
	int n;
	do {
		setlocale(LC_ALL, "Rus");
		int d, m, y;
		cin >> d >> m >> y;// ¬вод данных
		int err_m, max_d;// err_m - то, сколько дней нужно добавить к 28, чтобы получить количество дней в данном мес€це(кроме феврал€), max_d - количество дней в данном мес€це
		bool vis = (y % 4 == 0 and y % 100 != 0 or y % 400 == 0);// vis - вискосный ли год
		switch (m)
		{
		case 2:
			err_m = 0;
			break;
		case 4: case 6: case 9: case 11: err_m = 2; break; // 28 + 2 = 30
		default:
			err_m = 3; // 28 + 3 = 31
			break;
		}
		max_d = 28 + (vis and m == 2) + err_m; // 28 + вискосность в феврале + err_m
		if (y < 1) {
			cout << "неправильный год"; // Ќе учитываем года до н. э.
		}
		else if (m < 1 or m > 12) {
			cout << "неправильный мес€ц"; // некорректный мес€ц
		}
		else if (d < 1 or d > max_d) {
			cout << "неправильный день"; // некорректный день
		}
		else {
			cout << d;
			switch (m)
			{
			case 1: cout << " €нвар€ "; break;
			case 2: cout << " феврал€ "; break;
			case 3: cout << " марта "; break;
			case 4: cout << " апрел€ "; break;
			case 5: cout << " ма€ "; break;
			case 6: cout << " июн€ "; break;
			case 7: cout << " июл€ "; break;
			case 8: cout << " августа "; break;
			case 9: cout << " сент€бр€ "; break;
			case 10: cout << " окт€бр€ "; break;
			case 11: cout << " но€бр€ "; break;
			default:
				cout << " декабр€ ";
				break;
			}
			cout << y << " года" << endl;
			cout << max_d - d;
		}
		cout << endl << "¬ведите любое число дл€ продолжени€ (кроме нул€): ";
		cin >> n;
	} while (n);
	return 0;
}