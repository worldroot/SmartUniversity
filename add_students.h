#ifndef ADD_STUDENTS_H
#define ADD_STUDENTS_H

#include <QDialog>

namespace Ui {
class add_students;
}

class add_students : public QDialog
{
    Q_OBJECT

public:
    explicit add_students(QWidget *parent = nullptr);
    ~add_students();

private slots:
    void on_Cancel_clicked();

    void on_Restau_selection_currentIndexChanged(const QString &arg1);

    void on_send_clicked();

    void on_cancel_clicked();

private:
    Ui::add_students *ui;
};

#endif // ADD_STUDENTS_H
