#include "particula.h"
#include<iostream>
using namespace std;

Particula::Particula(){}
Particula::~Particula(){}

Particula::Particula(float x, float y, float vel_x, float vel_y, float rad):QGraphicsItem()
{
    pos_x = x;
    pos_y = y;
    this->vel_x = vel_x;
    this->vel_y = vel_y;
    radio = rad;
}

QRectF Particula::boundingRect() const{
    return QRectF(-1*radio, -1*radio, 2*radio, 2*radio);
}

void Particula::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    int color = rand()%6;

    if (color == 1){
        painter->setBrush(Qt::darkYellow);
    }
    else if (color == 2){
        painter->setBrush(Qt::darkCyan);
    }
    else if (color == 3){
        painter->setBrush(Qt::darkRed);
    }
    else if (color == 4) {
        painter->setBrush(Qt::darkGreen);
    }
    else if (color == 5){
        painter->setBrush(Qt::magenta);
    }
    else {
        painter->setBrush(Qt::darkCyan);
    }
    //painter->setBrush(Qt::darkCyan);
    painter->drawEllipse(boundingRect());
}

void Particula::moverParticula(float speed){
    pos_x += vel_x * speed;
    pos_y += vel_y * speed;
    setPos(pos_x, pos_y);
}

void Particula::colisonParticula(float horzlim, float vertlim, Particula *particula[10], int num_i, int numParticula){
    if((pos_x < radio) || (pos_x > vertlim - radio)){
        vel_x = -1*vel_x;
    }

    if((pos_y < radio) || (pos_y > horzlim - radio)){
        vel_y = -1*vel_y;
    }

   /* for (int i = 0; i < numParticula ; i++){ //Intento de fisica entre particulas :c
        if (i == num_i){
            continue;
        }
        else {
            if (pos_x > particula[i]->pos_x){
                if (pos_x-particula[i]->pos_x <= radio+particula[i]->radio && pos_x-particula[i]->pos_x >= -1*(radio+particula[i]->radio)){
                    vel_x = -1*vel_x;
                }
            }
            else {
                if (pos_x-particula[i]->pos_x <= radio+particula[i]->radio && pos_x-particula[i]->pos_x >= -1*(radio+particula[i]->radio)){
                    vel_x = -1*vel_x;
                }
            }
            if (pos_y > particula[i]->pos_y){
                if (pos_y-particula[i]->pos_y <= radio+particula[i]->radio && pos_y-particula[i]->pos_y >= -1*(radio+particula[i]->radio)){
                    vel_y = -1*vel_y;
                }
            }
            else {
                if (particula[i]->pos_y-pos_y <= particula[i]->radio+radio && pos_y-particula[i]->pos_y >= -1*(radio+particula[i]->radio)){
                    vel_y = -1*vel_y;
                }
            }
        }
    }*/

}

void Particula::removeParticula(){
    //pos_x = 600;
    //pos_y = 600;
    //setPos(pos_x,pos_y);
}
