#include <QApplication>
#include "mywidget.h"
int main (int argc, char *argv[])
{
    QTextCodec::setCodecForTr(QTextCodec::codecForName("Windows-1251"));
        QApplication qapp(argc, argv);
        qapp.setOrganizationName("Krukovets Artem. K4-331");
        qapp.setApplicationName("Gauss 1.0");
        MyWidget myw;
        qapp.exec();
        return 0;
}
