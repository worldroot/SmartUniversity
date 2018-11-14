#ifndef CONNEXION_H
#define CONNEXION_H
#include <QSqlDatabase>

class connexion
{
private:
    QSqlDatabase db;
public:
    connexion();
    bool ouvrir_connexion();
    void fermer_connexion();
};

#endif // CONNEXION_H
