#include "etudiant.h"

etudiant::etudiant()
{

}


  etudiant::etudiant(int id,QString nom,QString prenom,int id_classe)
  {
      this->id=id;
      this->nom=nom;
      this->prenom=prenom;
      this->id_classe=id_classe;


  }
QSqlQueryModel * etudiant::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from etudiants");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("PRENOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("ID_CLASSE"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("LOGIN"));
        return model;
}
