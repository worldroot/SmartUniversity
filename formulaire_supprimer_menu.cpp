#include "formulaire_supprimer_menu.h"
#include "ui_formulaire_supprimer_menu.h"


#include <QString>

#include <QSqlQuery>
#include <QSqlDatabase>
#include <QtSql>
#include <QtSql/QSqlRelation>
#include <QDebug>
#include <QMessageBox>
#include <iostream>
#include <QString>
#include <QCoreApplication>
#include "menu.h"
#include<QSqlTableModel>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtWidgets>
formulaire_supprimer_menu::formulaire_supprimer_menu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::formulaire_supprimer_menu)
{
    ui->setupUi(this);
}

formulaire_supprimer_menu::~formulaire_supprimer_menu()
{
    delete ui;
}

void formulaire_supprimer_menu::on_suivant_clicked()
{
    int id = ui->lineEdit_id->text().toInt();
    bool test = tempmenu.supprimer_Menu(id);
    if(test== true)
    {
        QMessageBox::information(nullptr, QObject::tr("Supprimer un Menu"),
                        QObject::tr("Menu supprimé.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        ui->stackedWidget->setCurrentIndex(1);
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un Menu"),
                      QObject::tr("Erreur !.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void formulaire_supprimer_menu::on_Cancel_clicked()
{
        close();
}

void formulaire_supprimer_menu::on_terminer_clicked()
{
    close();
}
