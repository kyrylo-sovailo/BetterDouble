#pragma once

#include <cmath>
#include <limits>
#include <ostream>
#include <istream>
#include <sstream>
#include <string>

namespace bd
{
    //Predefine
    template<class T, unsigned int N> class Differentiable;

    //Basic arithmetics
    template<class T, unsigned int N> constexpr inline Differentiable<T, N> operator+(const Differentiable<T, N> &a, const Differentiable<T, N> &b) { Differentiable<T, N> v; v.value = a.value + b.value; for (unsigned int i = 0; i < N; ++i) v.derivative[i] = a.derivative[i] + b.derivative[i]; return v; };
    template<class T, unsigned int N> constexpr inline Differentiable<T, N> operator-(const Differentiable<T, N> &a, const Differentiable<T, N> &b) { Differentiable<T, N> v; v.value = a.value - b.value; for (unsigned int i = 0; i < N; ++i) v.derivative[i] = a.derivative[i] - b.derivative[i]; return v; };
    template<class T, unsigned int N> constexpr inline Differentiable<T, N> operator*(const Differentiable<T, N> &a, const Differentiable<T, N> &b) { Differentiable<T, N> v; v.value = a.value * b.value; for (unsigned int i = 0; i < N; ++i) v.derivative[i] = a.value * b.derivative[i] + b.value * a.derivative[i]; return v; };
    template<class T, unsigned int N> constexpr inline Differentiable<T, N> operator/(const Differentiable<T, N> &a, const Differentiable<T, N> &b) { Differentiable<T, N> v; v.value = a.value / b.value; for (unsigned int i = 0; i < N; ++i) v.derivative[i] = (a.derivative[i] * b.value - a.value * b.derivative[i]) / (b.value * b.value); return v; };

    ///Same as double, but with overloaded operators
    ///@tparam T Base type
    ///@tparam N Number of derivatives
    template<class T, unsigned int N>
    class Differentiable
    {
    public:
        //Variables
        T value;
        T derivative[N];

        //Constructors & assignment
        constexpr inline explicit Differentiable()                         noexcept { this->value = 0;           for (unsigned int i = 0; i < N; ++i) derivative[i] = 0; };
        constexpr inline Differentiable(const T &other)                    noexcept { this->value = other;       for (unsigned int i = 0; i < N; ++i) derivative[i] = 0; };
        constexpr inline Differentiable(const Differentiable<T, N> &other) noexcept { this->value = other.value; for (unsigned int i = 0; i < N; ++i) derivative[i] = other.derivative[i]; };

        //Increments/decrements
        constexpr inline Differentiable &operator++()    noexcept { ++this->value; return *this; };
        constexpr inline Differentiable &operator--()    noexcept { --this->value; return *this; };
        constexpr inline Differentiable operator++ (int) noexcept { Differentiable v = *this; ++v.value; return v; };
        constexpr inline Differentiable operator-- (int) noexcept { Differentiable v = *this; --v.value; return v; };

        //Arithmetics
        constexpr inline Differentiable &operator+=(const Differentiable &other) noexcept { for (unsigned int i = 0; i < N; ++i) derivative[i] += other.derivative[i]; return *this; value += other.value; };
        constexpr inline Differentiable &operator-=(const Differentiable &other) noexcept { for (unsigned int i = 0; i < N; ++i) derivative[i] -= other.derivative[i]; return *this; value -= other.value; };
        constexpr inline Differentiable &operator*=(const Differentiable &other) noexcept { for (unsigned int i = 0; i < N; ++i) derivative[i] = derivative[i] * other.value + other.derivative[i] * value; value *= other.value; return *this; };
        constexpr inline Differentiable &operator/=(const Differentiable &other) noexcept { for (unsigned int i = 0; i < N; ++i) derivative[i] = (derivative[i] * other.value - other.derivative[i] * value) / (other.value * other.value); value /= other.value; return *this; };

