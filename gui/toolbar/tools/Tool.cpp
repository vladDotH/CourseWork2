#include "Tool.h"

Tool::Tool(QString name, QWidget *parent, QWidget *buttonParent) : QWidget(parent) {
    this->name = name;
    active = new QRadioButton(name, buttonParent);
    connect(active, &QRadioButton::clicked, [this](bool checked) {
       emit picked(this);
    });
}

QRadioButton *Tool::getActive() const {
    return active;
}
