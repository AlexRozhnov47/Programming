#include "mywidget.h"
#include <math.h>
#include <float.h>

/*Процедура выбора ведущего элемента */
void MyWidget::vedElem(double **A, int k)
{
    int n = usr_dim->text().toInt();
    int kmax=k;
    double det = 1.0;
    double Amod;
    double Amax=fabs(A[k][k]);
    if (k<n)
    {
        for (int i = k+1 ; i < n ; i++)
        {
            Amod=fabs(A[i][k]);
            if (Amod > Amax)
            {
                Amax=Amod;
                kmax=i;
            }
        }
    }
    if (fabs(Amax)<=DBL_EPSILON) //DBL_EPSILON - машинный ноль, для типа double
    {
        det=0.0;
        crash();
        return;
    }
    if (kmax!=k)
    {
        for (int j = k; j < n+1 ; j++)
        {
            double buf=A[k][j];
            A[k][j]=A[kmax][j];
            A[kmax][j]=buf;
        }
        det=-det;
    }
    det=det*A[k][k];

}

