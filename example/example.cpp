#include "../include/betterdouble/real.hpp"
#include <gtest/gtest.h>
#include <Eigen/Eigenvalues>
#include <limits>

/*
TEST(Arithmetics, Addition)
{
    bd::Double a = 1; a.derivative[0] = 2;
    bd::Double b = 3; b.derivative[0] = 4;
    bd::Double c = a + b;
    EXPECT_EQ(c, 4);
    EXPECT_EQ(c.derivative[0], 6);
}

TEST(Arithmetics, Subtraction)
{
    bd::Double a = 1; a.derivative[0] = 2;
    bd::Double b = 3; b.derivative[0] = 4;
    bd::Double c = a - b;
    EXPECT_EQ(c, -2);
    EXPECT_EQ(c.derivative[0], -2);
}

TEST(Arithmetics, Multiplication)
{
    bd::Double a = 1; a.derivative[0] = 2;
    bd::Double b = 3; b.derivative[0] = 4;
    bd::Double c = a * b;
    EXPECT_EQ(c, 3);
    EXPECT_EQ(c.derivative[0], 10);
}

TEST(Arithmetics, Division)
{
    bd::Double a = 1; a.derivative[0] = 2;
    bd::Double b = 3; b.derivative[0] = 4;
    bd::Double c = a / b;
    EXPECT_NEAR(c, 1.0/3.0, 0.001);
    EXPECT_NEAR(c.derivative[0], 2.0/9.0, 0.001);
}

TEST(Trigonometry, Sine)
{
    bd::Double a = 1; a.derivative[0] = 1;
    bd::Double c = bd::sin(a);
    EXPECT_NEAR(c, std::sin(1), 0.001);
    EXPECT_NEAR(c.derivative[0], std::cos(1), 0.001);
}

TEST(Trigonometry, Cosine)
{
    bd::Double a = 1; a.derivative[0] = 1;
    bd::Double c = bd::cos(a);
    EXPECT_NEAR(c, std::cos(1), 0.001);
    EXPECT_NEAR(c.derivative[0], -std::sin(1), 0.001);
}
*/

/*
namespace Eigen
{
    template<> struct NumTraits<bd::Real<double>> : NumTraits<double>
    {
        enum
        {
            IsComplex = 0,
            IsInteger = 0,
            IsSigned = 1,
            ReadCost = 1,
            AddCost = 3,
            MulCost = 3,
            RequireInitialization = 0,
        };
        typedef bd::Real<double> Real;
        typedef bd::Real<double> NonInteger;
        typedef bd::Real<double> Literal;
        typedef bd::Real<double> Nested;
    };
}
*/

template<> struct Eigen::NumTraits<bd::Real<double>>
{
    typedef bd::Real<double> Real;
    typedef bd::Real<double> NonInteger;
    typedef bd::Real<double> Literal;
    typedef bd::Real<double> Nested;

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

    static constexpr inline bd::Real<double> epsilon        () noexcept { return std::numeric_limits<double>::epsilon(); }
    static constexpr inline bd::Real<double> dummy_precision() noexcept { return std::numeric_limits<double>::epsilon(); }
    static constexpr inline bd::Real<double> highest        () noexcept { return std::numeric_limits<double>::infinity(); }
    static constexpr inline bd::Real<double> lowest         () noexcept { return -std::numeric_limits<double>::infinity(); }
    static constexpr inline int              digits         () noexcept { return std::numeric_limits<double>::digits; }
    static constexpr inline int              digits10       () noexcept { return std::numeric_limits<double>::digits10; }
    static constexpr inline int              min_exponent   () noexcept { return std::numeric_limits<double>::min_exponent; }
    static constexpr inline int              max_exponent   () noexcept { return std::numeric_limits<double>::max_exponent; }
    static constexpr inline bd::Real<double> infinity       () noexcept { return std::numeric_limits<double>::infinity(); }
    static constexpr inline bd::Real<double> quiet_NaN      () noexcept { return std::numeric_limits<double>::quiet_NaN(); }
};

TEST(Eigen, Eigen)
{
    Eigen::Matrix<bd::Double, Eigen::Dynamic, Eigen::Dynamic> matrix(2, 2);
    matrix(0, 0) =  0; matrix(0, 1) =  1;
    matrix(1, 0) = -2; matrix(1, 1) = -3;
    Eigen::EigenSolver<Eigen::Matrix<bd::Double, Eigen::Dynamic, Eigen::Dynamic>> solver;
    solver.compute(matrix);
    Eigen::Matrix<bd::Double, Eigen::Dynamic, 1> vector = solver.eigenvectors().col(0).real();
    EXPECT_NEAR(vector(0).value,  1.0 / sqrt(2.0), 0.001);
    EXPECT_NEAR(vector(1).value, -1.0 / sqrt(2.0), 0.001);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}