#include "add_restaurant.h"
#include "ui_add_restaurant.h"
#include "restaurant.h"
#include <QMessageBox>
#include "menu.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlTableModel>
Add_restaurant::Add_restaurant(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Add_restaurant)
{
    Menu temp;
    ui->setupUi(this);
    ui->table->setModel(temp.afficher());
}

Add_restaurant::~Add_restaurant()
{
    delete ui;  
}

void Add_restaurant::on_Cancel_clicked()
{
    close();
}

void Add_restaurant::on_send_clicked()
{
    int id,nb_places,nb_employes,id_menu;
    id= ui->lineEdit_id->text().toInt();
    nb_places= ui->lineEdit_places->text().toInt();
    nb_employes =ui->lineEdit_employes->text().toInt();
    id_menu= ui->lineEdit_menu->text().toInt();
    Restaurant R(id,id_menu,nb_employes,nb_places);
    bool test = R.ajouter_Restaurant();
    if (test == true)
    {
        QMessageBox::information(nullptr, QObject::tr("Ajouter un Restaurant"),
                          QObject::tr("Restaurant ajouté.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);


    }

}

void Add_restaurant::on_cancel_clicked()
{
    close();
}
