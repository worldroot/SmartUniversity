#include "add_students.h"
#include "ui_add_students.h"
#include "restaurant.h"
#include "etudiant.h"
#include "abonne_restaurant.h"
#include <QMessageBox>
add_students::add_students(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::add_students)
{
    ui->setupUi(this);
    Restaurant res;
    etudiant e;
    Abonne_Restaurant temp;
    ui->Restau_selection->setModel(res.afficher());
    ui->Etudiant_selection->setModel(e.afficher());
    ui->table->setModel(temp.afficher());
    ui->alerte->hide();
     // ui->alerte->visibleRegion();
     // ui->alerte->show();
}

add_students::~add_students()
{
    delete ui;
}

void add_students::on_Cancel_clicked()
{
    close();
}

void add_students::on_Restau_selection_currentIndexChanged(const QString &arg1)
{

}

void add_students::on_send_clicked()
{

    int id;
    QDate debut;
    QDate fin;
    QString type;
    int id_resto;
    int id_etudiant;

id= ui->lineEdit_id->text().toInt();
id_resto = ui->Restau_selection->currentText().toInt();
id_etudiant = ui->Etudiant_selection->currentText().toInt();
type = ui->lineEdit_type->text();
debut = ui->dateEdit->date();
fin = ui->dateEdit_2->date();
if (type == "Pension-complete" || type =="Demi-Pension")
{
    Abonne_Restaurant abon(id,debut,fin,type,id_resto,id_etudiant);
    bool test = abon.ajouter_Abonne_Restaurant();
        if (test == true)
        {
            QMessageBox::information(nullptr, QObject::tr("Ajouter un Abonnement"),
                              QObject::tr("Abonnement ajouté.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);


        }

}
else {
    QMessageBox::information(nullptr, QObject::tr("Ajouter un Abonnement"),
                      QObject::tr("Abonnement ERREUR TYPE(Demi-Pension,Pension-complete).\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);
      ui->alerte->show();
}


}


void add_students::on_cancel_clicked()
{
    close();
}