        //Transformations
        constexpr inline Differentiable operator+() const noexcept { return *this; };
        constexpr inline Differentiable operator-() const noexcept { Differentiable v; v.value = -this->value; for (unsigned int i = 0; i < N; ++i) v.derivative[i] = -derivative[i]; return v; };

        //Cast
        constexpr inline explicit operator T() noexcept { return value; };
    };

    //Comparison
    template<class T, unsigned int N> constexpr inline bool operator==(const Differentiable<T, N> &a, const Differentiable<T, N> &b) { return a.value == b.value; };
    template<class T, unsigned int N> constexpr inline bool operator!=(const Differentiable<T, N> &a, const Differentiable<T, N> &b) { return a.value != b.value; };
    template<class T, unsigned int N> constexpr inline bool operator> (const Differentiable<T, N> &a, const Differentiable<T, N> &b) { return a.value >  b.value; };
    template<class T, unsigned int N> constexpr inline bool operator< (const Differentiable<T, N> &a, const Differentiable<T, N> &b) { return a.value <  b.value; };
    template<class T, unsigned int N> constexpr inline bool operator>=(const Differentiable<T, N> &a, const Differentiable<T, N> &b) { return a.value >= b.value; };
    template<class T, unsigned int N> constexpr inline bool operator<=(const Differentiable<T, N> &a, const Differentiable<T, N> &b) { return a.value <= b.value; };

    //Trigonometric functions
    template<class T, unsigned int N> constexpr inline Differentiable<T, N> cos  (const Differentiable<T, N> &x) noexcept { Differentiable<T, N> v; v.value = std::cos  (x.value); for (unsigned int i = 0; i < N; ++i) v.derivative[i] = -x.derivative[i] * std::sin(x.value);       return v; };
    template<class T, unsigned int N> constexpr inline Differentiable<T, N> sin  (const Differentiable<T, N> &x) noexcept { Differentiable<T, N> v; v.value = std::sin  (x.value); for (unsigned int i = 0; i < N; ++i) v.derivative[i] =  x.derivative[i] * std::cos(x.value);       return v; };
    template<class T, unsigned int N> constexpr inline Differentiable<T, N> tan  (const Differentiable<T, N> &x) noexcept { Differentiable<T, N> v; v.value = std::tan  (x.value); for (unsigned int i = 0; i < N; ++i) v.derivative[i] =  x.derivative[i] * (v.value + 1);           return v; };
    template<class T, unsigned int N> constexpr inline Differentiable<T, N> acos (const Differentiable<T, N> &x) noexcept { Differentiable<T, N> v; v.value = std::acos (x.value); for (unsigned int i = 0; i < N; ++i) v.derivative[i] = -x.derivative[i] / sqrt(1 - x.value);       return v; };
    template<class T, unsigned int N> constexpr inline Differentiable<T, N> asin (const Differentiable<T, N> &x) noexcept { Differentiable<T, N> v; v.value = std::asin (x.value); for (unsigned int i = 0; i < N; ++i) v.derivative[i] =  x.derivative[i] / sqrt(1 - x.value);       return v; };
    template<class T, unsigned int N> constexpr inline Differentiable<T, N> atan (const Differentiable<T, N> &x) noexcept { Differentiable<T, N> v; v.value = std::atan (x.value); for (unsigned int i = 0; i < N; ++i) v.derivative[i] =  x.derivative[i] / (1 + x.value * x.value); return v; };

