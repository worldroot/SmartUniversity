#ifndef FORMULAIRE_SUPPRIMER_MENU_H
#define FORMULAIRE_SUPPRIMER_MENU_H

#include <QDialog>
#include "menu.h"

namespace Ui {
class formulaire_supprimer_menu;
}

class formulaire_supprimer_menu : public QDialog
{
    Q_OBJECT

public:
    explicit formulaire_supprimer_menu(QWidget *parent = nullptr);
    ~formulaire_supprimer_menu();

private slots:
    void on_suivant_clicked();

    void on_Cancel_clicked();

    void on_terminer_clicked();

private:
    Ui::formulaire_supprimer_menu *ui;
    Menu tempmenu;
};

#endif // FORMULAIRE_SUPPRIMER_MENU_H
