#ifndef RESTAURANT_H
#define RESTAURANT_H


class Restaurant
{
private:
    int id;
    int nb_places;
    int nb_employes;
    int nb_capteurs;
public:
    Restaurant();
    Restaurant(int,int,int,int);
    void ajouter_Restaurant(Restaurant);
    void supprimer_Restaurant(int id);
    void modifier_Restaurant(int id);
    void consulter_Restaurant(int id);
    int get_id();
    int get_nb_places();
    int get_nb_employes();
    int get_nb_capteurs();
    bool ajouter();

};

#endif // RESTAURANT_H