    //Hyperbolic functions
    template<class T, unsigned int N> constexpr inline Differentiable<T, N> cosh (const Differentiable<T, N> &x) noexcept { Differentiable<T, N> v; v.value = std::cosh (x.value); for (unsigned int i = 0; i < N; ++i) v.derivative[i] =  x.derivative[i] * std::sinh(v.value);                        return v; };
    template<class T, unsigned int N> constexpr inline Differentiable<T, N> sinh (const Differentiable<T, N> &x) noexcept { Differentiable<T, N> v; v.value = std::sinh (x.value); for (unsigned int i = 0; i < N; ++i) v.derivative[i] =  x.derivative[i] * std::cosh(v.value);                        return v; };
    template<class T, unsigned int N> constexpr inline Differentiable<T, N> tanh (const Differentiable<T, N> &x) noexcept { Differentiable<T, N> v; v.value = std::tanh (x.value); for (unsigned int i = 0; i < N; ++i) v.derivative[i] =  x.derivative[i] / (std::cosh(v.value) * std::cosh(v.value)); return v; };
    template<class T, unsigned int N> constexpr inline Differentiable<T, N> acosh(const Differentiable<T, N> &x) noexcept { Differentiable<T, N> v; v.value = std::acosh(x.value); for (unsigned int i = 0; i < N; ++i) v.derivative[i] =  x.derivative[i] / sqrt(x.value * x.value + 1);               return v; };
    template<class T, unsigned int N> constexpr inline Differentiable<T, N> asinh(const Differentiable<T, N> &x) noexcept { Differentiable<T, N> v; v.value = std::asinh(x.value); for (unsigned int i = 0; i < N; ++i) v.derivative[i] =  x.derivative[i] / sqrt(x.value * x.value - 1);               return v; };
    template<class T, unsigned int N> constexpr inline Differentiable<T, N> atanh(const Differentiable<T, N> &x) noexcept { Differentiable<T, N> v; v.value = std::atanh(x.value); for (unsigned int i = 0; i < N; ++i) v.derivative[i] =  x.derivative[i] / (1 - x.value * x.value);                   return v; };
    
    //Exponential and logarithmic functions
    template<class T, unsigned int N> constexpr inline Differentiable<T, N> exp  (const Differentiable<T, N> &x) noexcept { Differentiable<T, N> v; v.value = std::exp  (x.value); for (unsigned int i = 0; i < N; ++i) v.derivative[i] =  x.derivative[i] * v.value;                 return v; };
    template<class T, unsigned int N> constexpr inline Differentiable<T, N> log  (const Differentiable<T, N> &x) noexcept { Differentiable<T, N> v; v.value = std::log  (x.value); for (unsigned int i = 0; i < N; ++i) v.derivative[i] =  x.derivative[i] / v.value;                 return v; };
    template<class T, unsigned int N> constexpr inline Differentiable<T, N> log10(const Differentiable<T, N> &x) noexcept { Differentiable<T, N> v; v.value = std::log10(x.value); for (unsigned int i = 0; i < N; ++i) v.derivative[i] =  M_LOG10E * x.derivative[i] / v.value;      return v; };
    template<class T, unsigned int N> constexpr inline Differentiable<T, N> exp2 (const Differentiable<T, N> &x) noexcept { Differentiable<T, N> v; v.value = std::exp2 (x.value); for (unsigned int i = 0; i < N; ++i) v.derivative[i] =  M_LN2    * x.derivative[i] * v.value;      return v; };
    template<class T, unsigned int N> constexpr inline Differentiable<T, N> expm1(const Differentiable<T, N> &x) noexcept { Differentiable<T, N> v; v.value = std::expm1(x.value); for (unsigned int i = 0; i < N; ++i) v.derivative[i] =  x.derivative[i] * (v.value + 1);           return v; };
    template<class T, unsigned int N> constexpr inline Differentiable<T, N> log1p(const Differentiable<T, N> &x) noexcept { Differentiable<T, N> v; v.value = std::log1p(x.value); for (unsigned int i = 0; i < N; ++i) v.derivative[i] =  x.derivative[i] / (v.value + 1);           return v; };
    template<class T, unsigned int N> constexpr inline Differentiable<T, N> log2 (const Differentiable<T, N> &x) noexcept { Differentiable<T, N> v; v.value = std::log2 (x.value); for (unsigned int i = 0; i < N; ++i) v.derivative[i] =  M_LOG2E  * x.derivative[i] / v.value;      return v; };

