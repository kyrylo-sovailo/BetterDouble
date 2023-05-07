#pragma once

#include "real.hpp"

namespace bd
{
    //Predefine
    template<class T, unsigned int N> class Differentiable;

    //Basic arithmetics
    template<class T, unsigned int N> inline Differentiable<T, N> operator+(const Real<T>              &a, const Differentiable<T, N> &b) { Differentiable<T, N> v; v.value = a.value + b.value; for (unsigned int i = 0; i < N; ++i) v.derivative[i] = b.derivative[i]; return v; };
    template<class T, unsigned int N> inline Differentiable<T, N> operator+(const Differentiable<T, N> &a, const Real<T>              &b) { Differentiable<T, N> v; v.value = a.value + b.value; for (unsigned int i = 0; i < N; ++i) v.derivative[i] = a.derivative[i]; return v; };
    template<class T, unsigned int N> inline Differentiable<T, N> operator+(const Differentiable<T, N> &a, const Differentiable<T, N> &b) { Differentiable<T, N> v; v.value = a.value + b.value; for (unsigned int i = 0; i < N; ++i) v.derivative[i] = a.derivative[i] + b.derivative[i]; return v; };
    template<class T, unsigned int N> inline Differentiable<T, N> operator-(const Real<T>              &a, const Differentiable<T, N> &b) { Differentiable<T, N> v; v.value = a.value - b.value; for (unsigned int i = 0; i < N; ++i) v.derivative[i] = -b.derivative[i]; return v; };
    template<class T, unsigned int N> inline Differentiable<T, N> operator-(const Differentiable<T, N> &a, const Real<T>              &b) { Differentiable<T, N> v; v.value = a.value - b.value; for (unsigned int i = 0; i < N; ++i) v.derivative[i] = a.derivative[i]; return v; };
    template<class T, unsigned int N> inline Differentiable<T, N> operator-(const Differentiable<T, N> &a, const Differentiable<T, N> &b) { Differentiable<T, N> v; v.value = a.value - b.value; for (unsigned int i = 0; i < N; ++i) v.derivative[i] = a.derivative[i] - b.derivative[i]; return v; };
    template<class T, unsigned int N> inline Differentiable<T, N> operator*(const Real<T>              &a, const Differentiable<T, N> &b) { Differentiable<T, N> v; v.value = a.value * b.value; for (unsigned int i = 0; i < N; ++i) v.derivative[i] = a.value * b.derivative[i]; return v; };
    template<class T, unsigned int N> inline Differentiable<T, N> operator*(const Differentiable<T, N> &a, const Real<T>              &b) { Differentiable<T, N> v; v.value = a.value * b.value; for (unsigned int i = 0; i < N; ++i) v.derivative[i] = b.value * a.derivative[i]; return v; };
    template<class T, unsigned int N> inline Differentiable<T, N> operator*(const Differentiable<T, N> &a, const Differentiable<T, N> &b) { Differentiable<T, N> v; v.value = a.value * b.value; for (unsigned int i = 0; i < N; ++i) v.derivative[i] = a.value * b.derivative[i] + b.value * a.derivative[i]; return v; };
    template<class T, unsigned int N> inline Differentiable<T, N> operator/(const Real<T>              &a, const Differentiable<T, N> &b) { Differentiable<T, N> v; v.value = a.value / b.value; for (unsigned int i = 0; i < N; ++i) v.derivative[i] = -a.value * b.derivative[i] / (b.value * b.value); return v; };
    template<class T, unsigned int N> inline Differentiable<T, N> operator/(const Differentiable<T, N> &a, const Real<T>              &b) { Differentiable<T, N> v; v.value = a.value / b.value; for (unsigned int i = 0; i < N; ++i) v.derivative[i] = a.derivative[i] / b.value; return v; };
    template<class T, unsigned int N> inline Differentiable<T, N> operator/(const Differentiable<T, N> &a, const Differentiable<T, N> &b) { Differentiable<T, N> v; v.value = a.value / b.value; for (unsigned int i = 0; i < N; ++i) v.derivative[i] = (a.derivative[i] * b.value - a.value * b.derivative[i]) / (b.value * b.value); return v; };

    ///Same as double, but with overloaded operators
    ///@tparam T Base type
    ///@tparam N Number of derivatives
    template<class T, unsigned int N>
    class Differentiable : public Real<T>
    {
    public:
        //Variables
        T derivative[N];

