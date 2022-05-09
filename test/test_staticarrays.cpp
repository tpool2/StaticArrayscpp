#include "staticarrays/staticarrays.hpp"

#include <gtest/gtest.h>

using namespace Static;

TEST(Vector, IntSetValue)
{
    Vectori<3> v;
    int value = 0;
    size_t index = 0;
    v(index) = value;
    ASSERT_EQ(v(index), value);
}

TEST(Vector, Subtraction)
{
    Vectori<1> v1;
    Vectori<1> v2;
    int a = 10;
    int b = 9;
    v1(0) = a;
    v2(0) = b;
    Vectori<1> v3 = v1-v2;
    ASSERT_EQ(v3(0), a-b);
}

TEST(Vector, Addition)
{
    Vectori<1> v1;
    Vectori<1> v2;
    int a = 10;
    int b = 9;
    v1(0) = a;
    v2(0) = b;
    Vectori<1> v3 = v1+v2;
    ASSERT_EQ(v3(0), a+b);
}

TEST(Matrix, IntSetValue)
{
    Matrixi<2,2> A;
    int a = 0;
    A(0,0) = a;
    ASSERT_EQ(A(0,0), a);
}

TEST(Matrix, Addition)
{
    Matrixi<1,1> A;
    int a = 10;
    A(0,0) = a;
    Matrixi<1,1> B;
    int b = 9;
    B(0,0) = b;
    Matrixi<1,1> C = A+B;
    ASSERT_EQ(C(0,0), a+b);
}

TEST(Matrix, Subtraction)
{
    Matrixi<1,1> A;
    int a = 10;
    A(0,0) = a;
    Matrixi<1,1> B;
    int b = 9;
    B(0,0) = b;
    Matrixi<1,1> C = A-B;
    ASSERT_EQ(C(0,0), a-b);
}

TEST(Matrix, Transpose)
{
    Matrixi<2,2> A;
    A(0,0) = 0;
    A(0,1) = 1;
    A(1,0) = 2;
    A(1,1) = 3;
    Transpose<Matrixi<2,2>> At = transpose(A);
    ASSERT_EQ(At(0,0), A(0,0));
    ASSERT_EQ(At(0,1), A(1,0));
    ASSERT_EQ(At(1,0), A(0,1));
    ASSERT_EQ(At(1,1), A(1,1));
}

TEST(Vector, Transpose)
{
    Vectori<3> v;
    v(0) = 0;
    v(1) = 1;
    v(2) = 2;
    Transpose<Vectori<3>> vt = transpose(v);
}

TEST(MatrixVector, Muliplication)
{
    Matrixi<2,2> A;
    A(0,0) = 0;
    A(0,1) = 1;
    A(1,0) = 1;
    A(1,1) = 0;
    Vectori<2> v;
    v(0) = 1;
    v(1) = 2;
    Vectori<2> y = A*v;
    ASSERT_EQ(y(0), v(1));
    ASSERT_EQ(y(1), v(0));
}

TEST(MatrixMatrix, Multiplication)
{
    Matrixi<2,2> A;
    A(0,0) = 0;
    A(0,1) = 1;
    A(1,0) = 1;
    A(1,1) = 0;
    Matrixi<2,2> B;
    B(0,0) = -1;
    B(0,1) = 0;
    B(1,0) = 0;
    B(1,1) = -1;
    Matrixi<2,2> C = A*B;
    ASSERT_EQ(C(0,0), 0);
    ASSERT_EQ(C(0,1), -1);
    ASSERT_EQ(C(1,0), -1);
    ASSERT_EQ(C(1,1), 0);
}

TEST(VectorNorm, Double)
{
    Vectord<2> v;
    v(0) = 3.0;
    v(1) = 4.0;
    ASSERT_DOUBLE_EQ(norm(v), 5.0);
}

TEST(UpperTriangular, Matrix)
{
    Matrixi<3,3> A;
    A(0,0) = 0;
    A(0,1) = 1;
    A(0,2) = 2;
    A(1,0) = 3;
    A(1,1) = 4;
    A(1,2) = 5;
    A(2,0) = 6;
    A(2,1) = 7;
    A(2,2) = 8;

    UpperTriangular<int,3> U = triu(A);

    ASSERT_EQ(U(0,0), A(0,0));
    ASSERT_EQ(U(0,1), A(0,1));
    ASSERT_EQ(U(0,2), A(0,2));
    ASSERT_EQ(U(1,0), 0);
    ASSERT_EQ(U(1,1), A(1,1));
    ASSERT_EQ(U(1,2), A(1,2));
    ASSERT_EQ(U(2,0), 0);
    ASSERT_EQ(U(2,1), 0);
    ASSERT_EQ(U(2,2), A(2,2));
}

TEST(Cholesky, CholeskyDecomposition)
{
    Matrixd<2,2> A;
    A(0,0) = 4.0;
    A(0,1) = 0.0;
    A(1,0) = 0.0;
    A(1,1) = 4.0;

    Cholesky<2> ch = cholesky(A);
    ASSERT_DOUBLE_EQ(ch.U(0,0), 2.0);
    ASSERT_DOUBLE_EQ(ch.U(0,1), 0.0);
    ASSERT_DOUBLE_EQ(ch.U(1,0), 0.0);
    ASSERT_DOUBLE_EQ(ch.U(1,1), 2.0);
}