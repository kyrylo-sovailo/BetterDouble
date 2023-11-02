#pragma once

#include <cmath>
#include <limits>

namespace bd
{
    //Predefine
    template<class T> class Real;

    //Basic arithmetics
    template<class T> constexpr inline Real<T> operator+ (const Real<T> &a, const Real<T> &b) { return a.value + b.value; };
    template<class T> constexpr inline Real<T> operator- (const Real<T> &a, const Real<T> &b) { return a.value - b.value; };
    template<class T> constexpr inline Real<T> operator* (const Real<T> &a, const Real<T> &b) { return a.value * b.value; };
    template<class T> constexpr inline Real<T> operator/ (const Real<T> &a, const Real<T> &b) { return a.value / b.value; };

    ///Same as double, but with overloaded operators
    ///@tparam T Base type
    template<class T = double>
    class Real
    {
    public:
        //Variables
        T value;

        //Constructors & assignment
        constexpr inline Real()                    noexcept       {};
        constexpr inline Real(const T &other)      noexcept       : value(other) {};
        constexpr inline Real(const Real &other)   noexcept       : value(other.value) {};
        inline Real &operator= (const Real &other) noexcept       { value = other.value;  return *this; };

        //Increments/decrements
        inline Real &operator++()                  noexcept       { ++value; return *this; };
        inline Real &operator--()                  noexcept       { --value; return *this; };
        inline Real operator++ (int)               noexcept       { T v = value; ++value; return v; };
        inline Real operator-- (int)               noexcept       { T v = value; --value; return v; };

        //Arithmetics
        inline Real &operator+=(const Real &other) noexcept       { value += other.value; return *this; };
        inline Real &operator-=(const Real &other) noexcept       { value -= other.value; return *this; };
        inline Real &operator*=(const Real &other) noexcept       { value *= other.value; return *this; };
        inline Real &operator/=(const Real &other) noexcept       { value /= other.value; return *this; };

        //Transformations
        constexpr inline Real operator+  ()        const noexcept { return  value; };
        constexpr inline Real operator-  ()        const noexcept { return -value; };
    };
    
    //Comparison
    template<class T> constexpr inline bool operator==(const Real<T> &a, const Real<T> &b) { return a.value == b.value; };
    template<class T> constexpr inline bool operator!=(const Real<T> &a, const Real<T> &b) { return a.value != b.value; };
    template<class T> constexpr inline bool operator> (const Real<T> &a, const Real<T> &b) { return a.value >  b.value; };
    template<class T> constexpr inline bool operator< (const Real<T> &a, const Real<T> &b) { return a.value <  b.value; };
    template<class T> constexpr inline bool operator>=(const Real<T> &a, const Real<T> &b) { return a.value >= b.value; };
    template<class T> constexpr inline bool operator<=(const Real<T> &a, const Real<T> &b) { return a.value <= b.value; };
    
    //Trigonometric functions
    template<class T> constexpr inline Real<T> cos    (const Real<T> &x) noexcept { return std::cos  (x.value); };
    template<class T> constexpr inline Real<T> sin    (const Real<T> &x) noexcept { return std::sin  (x.value); };
    template<class T> constexpr inline Real<T> tan    (const Real<T> &x) noexcept { return std::tan  (x.value); };
    template<class T> constexpr inline Real<T> acos   (const Real<T> &x) noexcept { return std::acos (x.value); };
    template<class T> constexpr inline Real<T> asin   (const Real<T> &x) noexcept { return std::asin (x.value); };
    template<class T> constexpr inline Real<T> atan   (const Real<T> &x) noexcept { return std::atan (x.value); };
    template<class T> constexpr inline Real<T> atan2  (const Real<T> &y, const Real<T> &x) noexcept { return std::atan2(y.value, x.value); };

    //Hyperbolic functions
    template<class T> constexpr inline Real<T> cosh   (const Real<T> &x) noexcept { return std::cosh (x.value); };
    template<class T> constexpr inline Real<T> sinh   (const Real<T> &x) noexcept { return std::sinh (x.value); };
    template<class T> constexpr inline Real<T> tanh   (const Real<T> &x) noexcept { return std::tanh (x.value); };
    template<class T> constexpr inline Real<T> acosh  (const Real<T> &x) noexcept { return std::acosh(x.value); };
    template<class T> constexpr inline Real<T> asinh  (const Real<T> &x) noexcept { return std::asinh(x.value); };
    template<class T> constexpr inline Real<T> atanh  (const Real<T> &x) noexcept { return std::atanh(x.value); };
    
