#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"particula.h"
#include<QGraphicsScene>
#include<QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_startButton_clicked();
    void actualizarAnimacion();

    void on_Add_clicked();

    void on_mas_clicked();

    void on_menos_clicked();

    void on_Remove_clicked();

private:
    Ui::MainWindow *ui;
    Particula *particula[20];
    QGraphicsScene *escena;
    QTimer *timer;
};
#endif // MAINWINDOW_H