    //Power functions
    template<class T, unsigned int N> constexpr inline Differentiable<T, N> pow  (const Differentiable<T, N> &base, const Differentiable<T, N> &exponent) noexcept { Differentiable<T, N> v; v.value = std::pow(base.value, exponent.value); for (unsigned int i = 0; i < N; ++i) v.derivative[i] = exponent.value * std::pow(base.value, exponent.value - 1) * base.derivative[i] + std::log(base.value) * std::pow(base.value, exponent.value) * exponent.derivative[i]; return v; };
    template<class T, unsigned int N> constexpr inline Differentiable<T, N> sqrt (const Differentiable<T, N> &x)                                          noexcept { Differentiable<T, N> v; v.value = std::sqrt(x.value);                   for (unsigned int i = 0; i < N; ++i) v.derivative[i] = x.derivative[i] / (2 * std::sqrt(v.value)); return v; };
    template<class T, unsigned int N> constexpr inline Differentiable<T, N> cbrt (const Differentiable<T, N> &x)                                          noexcept { Differentiable<T, N> v; v.value = std::cbrt(x.value);                   for (unsigned int i = 0; i < N; ++i) v.derivative[i] = x.derivative[i] / (3 * std::cbrt(v.value) * std::cbrt(v.value)); return v; };
    template<class T, unsigned int N> constexpr inline Differentiable<T, N> hypot(const Differentiable<T, N> &x,    const Differentiable<T, N> &y)        noexcept { Differentiable<T, N> v; v.value = std::hypot(x.value, y.value);         for (unsigned int i = 0; i < N; ++i) v.derivative[i] = (x.value * x.derivative[i] + y.value * y.derivative[i]) / v.value; return v; };

    //Error and gamma functions
    template<class T, unsigned int N> constexpr inline Differentiable<T, N> erf   (const Differentiable<T, N> &x) noexcept { Differentiable<T, N> v; v.value = std::erf   (x.value); for (unsigned int i = 0; i < N; ++i) v.derivative[i] =  2 * x.derivative[i] * std::exp(-x.value * x.value) / M_PI;   return v; };
    template<class T, unsigned int N> constexpr inline Differentiable<T, N> erfc  (const Differentiable<T, N> &x) noexcept { Differentiable<T, N> v; v.value = std::erfc  (x.value); for (unsigned int i = 0; i < N; ++i) v.derivative[i] = -2 * x.derivative[i] * std::exp(-x.value * x.value) / M_PI;   return v; };
    template<class T, unsigned int N> constexpr inline Differentiable<T, N> tgamma(const Differentiable<T, N> &x) noexcept { Differentiable<T, N> v; v.value = std::tgamma(x.value); for (unsigned int i = 0; i < N; ++i) v.derivative[i] = std::numeric_limits<T>::quiet_NaN(); return v; };
    template<class T, unsigned int N> constexpr inline Differentiable<T, N> lgamma(const Differentiable<T, N> &x) noexcept { Differentiable<T, N> v; v.value = std::lgamma(x.value); for (unsigned int i = 0; i < N; ++i) v.derivative[i] = std::numeric_limits<T>::quiet_NaN(); return v; };

