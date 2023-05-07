#pragma once

#include <cmath>

namespace bd
{
    //Predefine
    template<class T> class Real;

    //Basic arithmetics
    template<class T> inline Real<T> operator+ (const Real<T> &a, const Real<T> &b) { return a.value + b.value; };
    template<class T> inline Real<T> operator- (const Real<T> &a, const Real<T> &b) { return a.value - b.value; };
    template<class T> inline Real<T> operator* (const Real<T> &a, const Real<T> &b) { return a.value * b.value; };
    template<class T> inline Real<T> operator/ (const Real<T> &a, const Real<T> &b) { return a.value / b.value; };

    ///Same as double, but with overloaded operators
    ///@tparam T Base type
    template<class T = double>
    class Real
    {
    public:
        //Variables
        T value;

        //Constructors & assignment
        inline Real()                              noexcept       {};
        inline Real(T other)                       noexcept       { value = other; };
        inline Real(const Real &other)             noexcept       { value = other.value; };
        inline Real &operator= (const Real &other) noexcept       { value = other.value;  return *this; };

        //Increments/decrements
        inline Real &operator++()                  noexcept       { ++value; return *this; };
        inline Real &operator--()                  noexcept       { --value; return *this; };
        inline Real operator++ (int)               noexcept       { Real v = *this; ++v.value; return v; };
        inline Real operator-- (int)               noexcept       { Real v = *this; --v.value; return v; };

        //Arithmetics
        inline Real &operator+=(const Real &other) noexcept       { return *this = *this + other; };
        inline Real &operator-=(const Real &other) noexcept       { return *this = *this - other; };
        inline Real &operator*=(const Real &other) noexcept       { return *this = *this * other; };
        inline Real &operator/=(const Real &other) noexcept       { return *this = *this / other; };

        //Transformations
        inline Real operator+  ()                  const noexcept { return  value; };
        inline Real operator-  ()                  const noexcept { return -value; };
        inline      operator T ()                  const noexcept { return  value; };
    };

    //Comparison
    template<class T, class L> inline bool operator==(const L &a,       const Real<T> &b) { return a       == b.value; };
    template<class T, class R> inline bool operator==(const Real<T> &a, const R       &b) { return a.value == b;       };
    template<class T>          inline bool operator==(const Real<T> &a, const Real<T> &b) { return a.value == b.value; };
    template<class T, class L> inline bool operator!=(const L &a,       const Real<T> &b) { return a       != b.value; };
    template<class T, class R> inline bool operator!=(const Real<T> &a, const R       &b) { return a.value != b;       };
    template<class T>          inline bool operator!=(const Real<T> &a, const Real<T> &b) { return a.value != b.value; };
    template<class T, class L> inline bool operator> (const L &a,       const Real<T> &b) { return a       >  b.value; };
    template<class T, class R> inline bool operator> (const Real<T> &a, const R       &b) { return a.value >  b;       };
    template<class T>          inline bool operator> (const Real<T> &a, const Real<T> &b) { return a.value >  b.value; };
    template<class T, class L> inline bool operator< (const L &a,       const Real<T> &b) { return a       <  b.value; };
    template<class T, class R> inline bool operator< (const Real<T> &a, const R       &b) { return a.value <  b;       };
    template<class T>          inline bool operator< (const Real<T> &a, const Real<T> &b) { return a.value <  b.value; };
    template<class T, class L> inline bool operator>=(const L &a,       const Real<T> &b) { return a       >= b.value; };
    template<class T, class R> inline bool operator>=(const Real<T> &a, const R       &b) { return a.value >= b;       };
    template<class T>          inline bool operator>=(const Real<T> &a, const Real<T> &b) { return a.value >= b.value; };
    template<class T, class L> inline bool operator<=(const L &a,       const Real<T> &b) { return a       <= b.value; };
    template<class T, class R> inline bool operator<=(const Real<T> &a, const R       &b) { return a.value <= b;       };
    template<class T>          inline bool operator<=(const Real<T> &a, const Real<T> &b) { return a.value <= b.value; };

    //Functions
    template<class T> inline Real<T> cos    (const Real<T> &x) noexcept { return std::cos  (x.value); };
    template<class T> inline Real<T> sin    (const Real<T> &x) noexcept { return std::sin  (x.value); };
    template<class T> inline Real<T> tan    (const Real<T> &x) noexcept { return std::tan  (x.value); };
    template<class T> inline Real<T> acos   (const Real<T> &x) noexcept { return std::acos (x.value); };
    template<class T> inline Real<T> asin   (const Real<T> &x) noexcept { return std::asin (x.value); };
    template<class T> inline Real<T> atan   (const Real<T> &x) noexcept { return std::atan (x.value); };
    template<class T> inline Real<T> atan2  (const Real<T> &y, const Real<T> &x) noexcept { return std::atan2(y.value, x.value); };

    template<class T> inline Real<T> cosh   (const Real<T> &x) noexcept { return std::cosh (x.value); };
    template<class T> inline Real<T> sinh   (const Real<T> &x) noexcept { return std::sinh (x.value); };
    template<class T> inline Real<T> tanh   (const Real<T> &x) noexcept { return std::tanh (x.value); };
    template<class T> inline Real<T> acosh  (const Real<T> &x) noexcept { return std::acosh(x.value); };
    template<class T> inline Real<T> asinh  (const Real<T> &x) noexcept { return std::asinh(x.value); };
    template<class T> inline Real<T> atanh  (const Real<T> &x) noexcept { return std::atanh(x.value); };
    
