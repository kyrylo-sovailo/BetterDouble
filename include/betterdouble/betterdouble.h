#pragma once

#include <cmath>

namespace bd
{
    ///Same as double, but with overloaded operators
    template<class T>
    class Real
    {
    public:
        T value;
        inline Real() {};
        inline Real(T value) : value(value) {};
        inline Real(const Real &other) : value(other.value) {};
        inline Real operator+  ()                  const noexcept { return value; };
        inline Real operator-  ()                  const noexcept { return -value; };
        inline Real &operator++()                  noexcept       { ++value; return *this; };
        inline Real &operator--()                  noexcept       { --value; return *this; };
        inline Real operator++ (int)               noexcept       { T old = value; ++value; return old; };
        inline Real operator-- (int)               noexcept       { T old = value; --value; return old; };
        inline Real &operator= (const Real &other) noexcept       { value = other.value;  return *this; };
        inline Real &operator+=(const Real &other) noexcept       { value += other.value; return *this; };
        inline Real &operator-=(const Real &other) noexcept       { value -= other.value; return *this; };
        inline Real &operator*=(const Real &other) noexcept       { value *= other.value; return *this; };
        inline Real &operator/=(const Real &other) noexcept       { value /= other.value; return *this; };
        inline operator bool   ()                  const noexcept { return value; };
    };

    template<class T> inline Real<T> operator+ (const Real<T> &a, const Real<T> &b) { return a.value +  b.value; };
    template<class T> inline Real<T> operator- (const Real<T> &a, const Real<T> &b) { return a.value -  b.value; };
    template<class T> inline Real<T> operator* (const Real<T> &a, const Real<T> &b) { return a.value *  b.value; };
    template<class T> inline Real<T> operator/ (const Real<T> &a, const Real<T> &b) { return a.value /  b.value; };
    template<class T> inline Real<T> operator==(const Real<T> &a, const Real<T> &b) { return a.value == b.value; };
    template<class T> inline Real<T> operator!=(const Real<T> &a, const Real<T> &b) { return a.value != b.value; };
    template<class T> inline Real<T> operator> (const Real<T> &a, const Real<T> &b) { return a.value >  b.value; };
    template<class T> inline Real<T> operator< (const Real<T> &a, const Real<T> &b) { return a.value <  b.value; };
    template<class T> inline Real<T> operator>=(const Real<T> &a, const Real<T> &b) { return a.value >= b.value; };
    template<class T> inline Real<T> operator<=(const Real<T> &a, const Real<T> &b) { return a.value <= b.value; };

    template<class T> inline Real<T> acos (const Real<T> &a) noexcept { return std::acos (a.value); };
    template<class T> inline Real<T> asin (const Real<T> &a) noexcept { return std::asin (a.value); };
    template<class T> inline Real<T> atan (const Real<T> &a) noexcept { return std::atan (a.value); };
    template<class T> inline Real<T> cos  (const Real<T> &a) noexcept { return std::cos  (a.value); };
    template<class T> inline Real<T> cosh (const Real<T> &a) noexcept { return std::cosh (a.value); };
    template<class T> inline Real<T> sin  (const Real<T> &a) noexcept { return std::sin  (a.value); };
    template<class T> inline Real<T> sinh (const Real<T> &a) noexcept { return std::sinh (a.value); };
    template<class T> inline Real<T> tanh (const Real<T> &a) noexcept { return std::tanh (a.value); };
    template<class T> inline Real<T> exp  (const Real<T> &a) noexcept { return std::exp  (a.value); };
    template<class T> inline Real<T> log  (const Real<T> &a) noexcept { return std::log  (a.value); };
    template<class T> inline Real<T> log10(const Real<T> &a) noexcept { return std::log10(a.value); };
    template<class T> inline Real<T> sqrt (const Real<T> &a) noexcept { return std::sqrt (a.value); };
    template<class T> inline Real<T> ceil (const Real<T> &a) noexcept { return std::ceil (a.value); };
    template<class T> inline Real<T> fabs (const Real<T> &a) noexcept { return std::fabs (a.value); };
    template<class T> inline Real<T> floor(const Real<T> &a) noexcept { return std::floor(a.value); };
    template<class T> inline Real<T> atan2(const Real<T> &a, const Real<T> &b) noexcept { return std::atan2(a.value, b.value);   };
    template<class T> inline Real<T> pow  (const Real<T> &a, const Real<T> &b) noexcept { return std::pow  (a.value, b.value);   };
    template<class T> inline Real<T> fmod (const Real<T> &a, const Real<T> &b) noexcept { return std::fmod (a.value, b.value);   };
    template<class T> inline Real<T> frexp(const Real<T> &a, int *b)           noexcept { return std::frexp(a.value, b);         };
    template<class T> inline Real<T> ldexp(const Real<T> &a, int b)            noexcept { return std::ldexp(a.value, b);         };
    template<class T> inline Real<T> modf (const Real<T> &a, Real<T> *b)       noexcept { return std::modf (a.value, &b->value); };

    typedef Real<double> Double;
    typedef Real<float> Float;
}