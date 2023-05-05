#pragma once

#include <math.h>

namespace bd
{
    ///Same as double, but with overloaded operators
    class Double
    {
    public:
        double value;
        inline Double() {};
        inline Double(double value) : value(value) {};
        inline Double(const Double &other) : value(other.value) {};
        inline Double operator+  ()                    const noexcept { return value; };
        inline Double operator-  ()                    const noexcept { return -value; };
        inline Double &operator++()                    noexcept       { ++value; return *this; };
        inline Double &operator--()                    noexcept       { --value; return *this; };
        inline Double operator++ (int)                 noexcept       { double old = value; ++value; return old; };
        inline Double operator-- (int)                 noexcept       { double old = value; --value; return old; };
        inline Double &operator= (const Double &other) noexcept       { value = other.value;  return *this; };
        inline Double &operator+=(const Double &other) noexcept       { value += other.value; return *this; };
        inline Double &operator-=(const Double &other) noexcept       { value -= other.value; return *this; };
        inline Double &operator*=(const Double &other) noexcept       { value *= other.value; return *this; };
        inline Double &operator/=(const Double &other) noexcept       { value /= other.value; return *this; };
        inline operator bool     ()                    const noexcept { return value; };
    };

    inline Double operator+ (const Double &a, const Double &b) { return a.value +  b.value; };
    inline Double operator- (const Double &a, const Double &b) { return a.value -  b.value; };
    inline Double operator* (const Double &a, const Double &b) { return a.value *  b.value; };
    inline Double operator/ (const Double &a, const Double &b) { return a.value /  b.value; };
    inline Double operator==(const Double &a, const Double &b) { return a.value == b.value; };
    inline Double operator!=(const Double &a, const Double &b) { return a.value != b.value; };
    inline Double operator> (const Double &a, const Double &b) { return a.value >  b.value; };
    inline Double operator< (const Double &a, const Double &b) { return a.value <  b.value; };
    inline Double operator>=(const Double &a, const Double &b) { return a.value >= b.value; };
    inline Double operator<=(const Double &a, const Double &b) { return a.value <= b.value; };

    inline Double acos (const Double &a) noexcept { return ::acos (a.value); };
    inline Double asin (const Double &a) noexcept { return ::asin (a.value); };
    inline Double atan (const Double &a) noexcept { return ::atan (a.value); };
    inline Double cos  (const Double &a) noexcept { return ::cos  (a.value); };
    inline Double cosh (const Double &a) noexcept { return ::cosh (a.value); };
    inline Double sin  (const Double &a) noexcept { return ::sin  (a.value); };
    inline Double sinh (const Double &a) noexcept { return ::sinh (a.value); };
    inline Double tanh (const Double &a) noexcept { return ::tanh (a.value); };
    inline Double exp  (const Double &a) noexcept { return ::exp  (a.value); };
    inline Double log  (const Double &a) noexcept { return ::log  (a.value); };
    inline Double log10(const Double &a) noexcept { return ::log10(a.value); };
    inline Double sqrt (const Double &a) noexcept { return ::sqrt (a.value); };
    inline Double ceil (const Double &a) noexcept { return ::ceil (a.value); };
    inline Double fabs (const Double &a) noexcept { return ::fabs (a.value); };
    inline Double floor(const Double &a) noexcept { return ::floor(a.value); };
    inline Double atan2(const Double &a, const Double &b) noexcept { return ::atan2(a.value, b.value);   };
    inline Double pow  (const Double &a, const Double &b) noexcept { return ::pow  (a.value, b.value);   };
    inline Double fmod (const Double &a, const Double &b) noexcept { return ::fmod (a.value, b.value);   };
    inline Double frexp(const Double &a, int *b)          noexcept { return ::frexp(a.value, b);         };
    inline Double ldexp(const Double &a, int b)           noexcept { return ::ldexp(a.value, b);         };
    inline Double modf (const Double &a, Double *b)       noexcept { return ::modf (a.value, &b->value); };
}