#include "add_types_subscriptions.h"
#include "ui_add_types_subscriptions.h"

add_types_subscriptions::add_types_subscriptions(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::add_types_subscriptions)
{
    ui->setupUi(this);
}

add_types_subscriptions::~add_types_subscriptions()
{
    delete ui;
}

void add_types_subscriptions::on_Cancel_clicked()
{
    close();
}
