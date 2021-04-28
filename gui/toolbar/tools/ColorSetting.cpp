#include "ColorSetting.h"

ColorSetting::ColorSetting(QWidget *parent) : QPushButton(parent) {
    connect(this, &QPushButton::clicked, [this]() {
        QColorDialog *dialog = new QColorDialog(this);
        QColor color = dialog->getColor();
        if (color.isValid()) {
            QPalette p = palette();
            p.setColor(QPalette::Button, color);
            setPalette(p);
            update();
        }
    });
}

const QColor &ColorSetting::getColor() const {
    return color;
}
