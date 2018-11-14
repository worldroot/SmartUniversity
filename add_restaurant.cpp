#include "add_restaurant.h"
#include "ui_add_restaurant.h"

Add_restaurant::Add_restaurant(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Add_restaurant)
{
    ui->setupUi(this);
}

Add_restaurant::~Add_restaurant()
{
    delete ui;
}

void Add_restaurant::on_Cancel_clicked()
{
    close();
}
