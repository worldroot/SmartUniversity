#ifndef RESTAURANT_H
#define RESTAURANT_H
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlTableModel>
class Restaurant
{
private:
    int id;
    int nb_places;
    int nb_employes;
    int id_menu;

public:
    Restaurant();
    Restaurant(int,int,int,int);
    bool ajouter_Restaurant();
    bool supprimer_Restaurant(int id_supprimer);
    bool modifier_Restaurant(QString,QString,QString,QString);
    void consulter_Restaurant(int id);
    QSqlQueryModel * afficher();
    QSqlQueryModel * chercher(QString,QString);
    QSqlTableModel *tri(int num);
    int get_id();
    int get_nb_places();
    int get_nb_employes();
    int get_nb_capteurs();
    bool ajouter();

};

#endif // RESTAURANT_H
