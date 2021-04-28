#ifndef CW2_CIRCLE_H
#define CW2_CIRCLE_H


#include <QWidget>
#include <QVBoxLayout>
#include <QSlider>
#include <QLabel>
#include "ColorSetting.h"
#include "Tool.h"

class Circle : public Tool {
Q_OBJECT
public:
    Circle(QWidget *parent = nullptr, QWidget *buttonParent = nullptr);

private:
    QVBoxLayout *layout;
    ColorSetting *color, *fillColor;
    QSlider *wd;
    QRadioButton *fill;
};


#endif //CW2_CIRCLE_H
