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
#include "Smtp.h"
#include "delete_restaurant.h"
#include "restaurant.h"

#define q2c(string) string.toStdString()

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    Restaurant r;
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
    ui->tableView_2->setModel(tempabo.afficher());
}

void MainWindow::on_Restaurants_clicked()
{
    ui->mini_menu->setCurrentIndex(1);
     ui->table_3->setModel(temprestau.afficher());
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

void MainWindow::on_table_activated(const QModelIndex &index)
{


    QString val = ui->table->model()->data(index).toString();
    QSqlQuery qry;
    qry.prepare("select * from menus where NOM='"+val+"' or DESCRIPTION='"+val+"' or ID='"+val+"'    ");
    if(qry.exec())
    {
        while(qry.next())
        {
                ui->txt_nom1->setText(qry.value(0).toString());
                ui->txt_description->setText(qry.value(1).toString());
                ui->txt_id->setText(qry.value(2).toString());
        }
    }

}

void MainWindow::on_Update_menu_clicked()
{
    QString nom,description,id;
    nom = ui->txt_nom1->text();
    description = ui->txt_description->text();
    id = ui->txt_id->text();


    Menu m;
    m.modifier_Menu(nom,description,id);
   // QSqlQuery qry;
   //qry.prepare("update menus set NOM='"+nom+"',DESCRIPTION='"+description+"',ID='"+id+"' where id='"+id+"' ");
    if(m.modifier_Menu(nom,description,id))
      {
        QMessageBox::information(nullptr, QObject::tr(" menu mis a jour"),
                        QObject::tr("Menu mis a jour.\n"));
      }
   #

}



void MainWindow::on_SendMail_clicked()
{
    Smtp* smtp = new Smtp("mehdi.behira@esprit.tn", "esprit2017", "smtp.gmail.com",465);
     connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

     smtp->sendMail("mehdi.behira@esprit.tn", "mehdibehira@gmail.com" , "This is a subject","This is a body");
}


void MainWindow::mailSent(QString status)
{
    if(status == "Message sent")
        QMessageBox::warning( 0, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
}

void MainWindow::on_Remove_Restau_clicked()
{   delete_restaurant delete_restau;
   delete_restau.setModal(true);
    delete_restau.exec();
}

void MainWindow::on_chercher_clicked()
{
    Restaurant r;
    QString chercher = ui->lineEdit_chercher->text();
    ui->tableView->setModel((r.chercher(x,chercher)));
}

void MainWindow::on_radioButton_clicked()
{
    x="1";
}

void MainWindow::on_radioButton_2_clicked()
{
    x="2";
}
