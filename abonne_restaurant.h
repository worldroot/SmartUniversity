#ifndef ABONNE_RESTAURANT_H
#define ABONNE_RESTAURANT_H
#include<QDate>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Abonne_Restaurant
{
private:
    int id;
    QDate debut;
    QDate fin;
    QString type;
    int id_resto;
    int id_etudiant;

public:
    Abonne_Restaurant();
    Abonne_Restaurant(int,QDate,QDate,QString,int,int);
    bool ajouter_Abonne_Restaurant();
    QSqlQueryModel * afficher();
    void modifier_Abonne_Restaurant();
    void supprimer_Abonne_Restaurant();
    int get_id();
    QDate get_debut();
    QDate get_fin();
    int get_type();
};

#endif // ABONNE_RESTAURANT_H
