#include <qmainwindow.h>
#include <qpushbutton.h>
#include <qlineedit.h>
#include <qlabel.h>
#include <qstring.h>
#include <QTableWidget>
#include <QSpinBox>
#include <QtGui>
#include <qmenu.h>
class MyWidget : public QMainWindow
{
    Q_OBJECT
    private:
        QMenuBar *menu;
        QLabel *lbl_dim;
        QLabel *lbl_matrix;
        QLabel *lbl_maxNev;
        QSpinBox *usr_dim;
        QTableWidget *usr_matrix;
        QCheckBox *usr_vedelm;
        QCheckBox *usr_newMatrix;
        QPushButton *btn_rand;
        QPushButton *btn_solve;
        QLineEdit *dsp_maxNev;
    public:

        MyWidget ();
        ~MyWidget();
        void vedElem(double **A, int k);
        void newValue(double *A, int p);
        void newValue(double** A);
        void clearMem(double **A);
        void findSolution(double **A, double** B);
        double** tableToArray();
        void nevyazka(double **A, double* X);
        void setMaxNev(double *A);
        void badValue (int i, int j);

    public slots:
        void setMatrixSize();
        void randValue();
        void mSolve();
        void crash();
        void help();
        void menuExit();
};
