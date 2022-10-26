#include "mywidget.h"
#include <QMainWindow>
#include <QTableWidget>
#include <QHBoxLayout>
#include <iomanip>
#include <stdlib.h>
#include <qtextcodec.h>


MyWidget::MyWidget ()
{
    QMainWindow *MainForm = new QMainWindow;
    QWidget *window = new QWidget;//������ ������
    QTextCodec::setCodecForTr(QTextCodec::codecForName("Windows-1251")); //���������� ����� ��� ���������
    window->setWindowTitle(tr("������� ������� ��������� ������� ������"));


    menu = new QMenuBar;
    MainForm->setMenuBar(menu);

    QAction *newHelp = new QAction(tr("�������"), this);
    newHelp->setShortcut(tr("Ctrl+H"));
    connect(newHelp, SIGNAL(triggered()), this, SLOT( help() ) );
    MainForm->menuBar()->addAction(newHelp);
    QAction *newExit = new QAction(tr("�����"), this);
    newExit->setShortcut(tr("Alt+F4"));
    connect(newExit, SIGNAL(triggered()), this, SLOT( menuExit() ) );
    MainForm->menuBar()->addAction(newExit);

    /* ������� ������� */
    lbl_dim = new QLabel(tr("�����������"));  //������ �������
    lbl_matrix = new QLabel(tr("����������� ������� ������� :"));
    lbl_maxNev = new QLabel(tr("������������ ������� :"));

    /* ������� ����, ������ ������������ ������ ������������� */
    usr_dim = new QSpinBox(this);            //������ ���� ��� �����
    usr_matrix = new QTableWidget(2,3);      //������ �������
    usr_vedelm = new QCheckBox(tr("������������ ��������� ������ �������� ��������"),this);  //������� �������
    usr_newMatrix = new QCheckBox(tr("�������� ��������������� �������"),this);
    usr_dim->setValue(2);
    usr_dim->setMinimum(2); //������������ ����������� �������� ��� �����������
    usr_dim->setMaximumWidth(100);

    /* ������� ������ */
    btn_rand = new QPushButton(tr("��������� ������� ���������� �������")); //������ ������
    btn_solve = new QPushButton(tr("������ �������"));
    dsp_maxNev = new QLineEdit(this);
    dsp_maxNev->setEnabled(0);
    dsp_maxNev->setMaximumWidth(100);

    /* ������������ ����� ����� ��������� ��������� � �������, ������� ����� �� ������������ */
    QObject::connect (usr_dim, SIGNAL (valueChanged(int)), this, SLOT(setMatrixSize()));
    QObject::connect (btn_rand, SIGNAL (clicked()), this, SLOT(randValue()));
    QObject::connect (btn_solve, SIGNAL (clicked()), this, SLOT(mSolve()));

    /* ������ �������. � ������� ����� ���� �������� � ���������� */
    QHBoxLayout *topLayout = new QHBoxLayout;
    topLayout -> addWidget(lbl_dim);
    topLayout -> addWidget(usr_dim);
    topLayout -> addStretch();
    QVBoxLayout *middleLayout = new QVBoxLayout;
    middleLayout -> addWidget(usr_vedelm);
    middleLayout -> addWidget(usr_newMatrix);
    middleLayout -> addWidget(lbl_matrix);
    middleLayout -> addWidget(usr_matrix);
    QHBoxLayout *middle2Layout = new QHBoxLayout;
    middle2Layout -> addWidget(lbl_maxNev);
    middle2Layout -> addWidget(dsp_maxNev);
    middle2Layout -> addStretch();
    QHBoxLayout *middle3Layout = new QHBoxLayout;
    middle3Layout -> addWidget(btn_rand);
    middle3Layout -> addWidget(btn_solve);
    QVBoxLayout *mainLayout = new QVBoxLayout;
    //mainLayout->addLayout (Menu);
    mainLayout->addLayout (topLayout);
    mainLayout->addLayout (middleLayout);
    mainLayout->addLayout (middle2Layout);
    mainLayout->addLayout (middle3Layout);
    window ->setLayout(mainLayout);
    MainForm->setCentralWidget(window);
    MainForm->setMinimumHeight(450);
    MainForm->setMinimumWidth(645);
    MainForm->show();

}


MyWidget::~MyWidget ()
{
}


