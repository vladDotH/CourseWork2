#include "BitMapQ.h"

void BitMapQ::updQImg() {
    QByteArray raw;
    raw.append((char *) header, HEADER_SIZE);
    raw.append((char *) data, fileSize - HEADER_SIZE);
    qimg->loadFromData(raw, ".bmp");
}

QPixmap *BitMapQ::getQImg() {
    return qimg;
}

BitMapQ::~BitMapQ() {
    delete qimg;
}

void BitMapQ::drawCrossRect(QPoint p1, QPoint p2, QColor color, int wd, bool fill, QColor fillColor) noexcept {
    BitMap::drawCrossRect(transform(p1), transform(p2), ColorQ(color), wd, fill, ColorQ(fillColor));
}

Vec2DQ BitMapQ::transform(QPoint p) {
    return Vec2DQ(p.x(), height - p.y());
}

void BitMapQ::drawCircle(QPoint c, int r, QColor color, int wd, bool fill, QColor fillColor) noexcept {
    BitMap::drawCircle(transform(c), r, ColorQ(color), wd, fill, ColorQ(fillColor));
}

void BitMapQ::rotate(QPoint p1, QPoint p2, RotateAngle a) noexcept {
    BitMap::rotate(transform(p1), transform(p2), a);
}

void BitMapQ::filter(Channel c, int val) noexcept {
    BitMap::filter(c, val);
}

