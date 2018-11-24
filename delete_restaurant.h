#ifndef DELETE_RESTAURANT_H
#define DELETE_RESTAURANT_H

#include <QDialog>

namespace Ui {
class delete_restaurant;
}

class delete_restaurant : public QDialog
{
    Q_OBJECT

public:
    explicit delete_restaurant(QWidget *parent = nullptr);
    ~delete_restaurant();

private slots:
    void on_send_clicked();

    void on_cancel_clicked();

private:
    Ui::delete_restaurant *ui;
};

#endif // DELETE_RESTAURANT_H
