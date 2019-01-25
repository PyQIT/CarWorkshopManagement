#include "mainwindow.h"
#include "mainwindow.cpp"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    menu();
    w.show();

    return a.exec();
}
