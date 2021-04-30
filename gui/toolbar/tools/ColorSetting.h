#ifndef CW2_COLORSETTING_H
#define CW2_COLORSETTING_H

#include <QWidget>
#include <QPushButton>
#include <QColor>
#include <QColorDialog>

class ColorSetting : public QPushButton {
Q_OBJECT
public:
    ColorSetting(QWidget *parent);

    const QColor &getColor() const;


private:
    QColor color = Qt::white;
};


#endif //CW2_COLORSETTING_H
