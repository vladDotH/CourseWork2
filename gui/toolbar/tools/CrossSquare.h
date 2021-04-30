#ifndef CW2_CROSSSQUARE_H
#define CW2_CROSSSQUARE_H


#include <QWidget>
#include <QSlider>
#include <QRadioButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QSizePolicy>
#include <QMouseEvent>
#include <QEvent>
#include <QPainter>
#include "ColorSetting.h"
#include "Tool.h"

class CrossSquare : public Tool {
Q_OBJECT
public:
    CrossSquare(QWidget *parent = nullptr, QWidget *buttonParent = nullptr);

    void process(QMouseEvent *ev, BitMapQ *bm) override;

private:
    QVBoxLayout *layout;
    ColorSetting *color, *fillColor;
    QSlider *wd;
    QRadioButton *fill;
    QPoint p1, p2;
};


#endif //CW2_CROSSSQUARE_H
