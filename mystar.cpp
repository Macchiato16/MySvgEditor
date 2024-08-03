#include "mystar.h"
#include "myshape.h"
#include <QtGui/QPainter>
#include <QtGui/QColor>
#include <QtGui/QPen>
#include <QtGui/QPainterPath>
#include <QPoint>
#include <cmath>

MyStar::MyStar(MyShape *parent):MyShape(parent)
{
}

MyStar::MyStar(const MyStar &copyShape):MyShape(copyShape)
{
}

void MyStar::paint(QPainter &painter)
{
    painter.setRenderHints(QPainter::Antialiasing, true);
    painter.setBrush(fillColor);
    QPen pen;
    pen.setStyle(penStyle);
    pen.setWidth(penSize);
    pen.setColor(penColor);
    pen.setCapStyle(Qt::RoundCap);
    pen.setJoinStyle(Qt::RoundJoin);
    painter.setPen(pen);

    QPainterPath drawpath;

    // 中心点
    QPoint center((start.x() + end.x()) / 2, (start.y() + end.y()) / 2);
    // 外部半径
    int R = qMin(abs(end.x() - start.x()), abs(end.y() - start.y())) / 2;
    // 内部半径
    int r = R * 0.4;

    // 绘制五角星
    for (int i = 0; i < 5; ++i) {
        double outerAngle = 72 * i * M_PI / 180;
        double innerAngle = 72 * (i + 0.5) * M_PI / 180;

        QPointF outerPoint(center.x() + R * cos(outerAngle), center.y() - R * sin(outerAngle));
        QPointF innerPoint(center.x() + r * cos(innerAngle), center.y() - r * sin(innerAngle));

        if (i == 0) {
            drawpath.moveTo(outerPoint);
        } else {
            drawpath.lineTo(outerPoint);
        }
        drawpath.lineTo(innerPoint);
    }
    drawpath.closeSubpath();
    painter.drawPath(drawpath);
}

MyShapeType MyStar::getType()
{
    return MyShapeType::star;
}
