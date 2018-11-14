#include "menu.h"
#include "connexion.h"
#include <QMessageBox>
Menu::Menu()
{
    id=0;
    nom="";
    description="";
}

Menu::Menu(int id,QString nom,QString description)
{
    this->id=id;
    this->nom=nom;
    this->description=description;
}

int Menu::get_id() {return id;}

QString Menu::get_nom() {return  nom;}

QString Menu::get_description() {return description;}

bool Menu::ajouter_Menu()
{
  connexion c;
  QSqlQuery query;
  QString id_string = QString::number(id);
  query.prepare("INSERT INTO menus(NOM,DESCRIPTION,ID) VALUES(:NOM, :DESCRIPTION, :ID)");
  query.bindValue(":NOM", nom);
  query.bindValue(":DESCRIPTION",description);
  query.bindValue(":ID",id_string);
    if (query.exec()== true)
    {
          return(true);
    }
 return(query.exec());

}

QSqlQueryModel * Menu::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from menus");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("DESCRIPTION"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("ID"));
        return model;
}

bool Menu::supprimer_Menu(int id_supprimer)
{
    QSqlQuery query;
    QString res= QString::number(id_supprimer);
    query.prepare("Delete from menus where ID = :id ");
    query.bindValue(":id", res);
    return    query.exec();
}
