#pragma once

#include "vector.hpp"
#include "matrix.hpp"

namespace Static
{

template <size_t N>
double norm(const Vectord<N>& vector)
{
    double result = 0.0;
    for(size_t index = 0; index < N; ++index)
    {
        result += vector(index)*vector(index);
    }
    return std::sqrt(result); 
}

template <size_t M, size_t N>
Vectori<M> operator*(const Matrixi<M,N>& A, const Vectori<N>& x)
{
    Vectori<M> result;
    for(size_t row = 0; row < M; ++row)
    {
        result(row) = 0;
        for(size_t col = 0; col < N; ++col)
        {
            result(row) += A(row,col)*x(col);
        }
    }
    return result;
}

template <size_t M, size_t N, size_t S>
Matrixi<M,S> operator*(const Matrixi<M,N>& A, const Matrixi<N,S>& B)
{
    Matrixi<M,S> result;
    for(size_t row = 0; row < M; ++row)
    {
        for(size_t col = 0; col < S; ++col)
        {
            result(row,col) = 0;
            for(size_t k = 0; k < N; ++k)
            {
                result(row,col) += A(row,k)*B(k,col);
            }
        }
    }
    return result;
}

}