#ifndef FORMULAIRE_AJOUT_MENU_H
#define FORMULAIRE_AJOUT_MENU_H

#include <QDialog>

namespace Ui {
class Formulaire_ajout_menu;
}

class Formulaire_ajout_menu : public QDialog
{
    Q_OBJECT

public:
    explicit Formulaire_ajout_menu(QWidget *parent = nullptr);
    ~Formulaire_ajout_menu();

private slots:
    void on_Cancel_clicked();

    void on_suivant_clicked();

    void on_terminer_clicked();

private:
    Ui::Formulaire_ajout_menu *ui;
};

#endif // FORMULAIRE_AJOUT_MENU_H