    template<class T> inline Real<T> exp    (const Real<T> &x) noexcept { return std::exp  (x.value); };
    template<class T> inline Real<T> log    (const Real<T> &x) noexcept { return std::log  (x.value); };
    template<class T> inline Real<T> log10  (const Real<T> &x) noexcept { return std::log10(x.value); };
    template<class T> inline Real<T> exp2   (const Real<T> &x) noexcept { return std::exp2 (x.value); };
    template<class T> inline Real<T> expm1  (const Real<T> &x) noexcept { return std::expm1(x.value); };
    template<class T> inline Real<T> ilogb  (const Real<T> &x) noexcept { return std::ilogb(x.value); };
    template<class T> inline Real<T> log1p  (const Real<T> &x) noexcept { return std::log1p(x.value); };
    template<class T> inline Real<T> log2   (const Real<T> &x) noexcept { return std::log2 (x.value); };
    template<class T> inline Real<T> logb   (const Real<T> &x) noexcept { return std::logb (x.value); };
    template<class T> inline Real<T> scalbn (const Real<T> &x, int n)      noexcept { return std::scalbn (x, n); };
    template<class T> inline Real<T> scalbln(const Real<T> &x, long int n) noexcept { return std::scalbln(x, n); };
    
    template<class T> inline Real<T> pow    (const Real<T> &base, const Real<T> &exponent) noexcept { return std::pow  (base.value, exponent.value); };
    template<class T> inline Real<T> sqrt   (const Real<T> &x)                             noexcept { return std::sqrt (x.value); };
    template<class T> inline Real<T> cbrt   (const Real<T> &x)                             noexcept { return std::cbrt (x.value); };
    template<class T> inline Real<T> hypot  (const Real<T> &x,    const Real<T> &y)        noexcept { return std::hypot(x.value, y.value); };

    template<class T> inline Real<T> erf   (const Real<T> &x) noexcept { return std::erf   (x.value); };
    template<class T> inline Real<T> erfc  (const Real<T> &x) noexcept { return std::erfc  (x.value); };
    template<class T> inline Real<T> tgamma(const Real<T> &x) noexcept { return std::tgamma(x.value); };
    template<class T> inline Real<T> lgamma(const Real<T> &x) noexcept { return std::lgamma(x.value); };

    template<class T> inline Real<T>       ceil     (const Real<T> &x) noexcept { return std::ceil     (x.value); };
    template<class T> inline Real<T>       floor    (const Real<T> &x) noexcept { return std::floor    (x.value); };
    template<class T> inline Real<T>       fmod     (const Real<T> &x) noexcept { return std::fmod     (x.value); };
    template<class T> inline Real<T>       trunc    (const Real<T> &x) noexcept { return std::trunc    (x.value); };
    template<class T> inline Real<T>       round    (const Real<T> &x) noexcept { return std::round    (x.value); };
    template<class T> inline long int      lround   (const Real<T> &x) noexcept { return std::lround   (x.value); };
    template<class T> inline long long int llround  (const Real<T> &x) noexcept { return std::llround  (x.value); };
    template<class T> inline Real<T>       rint     (const Real<T> &x) noexcept { return std::rint     (x.value); };
    template<class T> inline long int      lrint    (const Real<T> &x) noexcept { return std::lrint    (x.value); };
    template<class T> inline long long int llrint   (const Real<T> &x) noexcept { return std::llrint   (x.value); };
    template<class T> inline Real<T>       nearbyint(const Real<T> &x) noexcept { return std::nearbyint(x.value); };
    template<class T> inline Real<T>       remainder(const Real<T> &numer, const Real<T> &denom)            noexcept { return std::remainder(numer.value, denom.value); };
    template<class T> inline Real<T>       remquo   (const Real<T> &numer, const Real<T> &denom, int *quot) noexcept { return std::remquo   (numer.value, denom.value, quot); };

    template<class T> inline Real<T> copysign  (const Real<T> &x, const Real<T> &y) noexcept { return std::copysign  (x.value, y.value); };
    template<class T> inline Real<T> nan       (const char* tagp)                   noexcept { return std::nan(tagp); };
    template<class T> inline Real<T> nextafter (const Real<T> &x, const Real<T> &y) noexcept { return std::nextafter (x.value, y.value); };
    template<class T> inline Real<T> nexttoward(const Real<T> &x, const Real<T> &y) noexcept { return std::nexttoward(x.value, y.value); };
    
    template<class T> inline Real<T> fdim(const Real<T> &x, const Real<T> &y) noexcept { std::fdim(x.value, y.value); };
    template<class T> inline Real<T> fmax(const Real<T> &x, const Real<T> &y) noexcept { std::fmax(x.value, y.value); };
    template<class T> inline Real<T> fmin(const Real<T> &x, const Real<T> &y) noexcept { std::fmin(x.value, y.value); };

    template<class T> inline Real<T> abs (const Real<T> &x) noexcept { return std::abs (x.value); };
    template<class T> inline Real<T> fabs(const Real<T> &x) noexcept { return std::fabs(x.value); };
    template<class T> inline Real<T> fma (const Real<T> &x, const Real<T> &y, const Real<T> &z) { return std::fma(x.value, y.value, z.value); };

    //Defines
    typedef Real<float> Float;
    typedef Real<double> Double;
    typedef Real<long double> LongDouble;
}