#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsOpacityEffect>
#include <QSqlTableModel>
#include "menu.h"
#include "Smtp.h"
#include "restaurant.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:


    void on_Add_types_clicked();

    void on_pushButton_clicked();

    void on_Sub_clicked();

    void on_Restaurants_clicked();

    void on_Menu_clicked();

    void on_Sensors_clicked();

    void on_Notifications_clicked();

    void on_Add_menus_clicked();


    void on_Add_Restau_clicked();

    void on_Refresh_menus_clicked();

    void on_Remove_menus_clicked();

    void on_table_activated(const QModelIndex &index);

    void on_Update_menu_clicked();

    void on_SendMail_clicked();
    void mailSent(QString);
    void on_Remove_Restau_clicked();

private:
    Ui::MainWindow *ui;
    QSqlTableModel *model;
    QSqlTableModel *model1;
    Menu tempmenu;
    Restaurant temprestau;

};

#endif // MAINWINDOW_H
