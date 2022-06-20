#include "color.hpp"

namespace ellipsoid {
namespace utils {

unsigned int ColorRGBA255::limitValue(unsigned int value) {
    if (ELLIPSOID_COLOR255_MIN <= value) {
        if (value <= ELLIPSOID_COLOR255_MAX) {
            return value;
        }
        return ELLIPSOID_COLOR255_MAX;
    }
    return ELLIPSOID_COLOR255_MIN;
}

ColorRGBA255::ColorRGBA255() {
    _r = 0;
    _g = 0;
    _b = 0;
    _a = 0;
}

ColorRGBA255::ColorRGBA255(const unsigned int r, const unsigned int g,
                     const unsigned int b) {
    _r = limitValue(r);
    _g = limitValue(g);
    _b = limitValue(b);
    _a = 255;
}

ColorRGBA255::ColorRGBA255(const unsigned int r, const unsigned int g,
                     const unsigned int b, const unsigned int a) {
    _r = limitValue(r);
    _g = limitValue(g);
    _b = limitValue(b);
    _a = limitValue(a);
}

void ColorRGBA255::r(const unsigned int val) { _r = limitValue(val); }

void ColorRGBA255::g(const unsigned int val) { _g = limitValue(val); }

void ColorRGBA255::b(const unsigned int val) { _b = limitValue(val); }

void ColorRGBA255::a(const unsigned int val) { _a = limitValue(val); }

std::vector<unsigned int> ColorRGBA255::asVector() const {
    return std::vector<unsigned int>({_r, _g, _b, _a});
}

ColorRGBAfloat ColorRGBA255::asRGBAfloat() const {
    return ColorRGBAfloat(_r / 255, _g / 255, _b / 255, _a / 255);
}

const ColorRGBA255 ColorRGBA255::operator+(const ColorRGBA255& rhs) {
    ColorRGBA255 result;
    result.r(getR() + rhs.getR());
    result.g(getG() + rhs.getG());
    result.b(getB() + rhs.getB());
    result.a(getA() + rhs.getA());
    return result;
}

const ColorRGBA255 ColorRGBA255::operator-(const ColorRGBA255& rhs) {
    ColorRGBA255 result;
    result.r(getR() - rhs.getR());
    result.g(getG() - rhs.getG());
    result.b(getB() - rhs.getB());
    result.a(getA() - rhs.getA());
    return result;
}

ColorRGBA255& ColorRGBA255::operator+=(const ColorRGBA255& rhs) {
    r(_r + rhs.getR());
    g(_g + rhs.getG());
    b(_b + rhs.getB());
    a(_a + rhs.getA());
    return *this;
}

ColorRGBA255& ColorRGBA255::operator-=(const ColorRGBA255& rhs) {
    r(_r - rhs.getR());
    g(_g - rhs.getG());
    b(_b - rhs.getB());
    a(_a - rhs.getA());
    return *this;
}

unsigned int& ColorRGBA255::operator[](size_t index) {
    return asVector()[index];
}



float ColorRGBAfloat::limitValue(float value) {
    if (ELLIPSOID_COLOR_FLOAT_MIN <= value) {
        if (value <= ELLIPSOID_COLOR_FLOAT_MAX) {
            return value;
        }
        return ELLIPSOID_COLOR_FLOAT_MAX;
    }
    return ELLIPSOID_COLOR_FLOAT_MIN;
}

ColorRGBAfloat::ColorRGBAfloat() {
    _r = 0.0f;
    _g = 0.0f;
    _b = 0.0f;
    _a = 0.0f;
}

ColorRGBAfloat::ColorRGBAfloat(const float r, const float g,
                     const float b) {
    _r = limitValue(r);
    _g = limitValue(g);
    _b = limitValue(b);
    _a = 1.0f;
}

ColorRGBAfloat::ColorRGBAfloat(const float r, const float g,
                     const float b, const float a) {
    _r = limitValue(r);
    _g = limitValue(g);
    _b = limitValue(b);
    _a = limitValue(a);
}

void ColorRGBAfloat::r(float val) { _r = limitValue(val); }

void ColorRGBAfloat::g(float val) { _g = limitValue(val); }

void ColorRGBAfloat::b(float val) { _b = limitValue(val); }

void ColorRGBAfloat::a(float val) { _a = limitValue(val); }

std::vector<float> ColorRGBAfloat::asVector() const {
    return std::vector<float>({_r, _g, _b, _a});
}

const ColorRGBAfloat ColorRGBAfloat::operator+(const ColorRGBAfloat& rhs) {
    ColorRGBAfloat result;
    result.r(getR() + rhs.getR());
    result.g(getG() + rhs.getG());
    result.b(getB() + rhs.getB());
    result.a(getA() + rhs.getA());
    return result;
}

const ColorRGBAfloat ColorRGBAfloat::operator-(const ColorRGBAfloat& rhs) {
    ColorRGBAfloat result;
    result.r(getR() - rhs.getR());
    result.g(getG() - rhs.getG());
    result.b(getB() - rhs.getB());
    result.a(getA() - rhs.getA());
    return result;
}

ColorRGBAfloat& ColorRGBAfloat::operator+=(const ColorRGBAfloat& rhs) {
    r(_r + rhs.getR());
    g(_g + rhs.getG());
    b(_b + rhs.getB());
    a(_a + rhs.getA());
    return *this;
}

ColorRGBAfloat& ColorRGBAfloat::operator-=(const ColorRGBAfloat& rhs) {
    r(_r - rhs.getR());
    g(_g - rhs.getG());
    b(_b - rhs.getB());
    a(_a - rhs.getA());
    return *this;
}

float& ColorRGBAfloat::operator[](size_t index) {
    return asVector()[index];
}

} // namespace utils
} // namespace ellipsoid
