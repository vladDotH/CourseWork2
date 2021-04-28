#ifndef CW2_FILTER_H
#define CW2_FILTER_H


#include <QWidget>
#include <QRadioButton>
#include <QGroupBox>
#include <QSlider>
#include <QVBoxLayout>
#include "Tool.h"

class Filter : public Tool {
Q_OBJECT
public:
    Filter(QWidget *parent = nullptr, QWidget *buttonParent = nullptr);

private:
    QGroupBox *colorBox;
    QVBoxLayout *colorLt, *lt;
    QRadioButton *r, *g, *b;
    QSlider *val;
};


#endif //CW2_FILTER_H
