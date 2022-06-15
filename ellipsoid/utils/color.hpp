#ifndef ELLIPSOID_UTILS_COLOR_HEADER
#define ELLIPSOID_UTILS_COLOR_HEADER

#define ELLIPSOID_COLOR_MIN 0
#define ELLIPSOID_COLOR_MAX 255

namespace ellipsoid {
namespace utils {

class ColorRGBA {
private:
    unsigned int _r;
    unsigned int _g;
    unsigned int _b;
    unsigned int _a;

    static unsigned int limitValue(const unsigned int value);

public:
    ColorRGBA();
    ColorRGBA(const unsigned int r, const unsigned int g, const unsigned int b);
    ColorRGBA(const unsigned int r, const unsigned int g, const unsigned int b,
              const unsigned int a);

    void r(unsigned int val);
    void g(unsigned int val);
    void b(unsigned int val);
    void a(unsigned int val);

    unsigned int getR() const { return _r; };
    unsigned int getG() const { return _g; };
    unsigned int getB() const { return _b; };
    unsigned int getA() const { return _a; };

    const ColorRGBA operator+(const ColorRGBA& rhs);
    const ColorRGBA operator-(const ColorRGBA& rhs);
    ColorRGBA& operator+=(const ColorRGBA& rhs);
    ColorRGBA& operator-=(const ColorRGBA& rhs);
};

} // namespace utils
} // namespace ellipsoid

#endif