    //Exponential and logarithmic functions
    template<class T> constexpr inline Real<T> exp    (const Real<T> &x) noexcept { return std::exp  (x.value); };
    template<class T> constexpr inline Real<T> log    (const Real<T> &x) noexcept { return std::log  (x.value); };
    template<class T> constexpr inline Real<T> log10  (const Real<T> &x) noexcept { return std::log10(x.value); };
    template<class T> constexpr inline Real<T> exp2   (const Real<T> &x) noexcept { return std::exp2 (x.value); };
    template<class T> constexpr inline Real<T> expm1  (const Real<T> &x) noexcept { return std::expm1(x.value); };
    template<class T> constexpr inline Real<T> ilogb  (const Real<T> &x) noexcept { return std::ilogb(x.value); };
    template<class T> constexpr inline Real<T> log1p  (const Real<T> &x) noexcept { return std::log1p(x.value); };
    template<class T> constexpr inline Real<T> log2   (const Real<T> &x) noexcept { return std::log2 (x.value); };
    template<class T> constexpr inline Real<T> logb   (const Real<T> &x) noexcept { return std::logb (x.value); };
    template<class T> constexpr inline Real<T> scalbn (const Real<T> &x, int n)      noexcept { return std::scalbn (x, n); };
    template<class T> constexpr inline Real<T> scalbln(const Real<T> &x, long int n) noexcept { return std::scalbln(x, n); };
    
    //Power functions
    template<class T> constexpr inline Real<T> pow    (const Real<T> &base, const Real<T> &exponent) noexcept { return std::pow  (base.value, exponent.value); };
    template<class T> constexpr inline Real<T> sqrt   (const Real<T> &x)                             noexcept { return std::sqrt (x.value); };
    template<class T> constexpr inline Real<T> cbrt   (const Real<T> &x)                             noexcept { return std::cbrt (x.value); };
    template<class T> constexpr inline Real<T> hypot  (const Real<T> &x,    const Real<T> &y)        noexcept { return std::hypot(x.value, y.value); };

    //Error and gamma functions
    template<class T> constexpr inline Real<T> erf   (const Real<T> &x) noexcept { return std::erf   (x.value); };
    template<class T> constexpr inline Real<T> erfc  (const Real<T> &x) noexcept { return std::erfc  (x.value); };
    template<class T> constexpr inline Real<T> tgamma(const Real<T> &x) noexcept { return std::tgamma(x.value); };
    template<class T> constexpr inline Real<T> lgamma(const Real<T> &x) noexcept { return std::lgamma(x.value); };

    //Rounding and remainder functions
    template<class T> constexpr inline Real<T>       ceil     (const Real<T> &x) noexcept { return std::ceil     (x.value); };
    template<class T> constexpr inline Real<T>       floor    (const Real<T> &x) noexcept { return std::floor    (x.value); };
    template<class T> constexpr inline Real<T>       fmod     (const Real<T> &x) noexcept { return std::fmod     (x.value); };
    template<class T> constexpr inline Real<T>       trunc    (const Real<T> &x) noexcept { return std::trunc    (x.value); };
    template<class T> constexpr inline Real<T>       round    (const Real<T> &x) noexcept { return std::round    (x.value); };
    template<class T> constexpr inline long int      lround   (const Real<T> &x) noexcept { return std::lround   (x.value); };
    template<class T> constexpr inline long long int llround  (const Real<T> &x) noexcept { return std::llround  (x.value); };
    template<class T> constexpr inline Real<T>       rint     (const Real<T> &x) noexcept { return std::rint     (x.value); };
    template<class T> constexpr inline long int      lrint    (const Real<T> &x) noexcept { return std::lrint    (x.value); };
    template<class T> constexpr inline long long int llrint   (const Real<T> &x) noexcept { return std::llrint   (x.value); };
    template<class T> constexpr inline Real<T>       nearbyint(const Real<T> &x) noexcept { return std::nearbyint(x.value); };
    template<class T> constexpr inline Real<T>       remainder(const Real<T> &numer, const Real<T> &denom)            noexcept { return std::remainder(numer.value, denom.value); };
    template<class T> constexpr inline Real<T>       remquo   (const Real<T> &numer, const Real<T> &denom, int *quot) noexcept { return std::remquo   (numer.value, denom.value, quot); };

    //Floating-point manipulation functions
    template<class T> constexpr inline Real<T> copysign  (const Real<T> &x, const Real<T> &y) noexcept { return std::copysign  (x.value, y.value); };
    template<class T> constexpr inline Real<T> nan       (const char* tagp)                   noexcept { return std::nan(tagp); };
    template<class T> constexpr inline Real<T> nextafter (const Real<T> &x, const Real<T> &y) noexcept { return std::nextafter (x.value, y.value); };
    template<class T> constexpr inline Real<T> nexttoward(const Real<T> &x, const Real<T> &y) noexcept { return std::nexttoward(x.value, y.value); };
    
    //Minimum, maximum, difference functions
    template<class T> constexpr inline Real<T> fdim(const Real<T> &x, const Real<T> &y) noexcept { std::fdim(x.value, y.value); };
    template<class T> constexpr inline Real<T> fmax(const Real<T> &x, const Real<T> &y) noexcept { std::fmax(x.value, y.value); };
    template<class T> constexpr inline Real<T> fmin(const Real<T> &x, const Real<T> &y) noexcept { std::fmin(x.value, y.value); };
    
