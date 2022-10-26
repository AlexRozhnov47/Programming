#include "mywidget.h"
#include <QTableWidget>
#include <QHBoxLayout>
#include <iostream>
#include <iomanip>
#include <stdlib.h>

void MyWidget::help() //Справка о программе
    {
        QMessageBox::question(this, tr("О программе"),
                 tr("<center> <b> Эта программа предназначена для решения систем линейных уравнений методом Гаусса с возможностью использования процедуры выбора ведущего элемента.</b> </center> <BR> "
                    "<BR>"
                    " <u> Для начала использования программы Вам необходимо</u> : <BR>"
                    "<BR>""<BR>"
                    "1. Ввести колличество неизвестных (указать размерность системы)<BR> ""<BR>"
                    "2. Заполнить таблицу, где на месте i,j элемента  <BR>"
                    " указать i,j коэффициент, стоящий перед соответствующей переменной<BR>"
                    "   (Или воспользоваться кнопкой и сформировать матрицу случайным образом)<BR>""<BR>"
                    "3. При необходимости выбрать функцию использования процедуры выбора ведущего элемента<BR>""<BR>"
                    "4. Нажать на кнопку \"Решить систему\".<BR>""<BR>"
                    "5. В таблице появится две новых колонки \"X\" и \"Невязка\", <BR> "
                    " обозначающие ответ и его точность соответственно."));
    }

void MyWidget::setMatrixSize()  //устаналиваем размер таблицы
{

    int n = usr_dim->text().toInt();

    /*Если изменена размерность системы*/

    if(usr_matrix->columnCount() > n+1)
    {
        usr_matrix -> removeColumn(n); //удаляем столбик иксов
        usr_matrix -> removeColumn(n); //удаляем столбик с невязкой
        usr_matrix -> clearContents(); //удаляем из таблицы все введенные в нее данные
    }

    usr_matrix->setColumnCount(n+1);
    usr_matrix->setRowCount(n);
}
void MyWidget::randValue() // Заполняем таблицу случайными элементами
{
    int n = usr_dim->text().toInt();
    int i,j;
    double value;
    for (i=0;i<n;i++)
    {
     for (j=0; j<n+1; j++)
        {
         value=-500+rand()%500; //генерируем числа в диапазоне от -200 до 200
         if (value!=0) {value=(-15+rand()%15)/value;} //проверяем на 0 и делим на другое случаное число
         QTableWidgetItem *item1 = new QTableWidgetItem;  //Создаём итем, который положим в таблицу
         item1->setText(QString ("%1").arg(value)); // записываем  текст в итем
         usr_matrix->setItem(i, j, item1); //отправляем в таблицу
        }
    }
}
void MyWidget::crash() // Аварийное завершение программы
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::information(this, tr("Ошибка"), tr("Матрица вырожденная"));
}
void MyWidget::menuExit()
{
    qApp->quit();
}

