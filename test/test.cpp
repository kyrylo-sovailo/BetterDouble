#include "../include/betterdouble/betterdouble-eigen.hpp"
#include <gtest/gtest.h>
#include <Eigen/Eigenvalues>
#include <limits>

template class bd::Real<double>;

TEST(Arithmetics, Operators)
{
    bd::DDouble a = 1;
    a++;
    a--;
    ++a;
    --a;
    a += 1;
    a -= 1;
    a *= 1;
    a /= 1;
    EXPECT_EQ(a.value, 1);
}

TEST(Arithmetics, Addition)
{
    bd::DDouble a = 1; a.derivative[0] = 2;
    bd::DDouble b = 3; b.derivative[0] = 4;
    bd::DDouble c = a + b;
    EXPECT_EQ((double)c, 4);
    EXPECT_EQ(c.derivative[0], 6);
}

TEST(Arithmetics, Subtraction)
{
    bd::DDouble a = 1; a.derivative[0] = 2;
    bd::DDouble b = 3; b.derivative[0] = 4;
    bd::DDouble c = a - b;
    EXPECT_EQ((double)c, -2);
    EXPECT_EQ(c.derivative[0], -2);
}

TEST(Arithmetics, Multiplication)
{
    bd::DDouble a = 1; a.derivative[0] = 2;
    bd::DDouble b = 3; b.derivative[0] = 4;
    bd::DDouble c = a * b;
    EXPECT_EQ((double)c, 3);
    EXPECT_EQ(c.derivative[0], 10);
}

TEST(Arithmetics, Division)
{
    bd::DDouble a = 1; a.derivative[0] = 2;
    bd::DDouble b = 3; b.derivative[0] = 4;
    bd::DDouble c = a / b;
    EXPECT_NEAR((double)c, 1.0/3.0, 0.001);
    EXPECT_NEAR(c.derivative[0], 2.0/9.0, 0.001);
}

TEST(Trigonometry, Sine)
{
    bd::DDouble a = 1; a.derivative[0] = 1;
    bd::DDouble c = bd::sin(a);
    EXPECT_NEAR((double)c, std::sin(1), 0.001);
    EXPECT_NEAR(c.derivative[0], std::cos(1), 0.001);
}

TEST(Trigonometry, Cosine)
{
    bd::DDouble a = 1; a.derivative[0] = 1;
    bd::DDouble c = bd::cos(a);
    EXPECT_NEAR((double)c, std::cos(1), 0.001);
    EXPECT_NEAR(c.derivative[0], -std::sin(1), 0.001);
}

TEST(Matrices, LinearSystem)
{
    Eigen::Matrix<bd::Double, Eigen::Dynamic, Eigen::Dynamic> matrix(2, 2);
    matrix(0, 0) = 2; matrix(0, 1) = -1;
    matrix(1, 0) = 8; matrix(1, 1) =  3;
    Eigen::Matrix<bd::Double, Eigen::Dynamic, 1> vector(2);
    vector(0) = 3;
    vector(1) = 5;
    
    Eigen::Matrix<bd::Double, Eigen::Dynamic, 1> result = matrix.colPivHouseholderQr().solve(vector);
    
    EXPECT_NEAR((double)result(0),  1, 0.001);
    EXPECT_NEAR((double)result(1), -1, 0.001);
}

TEST(Matrices, Eigenvectors)
{
    Eigen::Matrix<bd::Double, Eigen::Dynamic, Eigen::Dynamic> matrix(2, 2);
    matrix(0, 0) =  0; matrix(0, 1) =  1;
    matrix(1, 0) = -2; matrix(1, 1) = -3;
    
    Eigen::EigenSolver<Eigen::Matrix<bd::Double, Eigen::Dynamic, Eigen::Dynamic>> solver;
    solver.compute(matrix);
    Eigen::Matrix<bd::Double, Eigen::Dynamic, 1> result = solver.eigenvectors().col(0).real();
    
    EXPECT_NEAR((double)result(0),  1.0 / sqrt(2.0), 0.001);
    EXPECT_NEAR((double)result(1), -1.0 / sqrt(2.0), 0.001);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}