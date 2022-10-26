#include "mywidget.h"
#include <QTableWidget>
#include <iomanip>
#include <stdlib.h>
#include <qtextcodec.h>
#include <float.h>
#include <QColor>
#include <QBrush>

/* ��������� ������� ��������� ������������ */
void MyWidget::newValue(double** A)
{
    int n = usr_dim->text().toInt();
    int i,j;
    double value;
    for (i=0;i<n;i++)
     for (j=0; j<(n+1); j++)
        {
         value=A[i][j]; //����� i,j �������
         QTableWidgetItem *item1 = new QTableWidgetItem;  //������ ����, ������� ������� � �������
         item1->setText(QString ("%1").setNum(value)); // ����������  ����� � ����
         usr_matrix->setItem(i, j, item1); //���������� � �������
        }

}

/* ��������� � ������� �������� "x" � "�������" */
void MyWidget::newValue(double *A, int p)
{
    int n = usr_dim->text().toInt();
    int i;
    double value;
    if (p==1) // ��������� � ��������� ������� ������� � ���������� ������
    {
        usr_matrix->insertColumn(n+1);
        QTableWidgetItem *item = new QTableWidgetItem;
        item->setText(QString(QChar('x')));
        usr_matrix->setHorizontalHeaderItem(n+1,item);

        for (i=0;i<n;i++)
        {
            value=A[i]; //����� i �������
             QTableWidgetItem *item1 = new QTableWidgetItem;  //������ ����, ������� ������� � �������
             item1->setText(QString ("%1").arg(value)); // ����������  ����� � ����
             usr_matrix->setItem(i, n+1, item1); //���������� � �������
        }

    }
    else // ��������� � ��������� ������� ������� � "��������"
    {
        usr_matrix->insertColumn(n+2);
        QTableWidgetItem *item = new QTableWidgetItem;
        item->setText(tr("�������"));
        usr_matrix->setHorizontalHeaderItem(n+2,item);

        for (i=0;i<n;i++)
        {
             value=A[i]; //����� i �������
             QString str;
             QTableWidgetItem *item1 = new QTableWidgetItem;  //������ ����, ������� ������� � �������
             item1->setText(str.setNum(value)); // ����������  ����� � ����
             usr_matrix->setItem(i, n+2, item1); //���������� � �������
        }

    };

}

/* ��������� ������ �� ������� � ������� ��� ���������� */
double** MyWidget::tableToArray()
{
    int n = usr_dim -> text().toInt();
    int i,j;
    bool isOK = false;



    double** A = new double* [n]; //������� ������ ��� �������� �������
    for (i = 0; i < n ; i++)
         A[i]=new double [n+1];

    /* ���������� ������� ��������� ������� */

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

/* ��������� "�������" ��� ������� ����������� �������� */
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

/*���� ������������ �������� "�������" ��� ������������� ������ */
void MyWidget::setMaxNev(double *A)
{
    int n = usr_dim -> text().toInt();
    int i;
    double max = A[0];
    for (i=1; i<n; i++)
        if (max < A[i] )  max = A[i];

    dsp_maxNev -> setText(QString("%1").setNum(max, 'e'));
}

/*������� ��������� � �������� ���� ��������� ������ */
void MyWidget::badValue(int i, int j)
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::warning(this, tr("������"), tr("�� ����� ������������ �������� � ������. ���������, ��� �� ����� �����."));
    usr_matrix->item(i,j)->setBackgroundColor(Qt::red);
    return;
}

/* ������� ������ �� ���������� ������ ��������� */
void MyWidget::clearMem(double** A)
{
    int n = usr_dim->text().toInt();
    for(int i = 0; i < n; i++)
       delete[] A[i];
    delete A;
}

