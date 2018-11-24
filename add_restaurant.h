#ifndef ADD_RESTAURANT_H
#define ADD_RESTAURANT_H

#include <QDialog>

namespace Ui {
class Add_restaurant;
}

class Add_restaurant : public QDialog
{
    Q_OBJECT

public:
    explicit Add_restaurant(QWidget *parent = nullptr);
    ~Add_restaurant();

private slots:
    void on_Cancel_clicked();

    void on_send_clicked();

    void on_cancel_clicked();

private:
    Ui::Add_restaurant *ui;
};

#endif // ADD_RESTAURANT_H
