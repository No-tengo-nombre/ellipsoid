#include "color.hpp"

namespace ellipsoid {
namespace utils {

unsigned int ColorRGBA::limitValue(unsigned int value) {
    if (ELLIPSOID_COLOR_MIN <= value) {
        if (value <= ELLIPSOID_COLOR_MAX) {
            return value;
        }
        return ELLIPSOID_COLOR_MAX;
    }
    return ELLIPSOID_COLOR_MIN;
}

ColorRGBA::ColorRGBA() {
    _r = 0;
    _g = 0;
    _b = 0;
    _a = 0;
}

ColorRGBA::ColorRGBA(const unsigned int r, const unsigned int g,
                     const unsigned int b) {
    _r = limitValue(r);
    _g = limitValue(g);
    _b = limitValue(b);
    _a = 255;
}

ColorRGBA::ColorRGBA(const unsigned int r, const unsigned int g,
                     const unsigned int b, const unsigned int a) {
    _r = limitValue(r);
    _g = limitValue(g);
    _b = limitValue(b);
    _a = limitValue(a);
}

void ColorRGBA::r(unsigned int val) { _r = limitValue(val); }

void ColorRGBA::g(unsigned int val) { _g = limitValue(val); }

void ColorRGBA::b(unsigned int val) { _b = limitValue(val); }

void ColorRGBA::a(unsigned int val) { _a = limitValue(val); }

std::vector<unsigned int> ColorRGBA::asVector() const {
    return std::vector<unsigned int>({_r, _g, _b, _a});
}

const ColorRGBA ColorRGBA::operator+(const ColorRGBA& rhs) {
    ColorRGBA result;
    result.r(getR() + rhs.getR());
    result.g(getG() + rhs.getG());
    result.b(getB() + rhs.getB());
    result.a(getA() + rhs.getA());
    return result;
}

const ColorRGBA ColorRGBA::operator-(const ColorRGBA& rhs) {
    ColorRGBA result;
    result.r(getR() - rhs.getR());
    result.g(getG() - rhs.getG());
    result.b(getB() - rhs.getB());
    result.a(getA() - rhs.getA());
    return result;
}

ColorRGBA& ColorRGBA::operator+=(const ColorRGBA& rhs) {
    r(_r + rhs.getR());
    g(_g + rhs.getG());
    b(_b + rhs.getB());
    a(_a + rhs.getA());
    return *this;
}

ColorRGBA& ColorRGBA::operator-=(const ColorRGBA& rhs) {
    r(_r - rhs.getR());
    g(_g - rhs.getG());
    b(_b - rhs.getB());
    a(_a - rhs.getA());
    return *this;
}

unsigned int& ColorRGBA::operator[](size_t index) {
    return asVector()[index];
}

} // namespace utils
} // namespace ellipsoid
