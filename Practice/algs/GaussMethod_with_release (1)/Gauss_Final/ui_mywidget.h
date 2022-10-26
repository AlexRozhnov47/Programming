/********************************************************************************
** Form generated from reading UI file 'mywidget.ui'
**
** Created: Thu 12. Apr 23:55:57 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYWIDGET_H
#define UI_MYWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyWidget
{
public:
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menu;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MyWidget)
    {
        if (MyWidget->objectName().isEmpty())
            MyWidget->setObjectName(QString::fromUtf8("MyWidget"));
        MyWidget->resize(400, 300);
        centralWidget = new QWidget(MyWidget);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        MyWidget->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MyWidget);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 26));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        MyWidget->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MyWidget);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MyWidget->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MyWidget);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MyWidget->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());

        retranslateUi(MyWidget);

        QMetaObject::connectSlotsByName(MyWidget);
    } // setupUi

    void retranslateUi(QMainWindow *MyWidget)
    {
        MyWidget->setWindowTitle(QApplication::translate("MyWidget", "MyWidget", 0, QApplication::UnicodeUTF8));
        menu->setTitle(QApplication::translate("MyWidget", "\320\241\320\277\320\260\321\200\320\262\320\272\320\260", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MyWidget: public Ui_MyWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYWIDGET_H
