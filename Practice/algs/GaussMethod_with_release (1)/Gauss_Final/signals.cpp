#include "mywidget.h"
#include <QTableWidget>
#include <QHBoxLayout>
#include <iostream>
#include <iomanip>
#include <stdlib.h>

void MyWidget::help() //������� � ���������
    {
        QMessageBox::question(this, tr("� ���������"),
                 tr("<center> <b> ��� ��������� ������������� ��� ������� ������ �������� ��������� ������� ������ � ������������ ������������� ��������� ������ �������� ��������.</b> </center> <BR> "
                    "<BR>"
                    " <u> ��� ������ ������������� ��������� ��� ����������</u> : <BR>"
                    "<BR>""<BR>"
                    "1. ������ ����������� ����������� (������� ����������� �������)<BR> ""<BR>"
                    "2. ��������� �������, ��� �� ����� i,j ��������  <BR>"
                    " ������� i,j �����������, ������� ����� ��������������� ����������<BR>"
                    "   (��� ��������������� ������� � ������������ ������� ��������� �������)<BR>""<BR>"
                    "3. ��� ������������� ������� ������� ������������� ��������� ������ �������� ��������<BR>""<BR>"
                    "4. ������ �� ������ \"������ �������\".<BR>""<BR>"
                    "5. � ������� �������� ��� ����� ������� \"X\" � \"�������\", <BR> "
                    " ������������ ����� � ��� �������� ��������������."));
    }

void MyWidget::setMatrixSize()  //������������ ������ �������
{

    int n = usr_dim->text().toInt();

    /*���� �������� ����������� �������*/

    if(usr_matrix->columnCount() > n+1)
    {
        usr_matrix -> removeColumn(n); //������� ������� �����
        usr_matrix -> removeColumn(n); //������� ������� � ��������
        usr_matrix -> clearContents(); //������� �� ������� ��� ��������� � ��� ������
    }

    usr_matrix->setColumnCount(n+1);
    usr_matrix->setRowCount(n);
}
void MyWidget::randValue() // ��������� ������� ���������� ����������
{
    int n = usr_dim->text().toInt();
    int i,j;
    double value;
    for (i=0;i<n;i++)
    {
     for (j=0; j<n+1; j++)
        {
         value=-500+rand()%500; //���������� ����� � ��������� �� -200 �� 200
         if (value!=0) {value=(-15+rand()%15)/value;} //��������� �� 0 � ����� �� ������ �������� �����
         QTableWidgetItem *item1 = new QTableWidgetItem;  //������ ����, ������� ������� � �������
         item1->setText(QString ("%1").arg(value)); // ����������  ����� � ����
         usr_matrix->setItem(i, j, item1); //���������� � �������
        }
    }
}
void MyWidget::crash() // ��������� ���������� ���������
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::information(this, tr("������"), tr("������� �����������"));
}
void MyWidget::menuExit()
{
    qApp->quit();
}

