#include "ToolBar.h"

ToolBar::ToolBar(QWidget *parent) : QWidget(parent) {
    lt = new QVBoxLayout(this);
    toolsPick = new QGroupBox("Выбор инструмента", this);
    toolsPickLt = new QVBoxLayout(toolsPick);

    toolSettings = new QWidget(this);
    toolSettingsLt = new QVBoxLayout(toolSettings);
    csq = new CrossSquare(toolSettings, toolsPick);
    flt = new Filter(toolSettings, toolsPick);
    crc = new Circle(toolSettings, toolsPick);
    rot = new Rotator(toolSettings, toolsPick);
    tools.append(csq);
    tools.append(flt);
    tools.append(crc);
    tools.append(rot);
    for (auto i : tools) {
        toolsPickLt->addWidget(i->getActive());
        toolSettingsLt->addWidget(i);
        connect(i, &Tool::picked, this, &ToolBar::toolPicked);
        i->setVisible(false);
    }
    toolSettings->setLayout(toolSettingsLt);
    toolsPick->setLayout(toolsPickLt);

    lt->addWidget(toolsPick);
    lt->addWidget(toolSettings);
    setLayout(lt);
}

void ToolBar::mouseHandler(QMouseEvent *ev) {
    qDebug() << ev->pos();
}

void ToolBar::toolPicked(Tool *tool) {
    if (currentTool != nullptr)
        currentTool->setVisible(false);
    tool->setVisible(true);
    currentTool = tool;
}
