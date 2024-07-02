#pragma once

#include <iostream>
#include <vector>
#include <stdexcept>
#include <pair>



// A function to return the size/shape of a vector/matrix.
// • A function to tell if a matrix is square.
// • A function to reshape a vector into a matrix, and vice-versa.

template <typename T, int rows, int cols>
class Matrix
{
    public:
        std::vector<std::vector<T>> components;

        // Constructor
        Matrix(std::initializer_list<std::initializer_list<T>> init)
        {
            if (init.size() != rows || (init.size() > 0 && init.begin()->size() != cols))
                throw std::invalid_argument("Matrix dimensions do not match.");
            for (auto& row : init)
            {
                components.push_back(std::vector<T>(row));
            }
        }

        template <typename T>
        std::pair<size_t, size_t> getMatrixSize(const std::vector<std::vector<T>>& matrix)
        {
            size_t rows = matrix.size();
            size_t cols = rows > 0 ? matrix[0].size() : 0;
            return {rows, cols};
        }

        template <typename T>
        bool isSquareMatrix(const std::vector<std::vector<T>>& matrix)
        {
            size_t rows = matrix.size();
            if (rows == 0)
                return true;
            size_t cols = matrix[0].size();
            return rows == cols;
        }


        // Addition
        Matrix operator+(const Matrix& rhs) const
        {
            if (components.size() != rhs.components.size() || components[0].size() != rhs.components[0].size())
                throw std::invalid_argument("Matrix addition requires matrices of the same size.");
            Matrix result = *this;
            for (size_t i = 0; i < components.size(); ++i) {
                for (size_t j = 0; j < components[i].size(); ++j) {
                    result.components[i][j] += rhs.components[i][j];
                }
            }
            return result;
        }

        // Subtraction
        Matrix operator-(const Matrix& rhs) const
        {
            if (components.size() != rhs.components.size() || components[0].size() != rhs.components[0].size())
                throw std::invalid_argument("Matrix subtraction requires matrices of the same size.");
            Matrix result = *this;
            for (size_t i = 0; i < components.size(); ++i) {
                for (size_t j = 0; j < components[i].size(); ++j) {
                    result.components[i][j] -= rhs.components[i][j];
                }
            }
            return result;
        }

        // Scaling
        Matrix operator*(const T scalar) const
        {
            Matrix result = *this;
            for (size_t i = 0; i < components.size(); ++i)
            {
                for (size_t j = 0; j < components[i].size(); ++j) {
                    result.components[i][j] *= scalar;
                }
            }
            return result;
        }


    // Output
    friend std::ostream& operator<<(std::ostream& os, const Matrix<T, rows, cols>& mat) {
        for (size_t i = 0; i < mat.components.size(); ++i) {
            os << "[ ";
            for (size_t j = 0; j < mat.components[i].size(); ++j) {
                os << mat.components[i][j];
                if (j != mat.components[i].size() - 1) {
                    os << ", ";
                }
            }
            os << " ]\n";
        }
        return os;
    }
};
