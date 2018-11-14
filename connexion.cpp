#include "connexion.h"
#include <QMessageBox>
#include <QCoreApplication>
#include <QDebug>
#include "mainwindow.h"
#include <QString>


connexion::connexion()
{

}

bool connexion::ouvrir_connexion()
{
    bool test = false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Source_Projet2A");
    db.setUserName("Mehdi");
    db.setPassword("esprit18");
    if (db.open())
      {
        test=true;
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                          QObject::tr("connection successful.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
      }
    else
      {
        QMessageBox::information(nullptr, QObject::tr("database is not open"),
                           QObject::tr("connection failed.\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);
      }
    return  test;

}

void connexion::fermer_connexion()
{db.close();}
