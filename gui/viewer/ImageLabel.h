#ifndef CW2_IMAGELABEL_H
#define CW2_IMAGELABEL_H

#include <QObject>
#include <QLabel>
#include <QDebug>
#include <QMouseEvent>

class ImageLabel : public QLabel {
Q_OBJECT
public:
    ImageLabel(QWidget *parent);

signals:

    void mouseEvent(QMouseEvent *ev);

protected:
    void mousePressEvent(QMouseEvent *ev) override;

    void mouseMoveEvent(QMouseEvent *ev) override;

    void mouseReleaseEvent(QMouseEvent *ev) override;
};


#endif //CW2_IMAGELABEL_H
