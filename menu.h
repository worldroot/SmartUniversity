#ifndef MENU_H
#define MENU_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Menu
{
private:
    int id;
    QString nom;
    QString description;

public:
    Menu();
    Menu(int,QString,QString);
    bool ajouter_Menu();
    QSqlQueryModel * afficher();
    bool supprimer_Menu(int id_supprimer);
    void afficher_Menu(int id);
    bool modifier_Menu(QString,QString,QString);
    int get_id();
    QString get_nom();
    QString get_description();

};

#endif // MENU_H
