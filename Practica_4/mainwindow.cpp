#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <cstdlib>

#define VERTLIM 230
#define HORZLIM 690

float speed = 2;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    this->resize(780, 400);
    this->setFixedSize(780, 400);

    escena = new QGraphicsScene(this);
    escena->setSceneRect(0,0,700,240);
    ui->graphicsView->setScene(escena);

    particula[0] = new Particula(20 + rand()%600,20 + rand()%150,8,8,20 + rand()%40);
    escena->addItem(particula[0]);
    particula[0]->moverParticula(speed);

    timer = new QTimer(this);
    timer->stop();
    connect(timer, SIGNAL(timeout()), this, SLOT(actualizarAnimacion()));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete timer;
    delete *particula;
    delete escena;
}

int numParticula = 1;
void MainWindow::on_startButton_clicked()
{
    timer->start(100);
}

void MainWindow::actualizarAnimacion(){
    for (int i = 0; i < numParticula; i++){
        particula[i]->moverParticula(speed);
        particula[i]->colisonParticula(VERTLIM, HORZLIM, particula, i, numParticula);
    }
}

void MainWindow::on_Add_clicked()
{
    particula[numParticula] = new Particula(20 + rand()%600,20 + rand()%150,8,8, 20 + rand()%40);
    escena->addItem(particula[numParticula]);
    particula[numParticula]->moverParticula(speed);

    numParticula++;
}

void MainWindow::on_Remove_clicked() //Intento de remover particula :c
{
   particula[numParticula]->removeParticula();
   particula[numParticula] = nullptr;
   numParticula--;
}
void MainWindow::on_mas_clicked()
{
    speed++;
}

void MainWindow::on_menos_clicked()
{
    speed--;
}