        //Constructors & assignment
        inline Differentiable()                                        noexcept       {};
        inline Differentiable(const T &other)                          noexcept       { this->value = other;       for (unsigned int i = 0; i < N; ++i) derivative[i] = 0; };
        inline Differentiable(const Real<T> &other)                    noexcept       { this->value = other.value; for (unsigned int i = 0; i < N; ++i) derivative[i] = 0; };
        inline Differentiable(const Differentiable &other)             noexcept       { this->value = other.value; for (unsigned int i = 0; i < N; ++i) derivative[i] = other.derivative[i]; };
        inline Differentiable &operator= (const Real<T> &other)        noexcept       { this->value = other.value; for (unsigned int i = 0; i < N; ++i) derivative[i] = 0; return *this; };
        inline Differentiable &operator= (const Differentiable &other) noexcept       { this->value = other.value; for (unsigned int i = 0; i < N; ++i) derivative[i] = other.derivative[i]; return *this; };

        //Increments/decrements
        inline Differentiable &operator++()                            noexcept       { ++this->value; return *this; };
        inline Differentiable &operator--()                            noexcept       { --this->value; return *this; };
        inline Differentiable operator++ (int)                         noexcept       { Differentiable v = *this; ++v.value; return v; };
        inline Differentiable operator-- (int)                         noexcept       { Differentiable v = *this; --v.value; return v; };

        //Arithmetics
        inline Differentiable &operator+=(const Real<T> &other)        noexcept       { return *this = *this + other; };
        inline Differentiable &operator-=(const Real<T> &other)        noexcept       { return *this = *this - other; };
        inline Differentiable &operator*=(const Real<T> &other)        noexcept       { return *this = *this * other; };
        inline Differentiable &operator/=(const Real<T> &other)        noexcept       { return *this = *this / other; };
        inline Differentiable &operator+=(const Differentiable &other) noexcept       { return *this = *this + other; };
        inline Differentiable &operator-=(const Differentiable &other) noexcept       { return *this = *this - other; };
        inline Differentiable &operator*=(const Differentiable &other) noexcept       { return *this = *this * other; };
        inline Differentiable &operator/=(const Differentiable &other) noexcept       { return *this = *this / other; };

        //Transformations
        inline Differentiable operator+  ()                            const noexcept { return *this; };
        inline Differentiable operator-  ()                            const noexcept { Differentiable v; v.value = -this->value; for (unsigned int i = 0; i < N; ++i) v.derivative[i] = -derivative[i]; return v; };
    };

    //Functions
    template<class T, unsigned int N> inline Differentiable<T, N> cos  (const Differentiable<T, N> &x) noexcept { Differentiable<T, N> v; v.value = std::cos  (x.value); for (unsigned int i = 0; i < N; ++i) v.derivative[i] = -x.derivative[i] * std::sin(x.value);       return v; };
    template<class T, unsigned int N> inline Differentiable<T, N> sin  (const Differentiable<T, N> &x) noexcept { Differentiable<T, N> v; v.value = std::sin  (x.value); for (unsigned int i = 0; i < N; ++i) v.derivative[i] =  x.derivative[i] * std::cos(x.value);       return v; };
    template<class T, unsigned int N> inline Differentiable<T, N> tan  (const Differentiable<T, N> &x) noexcept { Differentiable<T, N> v; v.value = std::tan  (x.value); for (unsigned int i = 0; i < N; ++i) v.derivative[i] =  x.derivative[i] * (v.value + 1);           return v; };
    template<class T, unsigned int N> inline Differentiable<T, N> acos (const Differentiable<T, N> &x) noexcept { Differentiable<T, N> v; v.value = std::acos (x.value); for (unsigned int i = 0; i < N; ++i) v.derivative[i] = -x.derivative[i] / sqrt(1 - x.value);       return v; };
    template<class T, unsigned int N> inline Differentiable<T, N> asin (const Differentiable<T, N> &x) noexcept { Differentiable<T, N> v; v.value = std::asin (x.value); for (unsigned int i = 0; i < N; ++i) v.derivative[i] =  x.derivative[i] / sqrt(1 - x.value);       return v; };
    template<class T, unsigned int N> inline Differentiable<T, N> atan (const Differentiable<T, N> &x) noexcept { Differentiable<T, N> v; v.value = std::atan (x.value); for (unsigned int i = 0; i < N; ++i) v.derivative[i] =  x.derivative[i] / (1 + x.value * x.value); return v; };

