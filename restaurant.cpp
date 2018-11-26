#include "restaurant.h"
#include "connexion.h"
Restaurant::Restaurant()
{

}


Restaurant::Restaurant(int id,int id_menu,int nb_employes,int nb_places)
{
    this->id = id;
    this->id_menu = id_menu;
    this->nb_employes = nb_employes;
    this->nb_places = nb_places;
}

bool Restaurant::ajouter_Restaurant()
{
    connexion c;
    QSqlQuery query;
    QString id_string = QString::number(id);
    QString id_menu_string = QString::number(id_menu);
    QString nb_employes_string = QString::number(nb_employes);
    QString nb_places_string = QString::number(nb_places);

    query.prepare("INSERT INTO resto(ID,NB_PLACES,NB_EMPLOYES,ID_MENU) VALUES(:ID, :NB_PLACES, :NB_EMPLOYES, :ID_MENU) ");
    query.bindValue(":ID", id_string);
    query.bindValue(":ID_MENU", id_menu_string);
    query.bindValue(":NB_EMPLOYES", nb_employes_string);
    query.bindValue(":NB_PLACES", nb_places_string);
    if (query.exec()== true)
    {
          return(true);
    }
 return(query.exec());
}

QSqlQueryModel *Restaurant::afficher()
{
        QSqlQueryModel * model= new QSqlQueryModel();
        model->setQuery("select * from resto");
        model->setHeaderData(0, Qt::Horizontal,QObject::tr("ID"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("NB_PLACES"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("NB_EMPLOYES"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("ID_MENU"));
            return model;
}

bool Restaurant::supprimer_Restaurant(int id_supprimer)
{
    QSqlQuery query;
    QString res= QString::number(id_supprimer);
    query.prepare("Delete from resto where ID = :id ");
    query.bindValue(":id", res);
    return    query.exec();
}

QSqlQueryModel *Restaurant::chercher(QString a, QString b)
{
    QSqlQueryModel * model= new QSqlQueryModel();
      if (a=="1")
      {
          model->setQuery("select * from resto where NB_PLACES='"+b+"' ");
      }
      if (a=="2")
      {
          model->setQuery("select * from resto where NB_EMPLOYES='"+b+"' ");
      }
     return model;
}
