#pragma once

#include "differentiable.hpp"
#include <Eigen/Core>

template<class T, unsigned int N> struct Eigen::NumTraits<bd::Differentiable<T, N>>
{
    typedef bd::Differentiable<T, N> Real;
    typedef bd::Differentiable<T, N> NonInteger;
    typedef bd::Differentiable<T, N> Literal;
    typedef bd::Differentiable<T, N> Nested;

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

    static constexpr inline bd::Differentiable<T, N> epsilon        () noexcept { return (bd::Differentiable<T, N>)std::numeric_limits<T>::epsilon(); }
    static constexpr inline bd::Differentiable<T, N> dummy_precision() noexcept { return (bd::Differentiable<T, N>)std::numeric_limits<T>::epsilon(); }
    static constexpr inline bd::Differentiable<T, N> highest        () noexcept { return (bd::Differentiable<T, N>)std::numeric_limits<T>::infinity(); }
    static constexpr inline bd::Differentiable<T, N> lowest         () noexcept { return (bd::Differentiable<T, N>)-std::numeric_limits<T>::infinity(); }
    static constexpr inline int                      digits         () noexcept { return std::numeric_limits<T>::digits; }
    static constexpr inline int                      digits10       () noexcept { return std::numeric_limits<T>::digits10; }
    static constexpr inline int                      min_exponent   () noexcept { return std::numeric_limits<T>::min_exponent; }
    static constexpr inline int                      max_exponent   () noexcept { return std::numeric_limits<T>::max_exponent; }
    static constexpr inline bd::Differentiable<T, N> infinity       () noexcept { return (bd::Differentiable<T, N>)std::numeric_limits<T>::infinity(); }
    static constexpr inline bd::Differentiable<T, N> quiet_NaN      () noexcept { return (bd::Differentiable<T, N>)std::numeric_limits<T>::quiet_NaN(); }
};