#include "abonne_restaurant.h"
#include "connexion.h"

Abonne_Restaurant::Abonne_Restaurant()
{

}

Abonne_Restaurant::Abonne_Restaurant(int id,QDate debut,QDate fin,QString type,int id_resto,int id_etudiant)
{
    this->id = id;
    this->debut= debut;
    this->fin=fin;
    this->type = type;
    this->id_resto=id_resto;
    this->id_etudiant = id_etudiant;
}

bool Abonne_Restaurant::ajouter_Abonne_Restaurant()
{
    connexion c;
    QSqlQuery query;
    QString id_string = QString::number(id);
     QString id_resto_string = QString::number(id_resto);
      QString id_etudiant_string = QString::number(id_etudiant);
    query.prepare("INSERT INTO abonnement_resto(ID,DEBUT,FIN,ID_ETUDIANT,ID_RESTO,TYPE) VALUES(:ID, :DEBUT, :FIN, :ID_ETUDIANT, :ID_RESTO, :TYPE) ");
    query.bindValue(":ID", id_string);
    query.bindValue(":DEBUT", debut);
    query.bindValue(":FIN", fin);
    query.bindValue(":ID_ETUDIANT", id_etudiant);
    query.bindValue(":ID_RESTO", id_resto);
    if (query.exec()== true)
    {
          return(true);
    }
 return(query.exec());
}
