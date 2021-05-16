#include <iostream>
#include "BitMap.h"

namespace Graphics {
    const Mat2D rotation[3]{
            Mat2D(Vec2D(0, 1),
                  Vec2D(-1, 0)),

            Mat2D(Vec2D(-1, 0),
                  Vec2D(0, -1)),

            Mat2D(Vec2D(0, -1),
                  Vec2D(1, 0))
    };

    BitMap::~BitMap() {
        clear();
    }

    bool BitMap::empty() {
        return data == nullptr;
    }

    void BitMap::clear() {
        if (!empty()) {
            delete[] data;
            data = nullptr;
        }
    }

    void BitMap::copy(BitMap &cp) {
        cp = *this;
        cp.data = new byte[dataSize];
        std::copy(header, header + HEADER_SIZE, cp.header);
        std::copy(data, data + dataSize, cp.data);
        cp.img = cp.data + imgOffset - HEADER_SIZE;
    }

    BitMap::BitMap(std::string name) noexcept(false) {
        read(name);
    }

    void BitMap::read(std::string name) noexcept(false) {
        this->name = name;
        clear();
        std::ifstream file(name, std::ios::binary);
        if (!file)
            throw std::invalid_argument("Bad file");

        file.read((char *) header, HEADER_SIZE);
        type = *(int16_t *) (header + 0x00);
        if (type != 0x4D42) {
            throw std::invalid_argument("File is not BMP");
        }

        fileSize = *(int32_t *) (header + 0x02);
        imgOffset = *(int32_t *) (header + 0x0A);
        dataSize = fileSize - HEADER_SIZE;

        data = new byte[dataSize];
        file.read((char *) data, sizeof(infoSize));
        infoSize = *(int32_t *) (data + 0x00);

        file.read((char *) (data + sizeof(infoSize)), infoSize - sizeof(infoSize));
        if (infoSize > CORE_VERSION_SIZE) {
            width = *(int32_t *) (data + 0x04);
            height = *(int32_t *) (data + 0x08);
            depth = *(int16_t *) (data + 0x0E);
        } else {
            width = *(uint16_t *) (data + 0x04);
            height = *(uint16_t *) (data + 0x06);
            depth = *(int16_t *) (data + 0x0A);
        }

        if (depth != DEPTH) {
            clear();
            throw std::invalid_argument("Bad file`s depth");
        }

        paddingWidth = width * 3 + width % 4;
        img = data + (imgOffset - HEADER_SIZE);
        end = Vec2D(width, height);

        file.read((char *) (data + infoSize), dataSize - infoSize);
        img = data + imgOffset - HEADER_SIZE;
        file.close();
    }

    void BitMap::save(std::string name) noexcept(false) {
        if (data == nullptr)
            throw std::logic_error("Empty bitmap");

        std::ofstream file(name, std::ios::binary);
        if (!file)
            throw std::invalid_argument("Bad file");

        file.write((char *) header, HEADER_SIZE);
        file.write((char *) data, fileSize - HEADER_SIZE);
        file.close();
    }

    int BitMap::getPixelPos(Vec2D pos) noexcept(false) {
        if (!(pos >= null && pos < end))
            throw std::out_of_range("Out of image size");
        return paddingWidth * (int) pos.y + 3 * (int) pos.x;
    }

    int BitMap::getChannel(Vec2D pos, Channel channel) noexcept(false) {
        return img[getPixelPos(pos) + channel];
    }

    void BitMap::setChannel(Vec2D pos, Channel channel, int val) noexcept(false) {
        if (data == nullptr)
            throw std::logic_error("Empty bitmap");
        img[getPixelPos(pos) + channel] = val;
    }

    Color BitMap::getPixel(Vec2D pos) noexcept(false) {
        if (data == nullptr)
            throw std::logic_error("Empty bitmap");
        return Color(
                getChannel(pos, R),
                getChannel(pos, G),
                getChannel(pos, B)
        );
    }

    void BitMap::setPixel(Vec2D pos, Color color) noexcept(false) {
        setChannel(pos, R, color.r);
        setChannel(pos, G, color.g);
        setChannel(pos, B, color.b);
    }

    void BitMap::drawLine(Vec2D p1, Vec2D p2, Color color, int wd) noexcept {
        Vec2D d = (p2 - p1).abs();
        if (wd == 0) {
            Vec2D s = (p2 - p1).sgn();
            int ex = d.x, ey = d.y;
            while (p1 != p2) {
                if (p1 >= null && p1 < end)
                    setPixel(p1, color);
                if (ex > ey) {
                    p1.x += s.x;
                    ey += d.y;
                } else {
                    p1.y += s.y;
                    ex += d.x;
                }
            }
        } else {
            if (d.y >= d.x) {
                for (int i = -wd / 2; i <= wd / 2; ++i) {
                    drawLine(p1 + (e1 * i), p2 + (e1 * i), color, 0);
                }
            } else {
                for (int i = -wd / 2; i <= wd / 2; ++i) {
                    drawLine(p1 + (e2 * i), p2 + (e2 * i), color, 0);
                }
            }
        }
    }

