#pragma once

#include "real.hpp"
#include <Eigen/Core>

template<class T> struct Eigen::NumTraits<bd::Real<T>>
{
    typedef bd::Real<T> Real;
    typedef bd::Real<T> NonInteger;
    typedef bd::Real<T> Literal;
    typedef bd::Real<T> Nested;

    enum
    {
        IsComplex = 0,
        IsInteger = 0,
        IsSigned = 1,
        ReadCost = 1,
        AddCost = 3,
        MulCost = 3,
        RequireInitialization = 0
    };

    static constexpr inline bd::Real<T> epsilon        () noexcept { return (bd::Real<T>)std::numeric_limits<T>::epsilon(); }
    static constexpr inline bd::Real<T> dummy_precision() noexcept { return (bd::Real<T>)std::numeric_limits<T>::epsilon(); }
    static constexpr inline bd::Real<T> highest        () noexcept { return (bd::Real<T>)std::numeric_limits<T>::infinity(); }
    static constexpr inline bd::Real<T> lowest         () noexcept { return (bd::Real<T>)-std::numeric_limits<T>::infinity(); }
    static constexpr inline int         digits         () noexcept { return std::numeric_limits<T>::digits; }
    static constexpr inline int         digits10       () noexcept { return std::numeric_limits<T>::digits10; }
    static constexpr inline int         min_exponent   () noexcept { return std::numeric_limits<T>::min_exponent; }
    static constexpr inline int         max_exponent   () noexcept { return std::numeric_limits<T>::max_exponent; }
    static constexpr inline bd::Real<T> infinity       () noexcept { return (bd::Real<T>)std::numeric_limits<T>::infinity(); }
    static constexpr inline bd::Real<T> quiet_NaN      () noexcept { return (bd::Real<T>)std::numeric_limits<T>::quiet_NaN(); }
};