    //Rounding and remainder functions
    template<class T, unsigned int N> constexpr inline Differentiable<T, N> ceil     (const Differentiable<T, N> &x) noexcept { return (Differentiable<T, N>)std::ceil     (x.value); };
    template<class T, unsigned int N> constexpr inline Differentiable<T, N> floor    (const Differentiable<T, N> &x) noexcept { return (Differentiable<T, N>)std::floor    (x.value); };
    template<class T, unsigned int N> constexpr inline Differentiable<T, N> fmod     (const Differentiable<T, N> &x) noexcept { return (Differentiable<T, N>)std::fmod     (x.value); };
    template<class T, unsigned int N> constexpr inline Differentiable<T, N> trunc    (const Differentiable<T, N> &x) noexcept { return (Differentiable<T, N>)std::trunc    (x.value); };
    template<class T, unsigned int N> constexpr inline Differentiable<T, N> round    (const Differentiable<T, N> &x) noexcept { return (Differentiable<T, N>)std::round    (x.value); };
    template<class T, unsigned int N> constexpr inline long int             lround   (const Differentiable<T, N> &x) noexcept { return std::lround   (x.value); };
    template<class T, unsigned int N> constexpr inline long long int        llround  (const Differentiable<T, N> &x) noexcept { return std::llround  (x.value); };
    template<class T, unsigned int N> constexpr inline Differentiable<T, N> rint     (const Differentiable<T, N> &x) noexcept { return (Differentiable<T, N>)std::rint     (x.value); };
    template<class T, unsigned int N> constexpr inline long int             lrint    (const Differentiable<T, N> &x) noexcept { return std::lrint    (x.value); };
    template<class T, unsigned int N> constexpr inline long long int        llrint   (const Differentiable<T, N> &x) noexcept { return std::llrint   (x.value); };
    template<class T, unsigned int N> constexpr inline Differentiable<T, N> nearbyint(const Differentiable<T, N> &x) noexcept { return (Differentiable<T, N>)std::nearbyint(x.value); };
    template<class T, unsigned int N> constexpr inline Differentiable<T, N> remainder(const Differentiable<T, N> &numer, const Differentiable<T, N> &denom)            noexcept { return (Differentiable<T, N>)std::remainder(numer.value, denom.value); };
    template<class T, unsigned int N> constexpr inline Differentiable<T, N> remquo   (const Differentiable<T, N> &numer, const Differentiable<T, N> &denom, int *quot) noexcept { return (Differentiable<T, N>)std::remquo   (numer.value, denom.value, quot); };

    //Floating-point manipulation functions
    template<class T, unsigned int N> constexpr inline Differentiable<T, N> copysign  (const Differentiable<T, N> &mag, const Differentiable<T, N> &sgn) noexcept { return (std::isnan(mag.value)) ? ((Differentiable<T, N>)(sgn.value > 0 - sgn.value < 0)) : ((std::signbit(mag.value) == std::signbit(sgn.value)) ? (mag) : (-mag)); };
    template<class T, unsigned int N> constexpr inline Differentiable<T, N> nan       (const char* tagp)                                                 noexcept { return (Differentiable<T, N>)std::nan       (tagp); };
    template<class T, unsigned int N> constexpr inline Differentiable<T, N> nextafter (const Differentiable<T, N> &x,   const Differentiable<T, N> &y)   noexcept { return (Differentiable<T, N>)std::nextafter (x.value, y.value); };
    template<class T, unsigned int N> constexpr inline Differentiable<T, N> nexttoward(const Differentiable<T, N> &x,   const Differentiable<T, N> &y)   noexcept { return (Differentiable<T, N>)std::nexttoward(x.value, y.value); };
    
    //Minimum, maximum, difference functions
    template<class T, unsigned int N> constexpr inline Differentiable<T, N> fdim(const Differentiable<T, N> &x, const Differentiable<T, N> &y) noexcept { return (x > y) ? (x - y) : ((Differentiable<T, N>)0); };
    template<class T, unsigned int N> constexpr inline Differentiable<T, N> fmax(const Differentiable<T, N> &x, const Differentiable<T, N> &y) noexcept { if (std::isnan(x.value)) return y; if (std::isnan(y.value)) return x; return (x > y) ? (x) : (y); };
    template<class T, unsigned int N> constexpr inline Differentiable<T, N> fmin(const Differentiable<T, N> &x, const Differentiable<T, N> &y) noexcept { if (std::isnan(x.value)) return y; if (std::isnan(y.value)) return x; return (x < y) ? (x) : (y); };
    
    //Other functions
    template<class T, unsigned int N> constexpr inline Differentiable<T, N> fabs(const Differentiable<T, N> &x) noexcept { Differentiable<T, N> v; v.value = std::fabs(x.value); for (unsigned int i = 0; i < N; ++i) v.derivative[i] = ((x.value == 0) ? (std::numeric_limits<T>::quiet_NaN()) : ((x.value > 0) ? (x.derivative[i]) : (-x.derivative[i]))); return v; };
    template<class T, unsigned int N> constexpr inline Differentiable<T, N> abs (const Differentiable<T, N> &x) noexcept { Differentiable<T, N> v; v.value = std::abs (x.value); for (unsigned int i = 0; i < N; ++i) v.derivative[i] = ((x.value == 0) ? (std::numeric_limits<T>::quiet_NaN()) : ((x.value > 0) ? (x.derivative[i]) : (-x.derivative[i]))); return v; };
    template<class T, unsigned int N> constexpr inline Differentiable<T, N> fma (const Differentiable<T, N> &x, const Differentiable<T, N> &y, const Differentiable<T, N> &z) noexcept { return x * y + z; };

