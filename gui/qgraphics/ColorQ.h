#ifndef CW2_COLORQ_H
#define CW2_COLORQ_H


#include <QColor>
#include <Color.h>

using namespace Graphics;

class ColorQ : public Color {
public:
    ColorQ(const QColor& c) : Color(c.red(), c.green(), c.blue()) {}
};


#endif //CW2_COLORQ_H
