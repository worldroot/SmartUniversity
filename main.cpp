#include "mainwindow.h"
#include <QApplication>
#include <QFile>
#include "connexion.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    connexion c;
    c.ouvrir_connexion();
    w.show();

    return a.exec();
}
