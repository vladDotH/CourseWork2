#ifndef CW2_CIRCLE_H
#define CW2_CIRCLE_H


#include <QWidget>
#include <QVBoxLayout>
#include <QSlider>
#include <QLabel>
#include <QPainter>
#include <QMouseEvent>
#include <QApplication>
#include "ColorSetting.h"
#include "Tool.h"

class Circle : public Tool {
Q_OBJECT
public:
    Circle(QWidget *parent = nullptr, QWidget *buttonParent = nullptr);

    void process(QMouseEvent *ev, BitMapQ *bm) override;

private:
    QVBoxLayout *layout;
    ColorSetting *color, *fillColor;
    QSlider *wd;
    QRadioButton *fill;
    QPoint p1, p2, c;
    int R;
};


#endif //CW2_CIRCLE_H
