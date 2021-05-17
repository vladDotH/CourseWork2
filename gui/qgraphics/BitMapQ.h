#ifndef CW2_BITMAPQ_H
#define CW2_BITMAPQ_H


#include <QByteArray>
#include <QPixmap>
#include <BitMap.h>
#include <QDebug>
#include "Vec2DQ.h"
#include "ColorQ.h"

using namespace Graphics;

class BitMapQ : public BitMap {
public:
    using BitMap::BitMap;

    BitMapQ(QString s) : BitMap(s.toStdString()) {}

    void read(QString s);

    void copy(BitMapQ &cp);

    Vec2DQ transform(QPoint p);

    void updQImg();

    QPixmap *getQImg();

    ~BitMapQ();

    void drawCrossRect(QPoint p1, QPoint p2, QColor color, int wd, bool fill, QColor fillColor) noexcept;

    void drawCircle(QPoint c, int r, QColor color, int wd, bool fill, QColor fillColor) noexcept;

    void rotate(QPoint p1, QPoint p2, RotateAngle a) noexcept;

    void filter(Channel c, int val) noexcept;

private:
    QPixmap *qimg = new QPixmap;
};


#endif //CW2_BITMAPQ_H
