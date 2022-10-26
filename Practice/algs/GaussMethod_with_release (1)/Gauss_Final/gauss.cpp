#include "mywidget.h"
#include <math.h>
#include <float.h>
#include <QTableWidget>
#include <QCheckBox>
#include <iostream>

/* Описание метода Гаусса */
void MyWidget::mSolve()
{

    /*Объявления*/
    int n = usr_dim->text().toInt(); //получаем размерность системы
    int i,j,k=0;
    double buf;

    /*Убираем предыдущее решение, если оно было выведено в виджет*/

    usr_matrix -> removeColumn(n+1); //убираем столбик "x"
    usr_matrix -> removeColumn(n+1); //убираем столбик "невязка"

    /*Получаем матрицу, для преобразования*/
    double** A=tableToArray();
    double** B=tableToArray();

    if(A!=0x0) //если валидация данных прошла успешно
    {

        /* Запускаем метод исключения Гаусса*/
        for (k=0 ; k < n ; k++)
        {
            if(usr_vedelm->isChecked()) vedElem(A,k); //если выбрана опция вызова процедуры выбора ведущего элемента
            for ( i = k+1 ; i < n; i++ )
            {
                buf = A[i][k]/A[k][k];
                for ( j = k ; j < n+1 ; j++)
                    A[i][j]=A[i][j]-buf*A[k][j];
            }
        }
    }
    else return; //если была введена тесктовая строка, а не число

    findSolution(A,B); //ищет иксы, записывает в новый стоблбик решения
    if(usr_newMatrix->isChecked()) newValue(A); //заполняет таблицу полученными данными (на место исходной таблицы вставит верхне-треугольную матрицу)
    clearMem(A); //очищает память, выделенную под таблицу    
}


/* Поиск решения Xi */
void MyWidget::findSolution(double **A, double **B)
{
    int n = usr_dim -> text().toInt();
    int i,j;
    double buf=0.0;
    double* X = new double [n];
    X[n-1]=A[n-1][n]/A[n-1][n-1];
    for ( i = n-2; i >= 0; i-- )
    {
        buf =0;
        for ( j = i+1 ; j < n ; j++)
            buf=buf+A[i][j]*X[j];
        X[i]=1.0/A[i][i]*(A[i][n]-buf);
    }
    newValue(X,1);
    nevyazka(B,X); //ищем невязку
}
