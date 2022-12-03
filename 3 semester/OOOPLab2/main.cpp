#include "mainwindow.h"

#include <QApplication>
#include <QLabel>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(":/resource/icons/icon.ico"));
    MainWindow w;
    w.show();
    return a.exec();
}
