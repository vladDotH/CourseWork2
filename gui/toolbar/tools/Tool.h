#ifndef CW2_TOOL_H
#define CW2_TOOL_H

#include <QWidget>
#include <QRadioButton>
#include <QDebug>
#include <qgraphics/BitMapQ.h>

class Tool : public QWidget {
Q_OBJECT
public:
    Tool(QString name, QWidget *parent = nullptr, QWidget *buttonParent = nullptr);

    QRadioButton *getActive() const;

    virtual void process(QMouseEvent *ev, BitMapQ *bm) {};

signals:

    void update(QPixmap *qimg);

    void picked(Tool *tool);

protected:
    QString name;
    QRadioButton *active;
};


#endif //CW2_TOOL_H
