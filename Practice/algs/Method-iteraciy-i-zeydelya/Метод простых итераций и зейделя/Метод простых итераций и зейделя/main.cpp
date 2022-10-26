#include <iostream>
#include <cmath>
#include "norm.h"
#include "iterat.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "");
	double eps, A[10][10], B[10];
	int N, i, j;
	int method;
	cout << "������� ������ ���������� �������: ";
	cin >> N;
	cout << "������� �������� ����������: ";
	cin >> eps;
	cout << "��������� ������� �: " << endl << endl;
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
		{
			cout << "A[" << i << "][" << j << "] = ";
			cin >> A[i][j];
		}
	cout << endl << endl;
		cout << "���� ������� �: " << endl << endl;
		for (i = 0; i < N; i++)
		{
			for (j = 0; j < N; j++)
				cout << A[i][j] << " ";
		cout << endl;
		}

		cout << endl;

		cout << "��������� ������� ��������� ������: " << endl << endl;
		for (i = 0; i < N; i++)
		{
			cout << "�[" << i+1 << "] = ";
			cin >> B [i];
		}
		cout << endl << endl;
		cout << "�������� ����� ������� �������:" << endl << endl;
		cout <<"1. ����� ������\n2. ����� �������" << endl << endl;
		cin >> method;
		cout << endl << endl;
		iterat(A,B,N,eps,method);
		
		return 0;


}