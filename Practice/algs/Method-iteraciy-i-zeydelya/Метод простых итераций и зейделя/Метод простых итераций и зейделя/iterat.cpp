#include <iostream>
#include <cmath>
#include "norm.h"
#include "okr.h"
using namespace std;
double iterat(double A[10][10], double B[10], int N, double eps, int method)
{
	if (thirdNorm(A,N,N) < 1)
	{
		int k = 0,i,j;
		double X[10], Y[10], s, g;
		for(i = 0; i < N; i++)
			X[i] = B[i];
		do
		{
			s = 0;
			k++;
			if (method != 1 && method != 2)
			{
				while (method != 1 && method != 2)
				{
				cout << "�������� ��������!" << endl;
				cout <<   "�������� ����� ������� �������:" << endl << endl;
				cout << "1. ����� ������\n2. ����� �������" << endl << endl;
				cin >> method;
				cout << endl << endl;
				}
			}
			if (method == 1) // ������ ������� ������� ������.
			{
				for (i = 0; i < N; i++)
				{
					Y[i] = B[i];
					for (j = 0; j < N; j++)
						Y[i] = Y[i] + A[i][j] * X[j];
					s += (X[i] - Y[i]) * (X[i] - Y[i]);
				}
				for (i = 0; i < N; i++)
					X[i] = Y[i];
			}
			else if (method == 2) // ������ ������� ������� �������.
			{
				for (i = 0; i < N; i++)
				{
					g = B[i];
					for (j = 0; j < N; j++)
						g = g + A[i][j] * X[j];
					s += (X[i] - g) * (X[i] - g);
					X[i] = g;
				}

			}
		}
		while (sqrt(s) >= eps*(1 - thirdNorm(A, N, N))/thirdNorm(A, N, N));
		if (method == 1 || method == 2)
		{
			cout << "������� �������:" << endl << endl;
			for (i = 0; i < N; i++)
				cout << "X"<< i <<" = "<< okr(X[i],eps) <<"" << endl;
			cout << "����� ��������: " << k-1 << "" << endl << endl;
			cout << "������ ����� ������� A: " << firstNorm(A,N,N) << "" << endl;
			cout << "������ ����� ������� A: " << secondNorm(A,N,N) << "" << endl;
			cout << "������ ����� ������� A: " << thirdNorm(A,N,N) << "" << endl;
			cout << endl << endl;
		}
	}

	else
		cout << "������� ���������� �� ���������� ������� �� �����������!" << endl << endl;

	return 0;
}