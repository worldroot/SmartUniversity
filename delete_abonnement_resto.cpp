#include "delete_abonnement_resto.h"
#include "ui_delete_abonnement_resto.h"
#include "restaurant.h"
#include "etudiant.h"
#include "abonne_restaurant.h"
#include <QMessageBox>

Delete_abonnement_resto::Delete_abonnement_resto(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Delete_abonnement_resto)
{
    ui->setupUi(this);
}

Delete_abonnement_resto::~Delete_abonnement_resto()
{
    delete ui;
}

void Delete_abonnement_resto::on_send_clicked()
{
    Abonne_Restaurant temp;
    Abonne_Restaurant r;
   int id = ui->lineEdit_id->text().toInt();
   bool test = temp.supprimer_Abonnement_Restaurant(id);
   if(test== true)
   {
       QMessageBox::information(nullptr, QObject::tr("Supprimer un Abonnement"),
                       QObject::tr("Abonnement supprimé.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);
   }
   else
   {
       QMessageBox::critical(nullptr, QObject::tr("Supprimer un Abonnement"),
                     QObject::tr("Erreur !.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);
   }

}

void Delete_abonnement_resto::on_cancel_clicked()
{
    close();
}
