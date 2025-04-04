#include <iostream>
using namespace std;

int main() 
{
	setlocale(LC_ALL, "RUS");
	// ���� �����
	int n, i;
	cout << "������� n: ";
	cin >> n;
	cout << "������� i: ";
	cin >> i;
	// 1 �������
	cout << endl << "������� 1: " << (1 << i) << endl; // x << 1 - ��������� �� 2, 1 << i - ��������� 1 �� 2 � ������� i
	// 2 �������
	cout << "������� 2: " << ((1 << i) | n) << endl; // 1 << i ������ ����� � ����� = 1 �� ������� i, ��������� = 0
	// ���� ��� � n �� ������� i = 0, ���������� ������� ���� ��� = 1 (1 | 0 = 1)
	// ���� ��� � n = 1, ���������� ������� ��� = 1 (1 | 1 = 1)
	// � ��������� ���� ���������� ������� ������ ��, ��� � � n (0 | 0 = 0, 0 | 1 = 1)
	// 0000 1 0000
	// 0110 0 1010
	// 0110 1 1010
	// 3 �������
	cout << "������� 3: " << (~(1 << i) & n) << endl; // ~(1 << i) ������ ����� � ����� = 0 �� ������� i, ��������� = 1
	// ���� ��� � n �� ������� i = 0, ���������� ������� ���� ��� = 0 (0 & 0 = 0)
	// ���� ��� � n = 1, ���������� ������� ��� = 0 (0 & 1 = 0)
	// � ��������� ���� ���������� ������� ������ ��, ��� � � n (1 & 0 = 0, 1 & 1 = 1)
	// 111 0 1111
	// 010 1 0110
	// 010 0 0110
	// 4 �������
	cout << "������� 4: " << ((1 << i) ^ n) << endl; // 1 << i ������ ����� � ����� = 1 �� ������� i, ��������� = 0
	// ���� ��� � n �� ������� i = 0, xor ������� ���� ��� = 1 (1 ^ 0 = 1)
	// ���� ��� � n = 1, xor ������� ��� = 0 (1 ^ 1 = 0)
	// � ��������� ���� xor ������� ������ ��, ��� � � n (0 & 0 = 0, 0 & 1 = 1)
	// 000 1 0000
	// 010 1 0110
	// 010 0 0110
	// 5 �������
	cout << "������� 5: ";
	((n & 1) == 1) ? cout << "��������" : cout << "׸����"; // ׸���� ����� ������������� �� 0, �������� - �� 1
	// ��� ���������� � 1 �� ���������� ������ ������ ���, ���� �� ����� 0, ��������� 0, � ���� ����� 1, ��������� 1 (0 & 1 = 1, 1 & 1 = 1)
	// 00000000001
	// 00010111011
	// 00000000001
	return 0;
}