    void BitMap::drawRect(Vec2D p1, Vec2D p2, Color color, int wd, bool fill, Color fillColor) noexcept {
        Vec2D step1 = (p2 - p1).sgn();
        if (wd == 0) {
            Vec2D d = (p2 - p1).abs(),
                    p = p1;
            for (int i = 0; i <= d.y; ++i, p.y += step1.y, p.x = p1.x) {
                for (int j = 0; j <= d.x; ++j, p.x += step1.x) {
                    if (p >= null && p < end)
                        setPixel(p, color);
                }
            }
        } else {
            wd--;
            Vec2D p3(p2.x, p1.y), p4(p1.x, p2.y),
                    step2 = (p4 - p3).sgn(),
                    p11 = p1 + step1 * wd, p22 = p2 + (-step1) * wd,
                    p33 = p3 + step2 * wd, p44 = p4 + (-step2) * wd;
            wd++;
            drawRect(p1, p33, color);
            drawRect(p3, p22, color);
            drawRect(p2, p44, color);
            drawRect(p4, p11, color);

            if (fill)
                drawRect(p1 + step1 * wd, p2 - step1 * wd, fillColor);
        }
    }

    void BitMap::drawCrossRect(Vec2D p1, Vec2D p2, Color color, int wd, bool fill, Color fillColor) noexcept {
        Vec2D d = (p2 - p1).abs();
        if (wd > d.x / 2 || wd > d.y / 2) { //!
            drawRect(p1, p2, color);
        } else {
            wd--;
            Vec2D p3(p2.x, p1.y), p4(p1.x, p2.y),
                    step1 = (p2 - p1).sgn(), step2 = (p4 - p3).sgn(),
                    p11 = p1 + step1 * wd, p22 = p2 + (-step1) * wd,
                    p33 = p3 + step2 * wd, p44 = p4 + (-step2) * wd;
            wd++;
            drawRect(p1, p2, color, wd, fill, fillColor);
            drawLine(p11, p22, color, wd);
            drawLine(p33, p44, color, wd);
        }
    }

    void BitMap::drawCircle(Vec2D c, int r, Color color, int wd, bool fill, Color fillColor) noexcept {
        Vec2D p = -one * r;
        int r1 = r, r2 = r - wd;
        int r1s = r1 * r1, r2s = r2 * r2;
        for (int i = 0; i <= 2 * r; ++i, p.y++) {
            p.x = -r1;
            for (int j = 0; j <= 2 * r; ++j, p.x++) {
                if (p + c >= null && p + c < end) {
                    if (p * p < r1s) {
                        if (p * p >= r2s || r2 < 0)
                            setPixel(p + c, color);
                        else if (fill)
                            setPixel(p + c, fillColor);
                    }
                }
            }
        }
    }

    void BitMap::filter(Channel c, int val) noexcept {
        Vec2D p = null;
        for (int i = 0; i < height; ++i, p += e2) {
            p.x = 0;
            for (int j = 0; j < width; ++j, p += e1) {
                setChannel(p, c, val);
            }
        }
    }

    void BitMap::rotate(Vec2D p1, Vec2D p2, RotateAngle a) noexcept {
        Mat2D rotate = rotation[a];
        BitMap cp;
        this->copy(cp);
        Vec2D c2 = (p1 + p2),
                d = (p2 - p1).abs(),
                s = (p2 - p1).sgn(),
                p = p1,
                v2, vs, ps;
        drawRect(p1, p2, WHITE);
        for (int i = 0; i <= d.y; ++i, p.y += s.y, p.x = p1.x) {
            for (int j = 0; j <= d.x; ++j, p.x += s.x) {
                v2 = 2 * p - c2;
                vs = Vec2D(rotate.x * v2, rotate.y * v2);
                ps = (vs + c2) / 2;
                if (ps >= null && p >= null && ps < end && p < end)
                    setPixel(ps, cp.getPixel(p));
            }
        }
        cp.clear();
    }

    int32_t BitMap::getFileSize() const {
        return fileSize;
    }

    int32_t BitMap::getInfoSize() const {
        return infoSize;
    }

    int32_t BitMap::getWidth() const {
        return width;
    }

    int32_t BitMap::getHeight() const {
        return height;
    }

    int16_t BitMap::getDepth() const {
        return depth;
    }

    const std::string &BitMap::getName() const {
        return name;
    }
}
