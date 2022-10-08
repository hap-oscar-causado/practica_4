#ifndef PARTICULA_H
#define PARTICULA_H

#include <QGraphicsItem>
#include<QPainter>

class Particula: public QGraphicsItem
{
    float pos_x;
    float pos_y;
    float vel_x;
    float vel_y;
    float radio;

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
public:
    Particula();
    ~Particula();

    Particula(float x, float y, float vel_x, float vel_y, float rad);
    void moverParticula(float speed);
    void colisonParticula(float horzlim, float vertlim, Particula *particula[10], int, int);
    void removeParticula();

};

#endif // PARTICULA_H
