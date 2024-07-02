#include <iostream>
#include <array>
#include <stdexcept>
#include <utility>

// Matrix class
template <typename T, int Rows, int Cols>
class Matrix
{
    public:
        std::array<std::array<T, Cols>, Rows> components;
        const int rows = Rows;
        const int cols = Cols;


        Matrix(std::initializer_list<std::initializer_list<T>> init) {
            if (init.size() != Rows || (init.size() > 0 && init.begin()->size() != Cols))
                throw std::invalid_argument("Matrix dimensions do not match.");
            auto row_it = init.begin();
            for (int i = 0; i < Rows; ++i, ++row_it) {
                auto col_it = row_it->begin();
                for (int j = 0; j < Cols; ++j, ++col_it) {
                    components[i][j] = *col_it;
                }
            }
        }

        // Addition
        Matrix operator+(const Matrix& rhs) const {
            if (Rows != rhs.rows || Cols != rhs.cols)
                throw std::invalid_argument("Matrix addition requires matrices of the same size.");
            Matrix result = *this;
            for (int i = 0; i < Rows; ++i) {
                for (int j = 0; j < Cols; ++j) {
                    result.components[i][j] += rhs.components[i][j];
                }
            }
            return result;
        }

        // Subtraction
        Matrix operator-(const Matrix& rhs) const {
            if (Rows != rhs.rows || Cols != rhs.cols)
                throw std::invalid_argument("Matrix subtraction requires matrices of the same size.");
            Matrix result = *this;
            for (int i = 0; i < Rows; ++i) {
                for (int j = 0; j < Cols; ++j) {
                    result.components[i][j] -= rhs.components[i][j];
                }
            }
            return result;
        }

        // Scaling
        Matrix operator*(const T scalar) const {
            Matrix result = *this;
            for (int i = 0; i < Rows; ++i) {
                for (int j = 0; j < Cols; ++j) {
                    result.components[i][j] *= scalar;
                }
            }
            return result;
        }

        std::pair<size_t, size_t> getMatrixSize() const {
            return {Rows, Cols};
        }

        bool isSquareMatrix() const {
            return Rows == Cols;
        }

        // Output
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
