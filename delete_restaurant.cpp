#include "delete_restaurant.h"
#include "ui_delete_restaurant.h"
#include "restaurant.h"
#include <QMessageBox>
#include "mainwindow.h"
#include "ui_mainwindow.h"

delete_restaurant::delete_restaurant(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::delete_restaurant)
{
    Restaurant r;
    ui->setupUi(this);
    ui->table->setModel(r.afficher());

}

delete_restaurant::~delete_restaurant()
{
    delete ui;
}

void delete_restaurant::on_send_clicked()
{
     Restaurant temp;
     Restaurant r;
    int id = ui->lineEdit_id->text().toInt();
    bool test = temp.supprimer_Restaurant(id);
    if(test== true)
    {
        QMessageBox::information(nullptr, QObject::tr("Supprimer un Restau"),
                        QObject::tr("Restau supprimé.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un Restau"),
                      QObject::tr("Erreur !.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);
    }
    ui->table->setModel(r.afficher());
}

void delete_restaurant::on_cancel_clicked()
{
    close();
}