    //Classification macro / functions
    template<class T, unsigned int N> constexpr inline int  fpclassify(const Differentiable<T, N> &x) noexcept { return std::fpclassify(x.value); }
    template<class T, unsigned int N> constexpr inline bool isfinite  (const Differentiable<T, N> &x) noexcept { return std::isfinite  (x.value); }
    template<class T, unsigned int N> constexpr inline bool isinf     (const Differentiable<T, N> &x) noexcept { return std::isinf     (x.value); }
    template<class T, unsigned int N> constexpr inline bool isnan     (const Differentiable<T, N> &x) noexcept { return std::isnan     (x.value); }
    template<class T, unsigned int N> constexpr inline bool isnormal  (const Differentiable<T, N> &x) noexcept { return std::isnormal  (x.value); }
    template<class T, unsigned int N> constexpr inline bool signbit   (const Differentiable<T, N> &x) noexcept { return std::signbit   (x.value); }

    //Comparison macro / functions
    template<class T, unsigned int N> constexpr inline bool isgreater     (const Differentiable<T, N> &x, const Differentiable<T, N> &y) noexcept { return std::isgreater     (x.value, y.value); }
    template<class T, unsigned int N> constexpr inline bool isgreaterequal(const Differentiable<T, N> &x, const Differentiable<T, N> &y) noexcept { return std::isgreaterequal(x.value, y.value); }
    template<class T, unsigned int N> constexpr inline bool isless        (const Differentiable<T, N> &x, const Differentiable<T, N> &y) noexcept { return std::isless        (x.value, y.value); }
    template<class T, unsigned int N> constexpr inline bool islessequal   (const Differentiable<T, N> &x, const Differentiable<T, N> &y) noexcept { return std::islessequal   (x.value, y.value); }
    template<class T, unsigned int N> constexpr inline bool islessgreater (const Differentiable<T, N> &x, const Differentiable<T, N> &y) noexcept { return std::islessgreater (x.value, y.value); }
    template<class T, unsigned int N> constexpr inline bool isunordered   (const Differentiable<T, N> &x, const Differentiable<T, N> &y) noexcept { return std::isunordered   (x.value, y.value); }

    //Defines
    typedef Differentiable<float, 1> DFloat;
    typedef Differentiable<double, 1> DDouble;
    typedef Differentiable<long double, 1> DLongDouble;
}

namespace std
{
    template<class C, class T, unsigned int N> basic_ostream<C> &operator<<(basic_ostream<C> &os, const bd::Differentiable<T, N> &x)
    {
        os << x.value;
        for (unsigned int i = 0; i < N; i++) { os << ' ' << x.derivative[i]; }
        return os;
    }

    template<class C, class T, unsigned int N> basic_istream<C> &operator>>(basic_istream<C> &is, const bd::Differentiable<T, N> &x)
    {
        is >> x.value;
        for (unsigned int i = 0; i < N; i++) { is >> ' ' >> x.derivative[i]; }
        return is;
    }

    template<class T, unsigned int N> std::string to_string(const bd::Differentiable<T, N> &x)
    {
        std::stringstream str;
        str << x.value;
        for (unsigned int i = 0; i < N; i++) { str << ' ' << x.derivative[i]; }
        return str.str();
    }

    template<class T, unsigned int N> std::wstring to_wstring(const bd::Differentiable<T, N> &x)
    {
        std::wstringstream str;
        str << x.value;
        for (unsigned int i = 0; i < N; i++) { str << ' ' << x.derivative[i]; }
        return str.str();
    }
};