#pragma once

#include <iostream>
#include <iomanip>
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
struct MatrixInit : public MatrixStorage<T, Rows, Cols>
{
    MatrixInit() = default;
    MatrixInit(const MatrixInit&) = default;
    MatrixInit& operator=(const MatrixInit&) = default;

    using base = MatrixStorage<T, Rows, Cols>;

    MatrixInit(std::initializer_list<std::initializer_list<T>> init)
    {
        auto row_it = init.begin();
        for (int i = 0; i < Rows; ++i, ++row_it)
        {
            auto col_it = row_it->begin();
            for (int j = 0; j < Cols; ++j, ++col_it)
            {
                this->components[i][j] = *col_it;
            }
        }
    }
};


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



    Matrix<T, Rows, Cols> inverse() const
    {
        if (Rows != Cols)
            throw std::invalid_argument("Inverse can only be calculated for square matrices.");

        Matrix<T, Rows, Cols> result = *this;
        Matrix<T, Rows, Cols> identity;

        // Initialize the identity matrix
        for (int i = 0; i < Rows; ++i)
        {
            identity[i][i] = 1;
        }

        // Perform Gaussian elimination
        for (int i = 0; i < Rows; ++i)
        {
            // Find the pivot element
            int pivot = i;
            for (int j = i + 1; j < Rows; ++j)
            {
                if (std::abs(result[j][i]) > std::abs(result[pivot][i]))
                    pivot = j;
            }

            // Swap rows if necessary
            if (pivot != i)
            {
                std::swap(result.components[i], result.components[pivot]);
                std::swap(identity.components[i], identity.components[pivot]);
            }

            // If the pivot element is zero, the matrix is singular and not invertible
            if (result[i][i] == 0)
                throw std::runtime_error("Matrix is singular and cannot be inverted.");

            // Normalize the pivot row
            T pivot_value = result[i][i];
            for (int j = 0; j < Cols; ++j)
            {
                result[i][j] /= pivot_value;
                identity[i][j] /= pivot_value;
            }

            // Eliminate the current column in all other rows
            for (int j = 0; j < Rows; ++j)
            {
                if (j != i)
                {
                    T factor = result[j][i];
                    for (int k = 0; k < Cols; ++k)
                    {
                        result[j][k] -= factor * result[i][k];
                        identity[j][k] -= factor * identity[i][k];
                    }
                }
            }
        }

        return identity;
    }


    T determinant()
    {
        if (!isSquareMatrix())
            throw std::invalid_argument("Determinant can only be calculated for square matrices.");

        Matrix<T, Rows, Cols> temp = *this;
        T det = 1.0;

        for (int i = 0; i < Rows; ++i)
        {
            int pivot = i;
            for (int j = i + 1; j < Rows; ++j)
            {
                if (std::abs(temp[j][i]) > std::abs(temp[pivot][i]))
                    pivot = j;
            }
            // If a pivot row different from the current row is found, swap rows
            //  and multiply determinant by -1
            if (pivot != i)
            {
                std::swap(temp[i], temp[pivot]);
                det *= -1; // Swapping rows changes the sign of the determinant
            }

            // If the pivot element is zero, the determinant is zero
            if (temp[i][i] == 0)
                return 0;

            det *= temp[i][i];
            
            // Perform row operations to zero out elements below the pivot
            for (int j = i + 1; j < Rows; ++j)
            {
                T factor = temp[j][i] / temp[i][i];
                for (int k = i + 1; k < Rows; ++k)
                {
                    // Subtract a multiple of the pivot row from the current row to 
                    // create zeros below the pivot
                    temp[j][k] -= factor * temp[i][k];
                }
            }
        }
        return det;
    }

    Matrix<T, Rows, Cols> row_echelon() const
    {
        Matrix<T, Rows, Cols> result = *this;
        size_t lead = 0;

        for (size_t r = 0; r < Rows; ++r)
        {
            if (lead >= Cols)
                return result;

            // Find the row with the largest absolute value in the current column
            size_t i = r;
            for (size_t k = r + 1; k < Rows; ++k)
            {
                if (std::abs(result[k][lead]) > std::abs(result[i][lead]))
                {
                    i = k;
                }
            }

            // If the pivot is zero, move to the next column
            if (result[i][lead] == 0)
            {
                lead++;
                if (lead >= Cols)
                    return result;
                continue;
            }

            // Swap rows if necessary
            if (i != r)
            {
                std::swap(result[r], result[i]);
            }

            // Normalize the leading row
            T div = result[r][lead];
            for (size_t j = lead; j < Cols; ++j)
            {
                result[r][j] /= div;
            }

            // Eliminate entries below the pivot
            for (size_t i = r + 1; i < Rows; ++i)
            {
                T factor = result[i][lead];
                for (size_t j = lead; j < Cols; ++j)
                {
                    result[i][j] -= factor * result[r][j];
                }
            }

            lead++;
        }

        // Handle zero rows (move zero rows to the bottom)
        size_t non_zero_row = Rows - 1;
        for (size_t r = Rows - 1; r >= 0; --r)
        {
            bool is_zero_row = true;
            for (size_t c = 0; c < Cols; ++c)
            {
                if (result[r][c] != 0)
                {
                    is_zero_row = false;
                    break;
                }
            }
            if (is_zero_row)
            {
                std::swap(result[r], result[non_zero_row]);
                --non_zero_row;
            }
            if (r == 0)
                break;
        }

        return result;
    }

    size_t rank() const
    {
        Matrix<T, Rows, Cols> rref = this->row_echelon();
        size_t rank = 0;

        for (size_t i = 0; i < Rows; ++i)
        {
            bool non_zero_row = false;
            for (size_t j = 0; j < Cols; ++j)
            {
                if (std::abs(rref[i][j]) > 1e-9)
                {
                    non_zero_row = true;
                    break;
                }
            }
            if (non_zero_row)
                ++rank;
        }
        return rank;
    }
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const Vector<T, 2>& vec) {
    os << "[ ";
    for (int i = 0; i < 2; ++i) {
        os << std::fixed << std::setprecision(6) << vec[i];
        if (i != 1) {
            os << ", ";
        }
    }
    os << " ]";
    return os;
}

template <typename T, int Rows, int Cols>
std::ostream& operator<<(std::ostream& os, const Matrix<T, Rows, Cols>& mat) {
    for (int i = 0; i < Rows; ++i) {
        os << "[ ";
        for (int j = 0; j < Cols; ++j) {
            os << std::fixed << std::setprecision(6) << mat[i][j];
            if (j != Cols - 1) {
                os << ", ";
            }
        }
        os << " ]\n";
    }
    return os;
}