    //Other functions
    template<class T> constexpr inline Real<T> fabs(const Real<T> &x) noexcept { return std::fabs(x.value); };
    template<class T> constexpr inline Real<T> abs (const Real<T> &x) noexcept { return std::abs (x.value); };
    template<class T> constexpr inline Real<T> fma (const Real<T> &x, const Real<T> &y, const Real<T> &z) { return std::fma(x.value, y.value, z.value); };

    //Classification macro / functions
    template<class T> constexpr inline int  fpclassify(const Real<T> &x) { return std::fpclassify(x.value); }
    template<class T> constexpr inline bool isfinite  (const Real<T> &x) { return std::isfinite  (x.value); }
    template<class T> constexpr inline bool isinf     (const Real<T> &x) { return std::isinf     (x.value); }
    template<class T> constexpr inline bool isnan     (const Real<T> &x) { return std::isnan     (x.value); }
    template<class T> constexpr inline bool isnormal  (const Real<T> &x) { return std::isnormal  (x.value); }
    template<class T> constexpr inline bool signbit   (const Real<T> &x) { return std::signbit   (x.value); }


    //Comparison macro / functions
    template<class T> constexpr inline bool isgreater     (const Real<T> &x, const Real<T> &y) { return std::isgreater     (x.value, y.value); }
    template<class T> constexpr inline bool isgreaterequal(const Real<T> &x, const Real<T> &y) { return std::isgreaterequal(x.value, y.value); }
    template<class T> constexpr inline bool isless        (const Real<T> &x, const Real<T> &y) { return std::isless        (x.value, y.value); }
    template<class T> constexpr inline bool islessequal   (const Real<T> &x, const Real<T> &y) { return std::islessequal   (x.value, y.value); }
    template<class T> constexpr inline bool islessgreater (const Real<T> &x, const Real<T> &y) { return std::islessgreater (x.value, y.value); }
    template<class T> constexpr inline bool isunordered   (const Real<T> &x, const Real<T> &y) { return std::isunordered   (x.value, y.value); }

    //Defines
    typedef Real<float> Float;
    typedef Real<double> Double;
    typedef Real<long double> LongDouble;
}

template<class T> struct std::numeric_limits<bd::Real<T>>
{
    static constexpr bool is_specialized = true;
    static constexpr int digits = std::numeric_limits<T>::digits;
    static constexpr int digits10 = std::numeric_limits<T>::digits10;
    static constexpr int max_digits10 = std::numeric_limits<T>::max_digits10;
    static constexpr bool is_signed = std::numeric_limits<T>::is_signed;
    static constexpr bool is_integer = std::numeric_limits<T>::is_integer;
    static constexpr bool is_exact = std::numeric_limits<T>::is_exact;
    static constexpr int radix = std::numeric_limits<T>::radix;
    static constexpr int min_exponent = std::numeric_limits<T>::min_exponent;
    static constexpr int min_exponent10 = std::numeric_limits<T>::min_exponent10;
    static constexpr int max_exponent = std::numeric_limits<T>::max_exponent;
    static constexpr int max_exponent10 = std::numeric_limits<T>::max_exponent10;
    static constexpr bool has_infinity = std::numeric_limits<T>::has_infinity;
    static constexpr bool has_quiet_NaN = std::numeric_limits<T>::has_quiet_NaN;
    static constexpr bool has_signaling_NaN = std::numeric_limits<T>::has_signaling_NaN;
    static constexpr float_denorm_style has_denorm = std::numeric_limits<T>::has_denorm;
    static constexpr bool has_denorm_loss = std::numeric_limits<T>::has_denorm_loss;
    static constexpr bool is_iec559 = std::numeric_limits<T>::is_iec559;
    static constexpr bool is_bounded = std::numeric_limits<T>::is_bounded;
    static constexpr bool is_modulo = std::numeric_limits<T>::is_modulo;
    static constexpr bool traps = std::numeric_limits<T>::traps;
    static constexpr bool tinyness_before = std::numeric_limits<T>::tinyness_before;
    static constexpr float_round_style round_style = std::numeric_limits<T>::round_style;

    static constexpr bd::Real<T> min() noexcept { return std::numeric_limits<T>::min(); }
    static constexpr bd::Real<T> max() noexcept { return std::numeric_limits<T>::max(); }
    static constexpr bd::Real<T> lowest() noexcept { return std::numeric_limits<T>::lowest(); }
    static constexpr bd::Real<T> epsilon() noexcept { return std::numeric_limits<T>::epsilon(); }
    static constexpr bd::Real<T> round_error() noexcept { return std::numeric_limits<T>::round_error(); }
    static constexpr bd::Real<T> infinity() noexcept { return std::numeric_limits<T>::infinity(); }
    static constexpr bd::Real<T> quiet_NaN() noexcept { return std::numeric_limits<T>::quiet_NaN(); }
    static constexpr bd::Real<T> signaling_NaN() noexcept { return std::numeric_limits<T>::signaling_NaN(); }
    static constexpr bd::Real<T> denorm_min() noexcept { return std::numeric_limits<T>::denorm_min(); }  
};