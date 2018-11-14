#ifndef ABONNE_RESTAURANT_H
#define ABONNE_RESTAURANT_H
#include<QDate>

class Abonne_Restaurant
{
private:
    int id;
    QDate debut;
    QDate fin;
    int type;
public:
    Abonne_Restaurant();
    Abonne_Restaurant(int,QDate,QDate);
    void ajouter_Abonne_Restaurant();
    void afficher_Abonne_Restaurant();
    void modifier_Abonne_Restaurant();
    void supprimer_Abonne_Restaurant();
    int get_id();
    QDate get_debut();
    QDate get_fin();
    int get_type();
};

#endif // ABONNE_RESTAURANT_H
