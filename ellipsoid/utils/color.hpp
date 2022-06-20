#ifndef ELLIPSOID_UTILS_COLOR_HEADER
#define ELLIPSOID_UTILS_COLOR_HEADER

#define ELLIPSOID_COLOR255_MIN 0
#define ELLIPSOID_COLOR255_MAX 255
#define ELLIPSOID_COLOR_FLOAT_MIN 0.0f
#define ELLIPSOID_COLOR_FLOAT_MAX 1.0f

#include <vector>

namespace ellipsoid {
namespace utils {

// TODO: Implement polymorphism to simplify colors
class ColorRGBAfloat {
private:
    float _r;
    float _g;
    float _b;
    float _a;

    static float limitValue(const float value);

public:
    ColorRGBAfloat();
    ColorRGBAfloat(const float r, const float g, const float b);
    ColorRGBAfloat(const float r, const float g, const float b,
              const float a);

    void r(const float val);
    void g(const float val);
    void b(const float val);
    void a(const float val);

    float getR() const { return _r; };
    float getG() const { return _g; };
    float getB() const { return _b; };
    float getA() const { return _a; };

    std::vector<float> asVector() const;

    const ColorRGBAfloat operator+(const ColorRGBAfloat& rhs);
    const ColorRGBAfloat operator-(const ColorRGBAfloat& rhs);
    ColorRGBAfloat& operator+=(const ColorRGBAfloat& rhs);
    ColorRGBAfloat& operator-=(const ColorRGBAfloat& rhs);

    float& operator[](size_t index);
};

class ColorRGBA255 {
private:
    unsigned int _r;
    unsigned int _g;
    unsigned int _b;
    unsigned int _a;

    static unsigned int limitValue(const unsigned int value);

public:
    ColorRGBA255();
    ColorRGBA255(const unsigned int r, const unsigned int g, const unsigned int b);
    ColorRGBA255(const unsigned int r, const unsigned int g, const unsigned int b,
              const unsigned int a);

    void r(const unsigned int val);
    void g(const unsigned int val);
    void b(const unsigned int val);
    void a(const unsigned int val);

    unsigned int getR() const { return _r; };
    unsigned int getG() const { return _g; };
    unsigned int getB() const { return _b; };
    unsigned int getA() const { return _a; };

    std::vector<unsigned int> asVector() const;
    ColorRGBAfloat asRGBAfloat() const;

    const ColorRGBA255 operator+(const ColorRGBA255& rhs);
    const ColorRGBA255 operator-(const ColorRGBA255& rhs);
    ColorRGBA255& operator+=(const ColorRGBA255& rhs);
    ColorRGBA255& operator-=(const ColorRGBA255& rhs);

    unsigned int& operator[](size_t index);
};

} // namespace utils
} // namespace ellipsoid

#endif
