#pragma once

#include <iostream>
#include <vector>
#include <stdexcept>

template <typename T, int rows, int cols>
class Matrix {
public:
    std::vector<std::vector<T>> components;

    // Constructor
    Matrix(std::initializer_list<std::initializer_list<T>> init)
    {
        if (init.size() != rows || (init.size() > 0 && init.begin()->size() != cols))
        {
            throw std::invalid_argument("Matrix dimensions do not match.");
        }
        for (auto& row : init)
        {
            components.push_back(std::vector<T>(row));
        }
    }

    // Addition
    Matrix operator+(const Matrix& rhs) const {
        if (components.size() != rhs.components.size() || components[0].size() != rhs.components[0].size()) {
            throw std::invalid_argument("Matrix addition requires matrices of the same size.");
        }
        Matrix result = *this;
        for (size_t i = 0; i < components.size(); ++i) {
            for (size_t j = 0; j < components[i].size(); ++j) {
                result.components[i][j] += rhs.components[i][j];
            }
        }
        return result;
    }

    // Subtraction
    Matrix operator-(const Matrix& rhs) const {
        if (components.size() != rhs.components.size() || components[0].size() != rhs.components[0].size()) {
            throw std::invalid_argument("Matrix subtraction requires matrices of the same size.");
        }
        Matrix result = *this;
        for (size_t i = 0; i < components.size(); ++i) {
            for (size_t j = 0; j < components[i].size(); ++j) {
                result.components[i][j] -= rhs.components[i][j];
            }
        }
        return result;
    }

    // Scaling
    Matrix operator*(const T scalar) const {
        Matrix result = *this;
        for (size_t i = 0; i < components.size(); ++i) {
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
