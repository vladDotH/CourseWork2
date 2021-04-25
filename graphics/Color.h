#ifndef COLOR_H
#define COLOR_H

namespace Graphics {
    using byte = unsigned char;

    struct Color {
        byte r, g, b;

        Color() : r(0), g(0), b(0) {}

        Color(byte r, byte g, byte b) : r(r), g(g), b(b) {}
    };

    extern const Color RED,
            GREEN,
            BLUE,
            BLACK,
            WHITE;
}

#endif //COLOR_H
