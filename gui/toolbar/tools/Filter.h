#ifndef CW2_FILTER_H
#define CW2_FILTER_H


#include <QWidget>
#include <QRadioButton>
#include <QGroupBox>
#include <QSlider>
#include <QVBoxLayout>
#include <QMouseEvent>
#include "Tool.h"

class Filter : public Tool {
Q_OBJECT
public:
    Filter(QWidget *parent = nullptr, QWidget *buttonParent = nullptr);

    void process(QMouseEvent *ev, BitMapQ *bm) override;

private:
    QGroupBox *colorBox;
    QVBoxLayout *colorLt, *lt;
    QRadioButton *r, *g, *b;
    QSlider *val;
    Channel ch;
};


#endif //CW2_FILTER_H
