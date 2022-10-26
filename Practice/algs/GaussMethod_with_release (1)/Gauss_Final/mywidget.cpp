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
    QWidget *window = new QWidget;//создаём виджет
    QTextCodec::setCodecForTr(QTextCodec::codecForName("Windows-1251")); //подключаем кодек для кириллицы
    window->setWindowTitle(tr("Решение системы уравнений методом Гаусса"));


    menu = new QMenuBar;
    MainForm->setMenuBar(menu);

    QAction *newHelp = new QAction(tr("Справка"), this);
    newHelp->setShortcut(tr("Ctrl+H"));
    connect(newHelp, SIGNAL(triggered()), this, SLOT( help() ) );
    MainForm->menuBar()->addAction(newHelp);
    QAction *newExit = new QAction(tr("Выход"), this);
    newExit->setShortcut(tr("Alt+F4"));
    connect(newExit, SIGNAL(triggered()), this, SLOT( menuExit() ) );
    MainForm->menuBar()->addAction(newExit);

    /* Создаем надписи */
    lbl_dim = new QLabel(tr("Размерность"));  //создаём надписи
    lbl_matrix = new QLabel(tr("Расширенная матрица системы :"));
    lbl_maxNev = new QLabel(tr("Максимальная невязка :"));

    /* Создаем поля, которе пользователь сможет редактировать */
    usr_dim = new QSpinBox(this);            //создаём бокс для чисел
    usr_matrix = new QTableWidget(2,3);      //создаём таблицу
    usr_vedelm = new QCheckBox(tr("Использовать процедуру выбора ведущего элемента"),this);  //создаем чекбокс
    usr_newMatrix = new QCheckBox(tr("Выводить преобразованную матрицу"),this);
    usr_dim->setValue(2);
    usr_dim->setMinimum(2); //ограничиваем минимальное значение для размерности
    usr_dim->setMaximumWidth(100);

    /* Создаем кнопки */
    btn_rand = new QPushButton(tr("Заполнить матрицу случайными числами")); //создаём кнопки
    btn_solve = new QPushButton(tr("Решить систему"));
    dsp_maxNev = new QLineEdit(this);
    dsp_maxNev->setEnabled(0);
    dsp_maxNev->setMaximumWidth(100);

    /* Устаналиваем связь между сигналами элементов и слотами, которые будут их обрабатывать */
    QObject::connect (usr_dim, SIGNAL (valueChanged(int)), this, SLOT(setMatrixSize()));
    QObject::connect (btn_rand, SIGNAL (clicked()), this, SLOT(randValue()));
    QObject::connect (btn_solve, SIGNAL (clicked()), this, SLOT(mSolve()));

    /* Создаём лейауты. в которые кладём наши элементы и группируем */
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


