#ifndef ETUDIANT_H
#define ETUDIANT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class etudiant
{
private:
    int id;
    QString nom;
    QString prenom;
    int id_classe;


public:
    etudiant();
    etudiant(int,QString,QString,int);
    QSqlQueryModel * afficher();

};

#endif // ETUDIANT_H
