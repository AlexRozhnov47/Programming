#include "mywidget.h"
#include <QTableWidget>
#include <iomanip>
#include <stdlib.h>
#include <qtextcodec.h>
#include <float.h>
#include <QColor>
#include <QBrush>

/* Заполняем таблицу итоговыми результатами */
void MyWidget::newValue(double** A)
{
    int n = usr_dim->text().toInt();
    int i,j;
    double value;
    for (i=0;i<n;i++)
     for (j=0; j<(n+1); j++)
        {
         value=A[i][j]; //Берем i,j элемент
         QTableWidgetItem *item1 = new QTableWidgetItem;  //Создаём итем, который положим в таблицу
         item1->setText(QString ("%1").setNum(value)); // записываем  текст в итем
         usr_matrix->setItem(i, j, item1); //отправляем в таблицу
        }

}

/* Добавляем к матрице столбики "x" и "невязка" */
void MyWidget::newValue(double *A, int p)
{
    int n = usr_dim->text().toInt();
    int i;
    double value;
    if (p==1) // добавляем к имеющейся таблице столбик с найденными иксами
    {
        usr_matrix->insertColumn(n+1);
        QTableWidgetItem *item = new QTableWidgetItem;
        item->setText(QString(QChar('x')));
        usr_matrix->setHorizontalHeaderItem(n+1,item);

        for (i=0;i<n;i++)
        {
            value=A[i]; //Берем i элемент
             QTableWidgetItem *item1 = new QTableWidgetItem;  //Создаём итем, который положим в таблицу
             item1->setText(QString ("%1").arg(value)); // записываем  текст в итем
             usr_matrix->setItem(i, n+1, item1); //отправляем в таблицу
        }

    }
    else // добавляем к имеющейся таблице столбик с "невязкой"
    {
        usr_matrix->insertColumn(n+2);
        QTableWidgetItem *item = new QTableWidgetItem;
        item->setText(tr("Невязка"));
        usr_matrix->setHorizontalHeaderItem(n+2,item);

        for (i=0;i<n;i++)
        {
             value=A[i]; //Берем i элемент
             QString str;
             QTableWidgetItem *item1 = new QTableWidgetItem;  //Создаём итем, который положим в таблицу
             item1->setText(str.setNum(value)); // записываем  текст в итем
             usr_matrix->setItem(i, n+2, item1); //отправляем в таблицу
        }

    };

}

/* Переносим данные из таблицы в матрицу для вычислений */
double** MyWidget::tableToArray()
{
    int n = usr_dim -> text().toInt();
    int i,j;
    bool isOK = false;



    double** A = new double* [n]; //Создаем массив под заданную матрицу
    for (i = 0; i < n ; i++)
         A[i]=new double [n+1];

    /* Заполнение матрицы исходными данными */

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n+1; j++)
        {
            A[i][j]=usr_matrix->item(i,j)->text().toDouble(&isOK);
            usr_matrix->item(i,j)->setBackgroundColor(Qt::white);
            if (isOK == false)
            {
                badValue(i,j);
                return 0x0;
            }
        }
    }
    return A;
}

/* Вычисляем "невязку" для каждого полученного значения */
void MyWidget::nevyazka(double **A, double *X)
{
    int i,j;
    int n = usr_dim -> text().toInt();
    double* B = new double [n];
    for ( i = 0 ; i < n ; i++)
        B[i] = 0.0;

    for ( i = 0 ; i < n ; i++)
        for ( j = 0 ; j < n ; j++ )
            B[i] += A[i][j]*X[j];

    for ( i = 0 ; i < n ;i++ )
    {
        double temp = usr_matrix->item(i,n)->text().toDouble();
        B[i] = (double)fabs( temp - B[i]);

    }
    newValue(B,2);
    setMaxNev(B);
    delete[] B;

}

/*Ищем максимальное значение "невязки" для используемого метода */
void MyWidget::setMaxNev(double *A)
{
    int n = usr_dim -> text().toInt();
    int i;
    double max = A[0];
    for (i=1; i<n; i++)
        if (max < A[i] )  max = A[i];

    dsp_maxNev -> setText(QString("%1").setNum(max, 'e'));
}

/*Выводим сообщение о неверном типе введенных данных */
void MyWidget::badValue(int i, int j)
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::warning(this, tr("Ошибка"), tr("Вы ввели неправильное значение в ячейку. Убедитесь, что Вы ввели число."));
    usr_matrix->item(i,j)->setBackgroundColor(Qt::red);
    return;
}

/* Очищаем память по завершению работы программы */
void MyWidget::clearMem(double** A)
{
    int n = usr_dim->text().toInt();
    for(int i = 0; i < n; i++)
       delete[] A[i];
    delete A;
}

