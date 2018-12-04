#ifndef DELETE_ABONNEMENT_RESTO_H
#define DELETE_ABONNEMENT_RESTO_H

#include <QDialog>

namespace Ui {
class Delete_abonnement_resto;
}

class Delete_abonnement_resto : public QDialog
{
    Q_OBJECT

public:
    explicit Delete_abonnement_resto(QWidget *parent = nullptr);
    ~Delete_abonnement_resto();

private slots:
    void on_send_clicked();

    void on_cancel_clicked();

private:
    Ui::Delete_abonnement_resto *ui;
};

#endif // DELETE_ABONNEMENT_RESTO_H