    template<class T, unsigned int N> inline Differentiable<T, N> cosh (const Differentiable<T, N> &x) noexcept { Differentiable<T, N> v; v.value = std::cosh (x.value); for (unsigned int i = 0; i < N; ++i) v.derivative[i] =  x.derivative[i] * std::sinh(v.value);                        return v; };
    template<class T, unsigned int N> inline Differentiable<T, N> sinh (const Differentiable<T, N> &x) noexcept { Differentiable<T, N> v; v.value = std::sinh (x.value); for (unsigned int i = 0; i < N; ++i) v.derivative[i] =  x.derivative[i] * std::cosh(v.value);                        return v; };
    template<class T, unsigned int N> inline Differentiable<T, N> tanh (const Differentiable<T, N> &x) noexcept { Differentiable<T, N> v; v.value = std::tanh (x.value); for (unsigned int i = 0; i < N; ++i) v.derivative[i] =  x.derivative[i] / (std::cosh(v.value) * std::cosh(v.value)); return v; };
    template<class T, unsigned int N> inline Differentiable<T, N> acosh(const Differentiable<T, N> &x) noexcept { Differentiable<T, N> v; v.value = std::acosh(x.value); for (unsigned int i = 0; i < N; ++i) v.derivative[i] =  x.derivative[i] / sqrt(x.value * x.value + 1);               return v; };
    template<class T, unsigned int N> inline Differentiable<T, N> asinh(const Differentiable<T, N> &x) noexcept { Differentiable<T, N> v; v.value = std::asinh(x.value); for (unsigned int i = 0; i < N; ++i) v.derivative[i] =  x.derivative[i] / sqrt(x.value * x.value - 1);               return v; };
    template<class T, unsigned int N> inline Differentiable<T, N> atanh(const Differentiable<T, N> &x) noexcept { Differentiable<T, N> v; v.value = std::atanh(x.value); for (unsigned int i = 0; i < N; ++i) v.derivative[i] =  x.derivative[i] / (1 - x.value * x.value);                   return v; };
    
    template<class T, unsigned int N> inline Differentiable<T, N> exp  (const Differentiable<T, N> &x) noexcept { Differentiable<T, N> v; v.value = std::exp  (x.value); for (unsigned int i = 0; i < N; ++i) v.derivative[i] =  x.derivative[i] * v.value;                 return v; };
    template<class T, unsigned int N> inline Differentiable<T, N> log  (const Differentiable<T, N> &x) noexcept { Differentiable<T, N> v; v.value = std::log  (x.value); for (unsigned int i = 0; i < N; ++i) v.derivative[i] =  x.derivative[i] / v.value;                 return v; };
    template<class T, unsigned int N> inline Differentiable<T, N> log10(const Differentiable<T, N> &x) noexcept { Differentiable<T, N> v; v.value = std::log10(x.value); for (unsigned int i = 0; i < N; ++i) v.derivative[i] =  M_LOG10E * x.derivative[i] / v.value;      return v; };
    template<class T, unsigned int N> inline Differentiable<T, N> exp2 (const Differentiable<T, N> &x) noexcept { Differentiable<T, N> v; v.value = std::exp2 (x.value); for (unsigned int i = 0; i < N; ++i) v.derivative[i] =  M_LN2    * x.derivative[i] * v.value;      return v; };
    template<class T, unsigned int N> inline Differentiable<T, N> expm1(const Differentiable<T, N> &x) noexcept { Differentiable<T, N> v; v.value = std::expm1(x.value); for (unsigned int i = 0; i < N; ++i) v.derivative[i] =  x.derivative[i] * (v.value + 1);           return v; };
    template<class T, unsigned int N> inline Differentiable<T, N> log1p(const Differentiable<T, N> &x) noexcept { Differentiable<T, N> v; v.value = std::log1p(x.value); for (unsigned int i = 0; i < N; ++i) v.derivative[i] =  x.derivative[i] / (v.value + 1);           return v; };
    template<class T, unsigned int N> inline Differentiable<T, N> log2 (const Differentiable<T, N> &x) noexcept { Differentiable<T, N> v; v.value = std::log2 (x.value); for (unsigned int i = 0; i < N; ++i) v.derivative[i] =  M_LOG2E  * x.derivative[i] / v.value;      return v; };

