#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "add_restaurant.h"
#include "add_students.h"
#include "add_types_subscriptions.h"
#include "formulaire_ajout_menu.h"
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QtSql>
#include <QtSql/QSqlRelation>
#include <QDebug>
#include <QMessageBox>
#include <iostream>
#include <QString>
#include <QCoreApplication>
#include <QtWidgets>
#include <QSqlTableModel>
#include "menu.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "formulaire_supprimer_menu.h"
#define q2c(string) string.toStdString()

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->table->setModel(tempmenu.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_Add_types_clicked()
{
    add_students add_students;
    add_students.setModal(true);
    add_students.exec();



    //add_types_subscriptions add_types;
    //add_types.setModal(true);
    //add_types.exec();
}

void MainWindow::on_pushButton_clicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Source_Projet2A");
    db.setUserName("Mehdi");
    db.setPassword("esprit18");
    bool connexion = db.open();
    if (connexion)
    {
        QMessageBox::information(this, "info", "connexion reussite");
        std::cout << "connected as "<< q2c(db.userName());
        db.close();

    }
    else
    {
        QMessageBox::information(this, "info", "connexion echoué");
    }
}

void MainWindow::on_Sub_clicked()
{

    ui->mini_menu->setCurrentIndex(0);
}

void MainWindow::on_Restaurants_clicked()
{
    ui->mini_menu->setCurrentIndex(1);
}

void MainWindow::on_Menu_clicked()
{


        ui->mini_menu->setCurrentIndex(2);
        model = new QSqlTableModel(this);
        model->setTable("MENUS");
        model->select();
        ui->table->setModel((model));


}

void MainWindow::on_Sensors_clicked()
{
    ui->mini_menu->setCurrentIndex(3);
}

void MainWindow::on_Notifications_clicked()
{
     ui->mini_menu->setCurrentIndex(4);
}

void MainWindow::on_Add_menus_clicked()
{
   Formulaire_ajout_menu form;
   form.setModal(true);
   form.exec();

}

void MainWindow::on_Add_Restau_clicked()
{
    Add_restaurant add_restau;
    add_restau.setModal(true);
    add_restau.exec();
}

void MainWindow::on_Refresh_menus_clicked()
{
    ui->table->setModel(tempmenu.afficher());
}

void MainWindow::on_Remove_menus_clicked()
{
 formulaire_supprimer_menu suppr_restau;
 suppr_restau.setModal(true);
 suppr_restau.exec();
}
