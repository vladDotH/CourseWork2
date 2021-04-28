#ifndef CW2_ROTATOR_H
#define CW2_ROTATOR_H


#include <QWidget>
#include <QRadioButton>
#include <QGroupBox>
#include <QVBoxLayout>
#include "Tool.h"

class Rotator : public Tool {
Q_OBJECT
public:
    Rotator(QWidget *parent = nullptr, QWidget *buttonParent = nullptr);

private:
    QVBoxLayout *lt, *anglesLt;
    QGroupBox *angles;
    QRadioButton *d90, *d180, *d270;


};


#endif //CW2_ROTATOR_H
