#pragma once
#include <iostream>
#include <array>
#include <stdexcept>
#include <utility>
#include "Vector.hpp"





template <typename T, int Rows, int Cols>
class Matrix
{
    public:
        using row_vector = Vector<T, Cols>;
        std::array<row_vector, Rows> components;
        static const int rows = Rows;
        static const int cols = Cols;
    
        // // Constructor to initialize matrix with initializer list
        Matrix(std::initializer_list<std::initializer_list<T>> init)
        {
            auto row_it = init.begin();
            for (int i = 0; i < Rows; ++i, ++row_it)
            {
                components[i] = row_vector();  // Initialize an empty row_vector
                auto col_it = row_it->begin();
                for (int j = 0; j < Cols; ++j, ++col_it)
                {
                    components[i][j] = *col_it;
                }
            }
        }

        Matrix()
        {
            // Initialize components to default values, for example:
            for (int i = 0; i < Rows; ++i)
            {
                for (int j = 0; j < Cols; ++j)
                {
                    components[i][j] = T(); // default-initialize elements
                }
            }
        }

        Vector<T, Cols>& operator[](int index)
        {
            return components[index];
        }

        const std::array<T, Cols>& operator[](int index) const
        {
            return components[index];
        }

        // Addition
        Matrix operator+(const Matrix& rhs) const {
            if (Rows != rhs.rows || Cols != rhs.cols)
                throw std::invalid_argument("Matrix addition requires matrices of the same size.");
            Matrix result = *this;
            for (int i = 0; i < Rows; ++i)
            {
                for (int j = 0; j < Cols; ++j)
                {
                    result.components[i][j] += rhs.components[i][j];
                }
            }
            return result;
        }

        // Subtraction
        Matrix operator-(const Matrix& rhs) const
        {
            if (Rows != rhs.rows || Cols != rhs.cols)
                throw std::invalid_argument("Matrix subtraction requires matrices of the same size.");
            Matrix result = *this;
            for (int i = 0; i < Rows; ++i)
            {
                for (int j = 0; j < Cols; ++j)
                {
                    result.components[i][j] -= rhs.components[i][j];
                }
            }
            return result;
        }

        // Scaling
        Matrix operator*(const T scalar) const
        {
            Matrix result = *this;
            for (int i = 0; i < Rows; ++i)
            {
                for (int j = 0; j < Cols; ++j)
                {
                    result.components[i][j] *= scalar;
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
        Vector<T, this->rows> result = {};  // Initialize result vector
        for (int i = 0; i < this->rows; ++i)
        {
            for (int j = 0; j < this->cols; ++j)
            {
                result[i] += components[i][j] * vec[j];
            }
        }
        return result;
    }

    Matrix<T, Rows, Cols> mul_mat(Matrix<T, Rows, Cols>& mat)
    {
        
        Matrix<T, this->rows, this->cols> result; // initialize result matrix with dimensions n x p
        
        for (int index = 0; index < this->rows; ++index)
        {
            for (int j = 0; j < mat.cols; ++j)
            {
                T sum = 0;
                for (int k = 0; k < this->cols; ++k)
                {
                    sum += this->components[index][k] * mat.components[k][j]; // multiply corresponding elements
                }
                result.components[index][j] = sum;
            }
        }
        
        return result;
    }


        friend std::ostream& operator<<(std::ostream& os, const Matrix<T, Rows, Cols>& mat) {
            for (int i = 0; i < Rows; ++i) {
                os << "[ ";
                for (int j = 0; j < Cols; ++j) {
                    os << mat.components[i][j];
                    if (j != Cols - 1) {
                        os << ", ";
                    }
                }
                os << " ]\n";
            }
            return os;
        }
};


