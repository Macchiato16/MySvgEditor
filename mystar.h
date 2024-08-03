#ifndef KOSOSTAR_H
#define KOSOSTAR_H

class QPainter;
class QPoint;
#include "myshape.h"

class MyStar : public MyShape
{
public:
    MyStar(MyShape *parent = nullptr);
    MyStar(const MyStar &copyShape);
    ~MyStar(){}

    void virtual paint(QPainter &painter) override;
    MyShapeType virtual getType() override;
};

#endif // KOSOSTAR_H
