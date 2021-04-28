#ifndef CW2_CROSSSQUARE_H
#define CW2_CROSSSQUARE_H


#include <QWidget>
#include <QSlider>
#include <QRadioButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QSizePolicy>
#include "ColorSetting.h"
#include "Tool.h"

class CrossSquare : public Tool {
Q_OBJECT
public:
    CrossSquare(QWidget *parent = nullptr, QWidget *buttonParent = nullptr);

private:
    QVBoxLayout *layout;
    ColorSetting *color, *fillColor;
    QSlider *wd;
    QRadioButton *fill;
};


#endif //CW2_CROSSSQUARE_H
