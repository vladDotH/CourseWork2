#ifndef CW2_VEC2DQ_H
#define CW2_VEC2DQ_H


#include <QPoint>
#include "Vector.h"

using namespace Graphics;

class Vec2DQ : public Vec2D {
public:
    Vec2DQ(QPoint p) : Vec2D(p.x(), p.y()) {}

    Vec2DQ(Vec2D v) : Vec2D(v) {}

    using Vec2D::Vector;

    QPoint point() { return QPoint(x, y); }
};


#endif //CW2_VEC2DQ_H
