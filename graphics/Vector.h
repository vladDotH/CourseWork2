#ifndef VECTOR_H
#define VECTOR_H

#include <cmath>
#include <ostream>

namespace Graphics {
    template<typename V>
    struct Vector {
        V x, y;

        Vector<V>() = default;

        Vector<V>(V x, V y) : x(x), y(y) {}

        Vector<V> sgn() {
            return Vector<V>((x > 0) - (x < 0), (y > 0) - (y < 0));
        }

        Vector<V> abs() {
            return Vector<V>(std::abs(x), std::abs(y));
        }

        friend Vector<V> operator-(Vector<V> v) {
            return Vector<V>(-v.x, -v.y);
        }

        friend Vector<V> operator+(Vector<V> v1, Vector<V> v2) {
            return Vector<V>(v1.x + v2.x, v1.y + v2.y);
        }

        friend Vector<V> operator-(Vector<V> v1, Vector<V> v2) {
            return Vector<V>(v1.x - v2.x, v1.y - v2.y);
        }

        friend void operator+=(Vector<V> &v1, Vector<V> v2) {
            v1 = v1 + v2;
        }

        friend void operator-=(Vector<V> &v1, Vector<V> v2) {
            v1 = v1 - v2;
        }

        friend Vector<V> operator/(Vector<V> v, V c) {
            return Vector<V>(v.x / c, v.y / c);
        }

        friend Vector<V> operator*(Vector<V> v, V c) {
            return Vector<V>(v.x * c, v.y * c);
        }

        friend Vector<V> operator*(V c, Vector<V> v) {
            return v * c;
        }

        friend V operator*(Vector<V> v1, Vector<V> v2) {
            return v1.x * v2.x + v1.y * v2.y;
        }

        friend std::ostream &operator<<(std::ostream &os, const Vector<V> &vector) {
            os << "x: " << vector.x << " y: " << vector.y;
            return os;
        }

        bool operator==(Vector<V> v) {
            return x == v.x && y == v.y;
        }

        bool operator!=(Vector<V> v) {
            return !(*this == v);
        }

        bool operator>(Vector<V> v) {
            return x > v.x && y > v.y;
        }

        bool operator<(Vector<V> v) {
            return x < v.x && y < v.y;
        }

        bool operator>=(Vector<V> v) {
            return x >= v.x && y >= v.y;
        }

        bool operator<=(Vector<V> v) {
            return x <= v.x && y <= v.y;
        }
    };


    using Vec2D = Vector<int>;
    using Mat2D = Vector<Vector<int>>;
    extern const Vec2D e1, e2, null, one;
}

#endif //VECTOR_H
