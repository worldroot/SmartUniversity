#ifndef ADD_TYPES_SUBSCRIPTIONS_H
#define ADD_TYPES_SUBSCRIPTIONS_H

#include <QDialog>

namespace Ui {
class add_types_subscriptions;
}

class add_types_subscriptions : public QDialog
{
    Q_OBJECT

public:
    explicit add_types_subscriptions(QWidget *parent = nullptr);
    ~add_types_subscriptions();

private slots:
    void on_Cancel_clicked();

private:
    Ui::add_types_subscriptions *ui;
};

#endif // ADD_TYPES_SUBSCRIPTIONS_H
