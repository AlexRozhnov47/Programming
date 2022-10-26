#include "stdio.h"
#include "iostream"
#include "math.h"

// приведение матрицы коэффициентов к виду с ненулевой диагональю и соответствующее изменение вектора правых частей
// возвращает true - если приведение - успешно
bool getDiagonal(double** coefficients, double* rightPart, int currColumn, int numberOfEquation) {
	bool result = false;
	int i, row = currColumn;
	double tempItem;
	// для матрицы 1x1 ответом является ненулевость ее единственного элемента
	if (currColumn == numberOfEquation - 1) {
		result = coefficients[currColumn][currColumn] != 0;
	}
	else {
		// пока не найдена перестановка приводящая матрицу к виду с ненулевой диагональю и пока мы можем еще просматривать строки ищем перестановку
		while (!result && row < numberOfEquation) {
			// если текущий элемент на диагонали нулевой ищем в столбце дальше ненулевой
			if (coefficients[row][currColumn] != 0) {
				// если элемент ненулевой и не лежит на диагонали меняем местами сотвествующие строки в матрице и элементы в векторе прваых частей
				if (row != currColumn) {
					for (i = 0; i < numberOfEquation; i++) {
						tempItem = coefficients[currColumn][i];
						coefficients[currColumn][i] = coefficients[row][i];
						coefficients[row][i] = tempItem;
					}
					tempItem = rightPart[currColumn];
					rightPart[currColumn] = rightPart[row];
					rightPart[row] = tempItem;
				}
				// рекурсивный вызов фактически для подматрицы с размерностью на 1 меньше
				result = getDiagonal(coefficients, rightPart, currColumn + 1, numberOfEquation);
				if (result) {
					break;
				}
			}
			row++;
		}
	}

	return result;
}

// было ли найдено решение, если да - итог в параметре solution
int iteration(double** coefficients, double* rightPart, int numberOfEquation, double* solution, double precision) {
	bool result;
	int i, j, k, step = 1;
	double temp;
	double* tempSolution;
	tempSolution = new double[numberOfEquation];
	// приведение матрицы коэффициентов к виду с ненулевой диагональю и соответствующее изменение вектора правых частей
	result = getDiagonal(coefficients, rightPart, 0, numberOfEquation);
	// если приведение успешно - работаем дальше
	if (result) {
		double fault = precision + 1;
		// преобразуем матрицу и правую часть для дальнейшего решения
		for (i = 0; i < numberOfEquation; i++) {
			for (j = 0; j < numberOfEquation; j++) {
				if (i != j) {
					coefficients[i][j] = -coefficients[i][j] / coefficients[i][i];
				}
			}
			rightPart[i] = rightPart[i] / coefficients[i][i];
			coefficients[i][i] = 0;
		}
		// первое приближение решения - преобразованный вектор правых частей
		for (i = 0; i < numberOfEquation; i++) {
			solution[i] = rightPart[i];
		}
		// пока не найдено решение с допустимй погрешнстью или пока не исчерпан лимит шагов... если все расходится например
		while (fault > precision && step <= 1000) {
			// поиск новой итерации с ее "самоиспользованием" при расчетах			
			for (j = 0; j < numberOfEquation; j++) {
				tempSolution[j] = 0;
			}
			for (i = 0; i < numberOfEquation; i++) {
				for (j = 0; j < numberOfEquation; j++) {
					tempSolution[i] = tempSolution[i] + coefficients[i][j] * solution[j];
				}
				tempSolution[i] = tempSolution[i] + rightPart[i];
			}
			// расчет погрешности
			fault = 0.0;
			for (j = 0; j < numberOfEquation; j++) {
				fault = fault + (solution[j] - tempSolution[j]) * (solution[j] - tempSolution[j]);
			}
			fault = sqrt(fault);
			// сохранение полученной новой итерации
			for (j = 0; j < numberOfEquation; j++) {
				solution[j] = tempSolution[j];
			}
			step++;
		}
	}
	else {
		result = 1001;
	}
	return step;
}


int main() {
	int i, j;
	int size;
	double** coefficients, * rightPart, * solution, precision;
	using namespace std;
	setlocale(LC_ALL, "Russian");
	cout << "Итерационный метод.\n Введите колличество столбцов: ";
	cin >> size;
	coefficients = new double* [size];
	for (i = 0; i < size; i++) {
		coefficients[i] = new double[size];
	}
	rightPart = new double[size];
	solution = new double[size];
	for (i = 0; i < size; i++) {
		cout << "Введите " << i + 1 << " строку: ";
		for (j = 0; j < size; j++) {
			cin >> coefficients[i][j];
		}
	}

	cout << "Введите правую часть: ";
	for (j = 0; j < size; j++) {
		cin >> rightPart[j];
	}

	cout << "Введите точность: ";
	cin >> precision;

	int steps = iteration(coefficients, rightPart, size, solution, precision);
	if (steps > 1000) {
		cout << "Решением данная матрица не поддается";
	}
	else {
		cout << "Итог:\n";
		for (j = 0; j < size; j++) {
			cout << solution[j] << "\n";
		}
		cout << "Колличество шагов \p: " << steps;
	}

	cout << "\nPress \"Enter\" to continue...";
	getchar();
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
