#ifndef BITMAP_H
#define BITMAP_H

#include <fstream>
#include <cmath>
#include "Vector.h"
#include "Color.h"

namespace Graphics {
    enum Channel {
        R = 2,
        G = 1,
        B = 0
    };

    enum RotateAngle {
        D90 = 0,
        D180 = 1,
        D270 = 2
    };

    extern const Mat2D rotation[3];

    class BitMap {
    protected:
        static const int DEPTH = 24;
        static const int HEADER_SIZE = 14;
        static const int CORE_VERSION_SIZE = 12;

        byte header[HEADER_SIZE], *data = nullptr, *img;
        int16_t type;
        int32_t fileSize, imgOffset;
        int32_t infoSize, width, height, paddingWidth;
        int16_t depth;
        Vec2D end;

    public:
        BitMap() = default;

        BitMap(const BitMap &bm);

        ~BitMap();

        void clear();

        bool empty();

        void read(std::string name) noexcept(false);

        void save(std::string name) noexcept(false);

        BitMap(std::string name) noexcept(false);

        int getPixelPos(Vec2D pos) noexcept(false);

        int getChannel(Vec2D pos, Channel channel) noexcept(false);

        void setChannel(Vec2D pos, Channel channel, int val) noexcept(false);

        Color getPixel(Vec2D pos) noexcept(false);

        void setPixel(Vec2D pos, Color color) noexcept(false);

        void drawLine(Vec2D p1, Vec2D p2, Color color = BLACK, int wd = 0) noexcept;

        void drawRect(Vec2D p1, Vec2D p2, Color color = BLACK, int wd = 0, bool fill = false,
                      Color fillColor = BLACK) noexcept;

        virtual void drawCrossRect(Vec2D p1, Vec2D p2, Color color = BLACK, int wd = 0, bool fill = false,
                           Color fillColor = BLACK) noexcept;

        virtual void filter(Channel c, int val) noexcept;

        virtual void drawCircle(Vec2D c, int r, Color color = BLACK, int wd = 0, bool fill = false,
                        Color fillColor = BLACK) noexcept;

        virtual void rotate(Vec2D p1, Vec2D p2, RotateAngle a) noexcept;
    };
}
#endif //BITMAP_H
