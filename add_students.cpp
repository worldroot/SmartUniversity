#include "add_students.h"
#include "ui_add_students.h"

add_students::add_students(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::add_students)
{
    ui->setupUi(this);
}

add_students::~add_students()
{
    delete ui;
}

void add_students::on_Cancel_clicked()
{
    close();
}
