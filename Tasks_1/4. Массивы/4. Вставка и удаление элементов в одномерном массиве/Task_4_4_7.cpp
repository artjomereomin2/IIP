#include <iostream>

using namespace std;

int main7_1()
{
	int d;
	do {
		setlocale(LC_ALL, "Rus");
		// ������������� ��c����
		int n;
		cout << "������� n: ";
		cin >> n;
		int* m = new int[n];
		// ���� ��-�� �������
		cout << "������� �������� �������:" << endl;
		for (int i = 0; i < (n); i++) {
			cin >> m[i];
		}
		// ����� ������������� �������� � �������
		int ma = INT_MIN;
		for (int i = 0; i < n; i++) {
			if (m[i] > ma) {
				ma = m[i];
			}
		}
		// ��������� ������� (��� ���������� ������������ ��-�� ��������
		// ��� ��-�� �� ���� �� 1 ����� � ���������� � �������� ���� �����
		int c = 0;
		for (int i = 0; i < n; i++) {
			if (m[i] == ma) {
				for (int j = i - 1; j >= 0; j--) {
					m[j + 1] = m[j];
				}
				c++;
			}
		}
		// ����� ����������� �������
		cout << "������ ��� ����. ���������:\n";
		for (int i = c; i < n - 1; i++) {
			cout << m[i] << ", ";
		}
		cout << m[n - 1] << endl;
		// �������� �������
		delete[]m;

		cout << "������� ����� ����� ��� ����������� (����� ����): ";
		cin >> d;
	} while (d);
	return 0;
}