    template<class T, unsigned int N> inline Differentiable<T, N> pow  (const Real<T>              &base, const Differentiable<T, N> &exponent) noexcept { Differentiable<T, N> v; v.value = std::pow(base.value, exponent.value); for (unsigned int i = 0; i < N; ++i) v.derivative[i] = std::log(base.value) * std::pow(base.value, exponent.value) * exponent.derivative[i]; return v; };
    template<class T, unsigned int N> inline Differentiable<T, N> pow  (const Differentiable<T, N> &base, const Real<T>              &exponent) noexcept { Differentiable<T, N> v; v.value = std::pow(base.value, exponent.value); for (unsigned int i = 0; i < N; ++i) v.derivative[i] = exponent.value * std::pow(base.value, exponent.value - 1) * base.derivative[i]; return v; };
    template<class T, unsigned int N> inline Differentiable<T, N> pow  (const Differentiable<T, N> &base, const Differentiable<T, N> &exponent) noexcept { Differentiable<T, N> v; v.value = std::pow(base.value, exponent.value); for (unsigned int i = 0; i < N; ++i) v.derivative[i] = exponent.value * std::pow(base.value, exponent.value - 1) * base.derivative[i] + std::log(base.value) * std::pow(base.value, exponent.value) * exponent.derivative[i]; return v; };
    template<class T, unsigned int N> inline Differentiable<T, N> sqrt (const Differentiable<T, N> &x)                                          noexcept { Differentiable<T, N> v; v.value = std::sqrt(x.value);                   for (unsigned int i = 0; i < N; ++i) v.derivative[i] = x.derivative[i] / (2 * sqrt(v.value)); return v; };
    template<class T, unsigned int N> inline Differentiable<T, N> cbrt (const Differentiable<T, N> &x)                                          noexcept { Differentiable<T, N> v; v.value = std::cbrt(x.value);                   for (unsigned int i = 0; i < N; ++i) v.derivative[i] = x.derivative[i] / (3 * cbrt(v.value) * cbrt(v.value)); return v; };
    template<class T, unsigned int N> inline Differentiable<T, N> hypot(const Real<T>              &x,    const Differentiable<T, N> &y)        noexcept { Differentiable<T, N> v; v.value = std::hypot(x.value, y.value);         for (unsigned int i = 0; i < N; ++i) v.derivative[i] = (y.value * y.derivative[i]) / v.value; return v; };
    template<class T, unsigned int N> inline Differentiable<T, N> hypot(const Differentiable<T, N> &x,    const Real<T>              &y)        noexcept { Differentiable<T, N> v; v.value = std::hypot(x.value, y.value);         for (unsigned int i = 0; i < N; ++i) v.derivative[i] = (x.value * x.derivative[i]) / v.value; return v; };
    template<class T, unsigned int N> inline Differentiable<T, N> hypot(const Differentiable<T, N> &x,    const Differentiable<T, N> &y)        noexcept { Differentiable<T, N> v; v.value = std::hypot(x.value, y.value);         for (unsigned int i = 0; i < N; ++i) v.derivative[i] = (x.value * x.derivative[i] + y.value * y.derivative[i]) / v.value; return v; };

    template<class T, unsigned int N> inline Differentiable<T, N> erf  (const Differentiable<T, N> &x) noexcept { Differentiable<T, N> v; v.value = std::erf  (x.value); for (unsigned int i = 0; i < N; ++i) v.derivative[i] =  2 * x.derivative[i] * std::exp(-x.value * x.value) / M_PI;   return v; };
    template<class T, unsigned int N> inline Differentiable<T, N> erfc (const Differentiable<T, N> &x) noexcept { Differentiable<T, N> v; v.value = std::erfc (x.value); for (unsigned int i = 0; i < N; ++i) v.derivative[i] = -2 * x.derivative[i] * std::exp(-x.value * x.value) / M_PI;   return v; };

    template<class T, unsigned int N> inline Differentiable<T, N> abs  (const Differentiable<T, N> &x) noexcept { return ((x.value >= 0) ? (+x) : (-x)); };
    template<class T, unsigned int N> inline Differentiable<T, N> fabs (const Differentiable<T, N> &x) noexcept { return ((x.value >= 0) ? (+x) : (-x)); };

    //Defines
    typedef Differentiable<float, 1> DFloat;
    typedef Differentiable<double, 1> DDouble;
    typedef Differentiable<long double, 1> DLongDouble;
}