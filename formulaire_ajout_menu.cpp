#include "formulaire_ajout_menu.h"
#include "ui_formulaire_ajout_menu.h"
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
Formulaire_ajout_menu::Formulaire_ajout_menu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Formulaire_ajout_menu)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
}

Formulaire_ajout_menu::~Formulaire_ajout_menu()
{
    delete ui;
}

void Formulaire_ajout_menu::on_Cancel_clicked()
{
    close();
}

void Formulaire_ajout_menu::on_suivant_clicked()
{

    QString name,description;
    int id;
    name= ui->nom->text();
    description = ui->description->text();
    id = ui->Id->text().toInt();

    Menu m(id,name,description);
    bool test = m.ajouter_Menu();
    if(test== true)
    {
    QMessageBox::information(nullptr, QObject::tr("Ajouter un menu"),
                      QObject::tr("Menu ajouté.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

        ui->stackedWidget->setCurrentIndex(1);
    }


}

void Formulaire_ajout_menu::on_terminer_clicked()
{
    close();
}
