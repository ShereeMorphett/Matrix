#pragma once

#include <iostream>
#include <array>
#include <initializer_list>
#include <stdexcept>
#include <type_traits>
#include "Vector.hpp"

template <typename T, int Rows, int Cols>
class MatrixStorage
{
    public:
        std::array<Vector<T, Cols>, Rows> components;

        MatrixStorage() = default;
        MatrixStorage(const MatrixStorage&) = default;
        MatrixStorage& operator=(const MatrixStorage&) = default;
};

template <typename T, int Rows, int Cols>
struct MatrixInit;

template <typename T>
struct MatrixInit<T, 2, 2> : public MatrixStorage<T, 2, 2>
{
    MatrixInit() = default;
    MatrixInit(const MatrixInit&) = default;
    MatrixInit& operator=(const MatrixInit&) = default;

    using base = MatrixStorage<T, 2, 2>;

    MatrixInit(T a, T b, T c, T d)
        : base{ {{ {a, b}, {c, d} }} }
    {}

    MatrixInit(std::initializer_list<std::initializer_list<T>> init)
    {
        auto row_it = init.begin();
        for (int i = 0; i < 2; ++i, ++row_it)
        {
            auto col_it = row_it->begin();
            for (int j = 0; j < 2; ++j, ++col_it)
            {
                this->components[i][j] = *col_it;
            }
        }
    }
};

template <typename T>
struct MatrixInit<T, 3, 3> : public MatrixStorage<T, 3, 3>
{
    MatrixInit() = default;
    MatrixInit(const MatrixInit&) = default;
    MatrixInit& operator=(const MatrixInit&) = default;

    using base = MatrixStorage<T, 3, 3>;

    MatrixInit(T a, T b, T c, T d, T e, T f, T g, T h, T i)
        : base{ {{ {a, b, c}, {d, e, f}, {g, h, i} }} }
    {}

    MatrixInit(std::initializer_list<std::initializer_list<T>> init)
    {
        auto row_it = init.begin();
        for (int i = 0; i < 3; ++i, ++row_it)
        {
            auto col_it = row_it->begin();
            for (int j = 0; j < 3; ++j, ++col_it)
            {
                this->components[i][j] = *col_it;
            }
        }
    }
};

template <typename T, int Rows, int Cols>
class Matrix : public MatrixInit<T, Rows, Cols>
{
    public:
        Matrix() = default;
        Matrix(const Matrix&) = default;

        using base = MatrixInit<T, Rows, Cols>;
        using base::base;

        Matrix(std::initializer_list<std::initializer_list<T>> init)
            : base(init) {}

        template <int OtherRows, int OtherCols>
        Matrix& operator=(const Matrix<T, OtherRows, OtherCols>&) = delete; // Disable assignment for different dimensions

        Matrix& operator=(const Matrix& other)
        {
            if (this != &other) {
                this->components = other.components;
            }
            return *this;
        }

        Vector<T, Cols>& operator[](int index)
        {
            return base::components[index];
        }

        const Vector<T, Cols>& operator[](int index) const
        {
            return base::components[index];
        }

        Matrix operator+(const Matrix& rhs) const
        {
            Matrix result;
            for (int i = 0; i < Rows; ++i)
            {
                for (int j = 0; j < Cols; ++j)
                {
                    result[i][j] = (*this)[i][j] + rhs[i][j];
                }
            }
            return result;
        }

        Matrix operator-(const Matrix& rhs) const
        {
            Matrix result;
            for (int i = 0; i < Rows; ++i)
            {
                for (int j = 0; j < Cols; ++j)
                {
                    result[i][j] = (*this)[i][j] - rhs[i][j];
                }
            }
            return result;
        }

        Matrix operator*(T scalar) const
        {
            Matrix result;
            for (int i = 0; i < Rows; ++i)
            {
                for (int j = 0; j < Cols; ++j)
                {
                    result[i][j] = (*this)[i][j] * scalar;
                }
            }
            return result;
        }

        std::pair<size_t, size_t> getMatrixSize() const
        {
            return {Rows, Cols};
        }

        bool isSquareMatrix() const
        {
            return Rows == Cols;
        }

        // Matrix-vector multiplication
        Vector<T, Rows> mul_vec(const Vector<T, Cols>& vec) const
        {
            Vector<T, Rows> result = {};  // Initialize result vector
            for (int i = 0; i < Rows; ++i)
            {
                for (int j = 0; j < Cols; ++j)
                {
                    result[i] += base::components[i][j] * vec[j];
                }
            }
            return result;
        }

        // Matrix-Matrix multiplication
        Matrix<T, Rows, Cols> mul_mat(Matrix<T, Rows, Cols>& mat)
        {
            Matrix<T, Rows, Cols> result; // initialize result matrix with dimensions n x p
            
            for (int index = 0; index < Rows; ++index)
            {
                for (int j = 0; j < Cols; ++j)
                {
                    T sum = 0;
                    for (int k = 0; k < Cols; ++k)
                    {
                        sum += this->components[index][k] * mat.components[k][j];
                    }
                    result.components[index][j] = sum;
                }
            }
            
            return result;
        }

        T trace()
        {
            T result = 0;
            if (Rows != Cols)
                throw std::invalid_argument("Matrix trace requires matrices to be square.");
            
            for(auto i = 0; i < Rows; ++i)
            {
                result += this->components[i][i];
            }

            return result;
        }


    Matrix<T, Cols, Rows> transpose() const
    {
        Matrix<T, Cols, Rows> new_mat;

        for (auto i = 0; i < Rows; ++i)
        {
            for (auto j = 0; j < Cols; ++j)
            {
                new_mat[j][i] = (*this)[i][j];
            }
        }
        
        return new_mat;
    }


        friend std::ostream& operator<<(std::ostream& os, const Matrix<T, Rows, Cols>& mat)
        {
            for (int i = 0; i < Rows; ++i) {
                os << "[ ";
                for (int j = 0; j < Cols; ++j) {
                    os << mat[i][j];
                    if (j != Cols - 1) {
                        os << ", ";
                    }
                }
                os << " ]\n";
            }
            return os;
        }
};