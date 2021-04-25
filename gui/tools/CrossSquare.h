#ifndef CW2_CROSSSQUARE_H
#define CW2_CROSSSQUARE_H


#include <QWidget>
#include <QSlider>
#include <QRadioButton>
#include <QVBoxLayout>

class CrossSquare : public QWidget {
public:
    CrossSquare(QWidget *parent);

private:
    QVBoxLayout *layout;
    QSlider *r, *g, *b, *wd;
    QRadioButton *fill;
};


#endif //CW2_CROSSSQUARE_H
