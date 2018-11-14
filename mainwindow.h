#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsOpacityEffect>
#include <QSqlTableModel>
#include "menu.h"

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

private:
    Ui::MainWindow *ui;
    QSqlTableModel *model;
    Menu tempmenu;

};

#endif // MAINWINDOW_H
