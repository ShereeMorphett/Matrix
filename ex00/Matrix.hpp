    #pragma once

    #include <iostream>
    #include <Matrix>
    #include <sstream>
    #include <limits>
    #include <cmath>


    template <typename T, int x, int y>
    struct Matrix
    {
        std::vector<std::vector<T>> components;

        // Constructor to initialize from a std::Matrix<T>
        Matrix(T type, int x, int y)
        {
            component = std::vector<std::vector<T>>(x, std::vector(y));
        };

        // Constructor to initialize from individual components
        Matrix(std::initializer_list<T> init) : components(init) {};

        // Accessor to get size of the Matrix
        size_t size() const
        {
            return components.size();
        }

        // Access operator to get individual components
        T& operator[](size_t index)
        {
            return components[index];
        }

        const T& operator[](size_t index) const {
            return components[index];
        }

        // Matrix arithmetic operators
        Matrix operator+(const Matrix& rhs) const
        {
            if (size() != rhs.size()) {
                throw std::invalid_argument("Matrix addition requires Matrixs of the same size.");
            }
            Matrix result;
            result.components.reserve(size());
            for (size_t i = 0; i < size(); ++i) {
                result.components.push_back(components[i] + rhs.components[i]);
            }

            return result;
        }
        
        // Matrix arithmetic operators
        Matrix operator-(const Matrix& rhs) const
        {
            if (size() != rhs.size()) {
                throw std::invalid_argument("Matrix addition requires Matrixs of the same size.");
            }
            Matrix result;
            result.components.reserve(size());
            for (size_t i = 0; i < size(); ++i) {
                result.components.push_back(components[i] - rhs.components[i]);
            }

            return result;
        }
            // Matrix arithmetic operators
        Matrix operator*(const T scalar) const
        {
            Matrix result;
            result.components.reserve(size());
            for (size_t i = 0; i < size(); ++i) {
                result.components.push_back(components[i] * scalar);
            }

            return result;
        }

    };

    template <typename T>
    std::ostream& operator<<(std::ostream& os, const Matrix<T>& vec)
    {
        os << "[ ";
        for (size_t i = 0; i < vec.size(); ++i) {
            os << vec[i];
            if (i != vec.size() - 1) {
                os << ", ";
            }
        }
        os << " ]";
        return os;
    }

    // template <typename T>
    // struct Matrix
    // {
    //     std::Matrix<T> components;

    //     Matrix(const std::Matrix<T>& v)
    //     {
    //         for (auto thing: v)
    //         {
    //             components.push_back(thing);
    //         }
    //     }

    //     size_t size() const
    //     {
    //         return components.size();
    //     }

    //     friend Matrix operator* (Matrix lhs, Matrix rhs)
    //     {
    //         return {lhs.x * rhs.x, lhs.y * rhs.y, lhs.z * rhs.z};
    //     }

    //     friend Matrix operator+ (Matrix lhs, Matrix rhs)
    //     {
    //         return {lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z};
    //     }

    //     friend Matrix operator- (Matrix lhs, Matrix rhs)
    //     {
    //         return {lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z};
    //     }
        
    //     friend Matrix operator* (Matrix lhs, T rhs)
    //     {
    //         return {lhs.x * rhs, lhs.y * rhs, lhs.z * rhs};
    //     }
        
    //     friend Matrix operator- (Matrix lhs, T rhs)
    //     {
    //         return {lhs.x - rhs, lhs.y - rhs, lhs.z - rhs};
    //     }

    //     friend Matrix operator/ (Matrix lhs, T rhs)
    //     {
    //         return {lhs.x / rhs, lhs.y / rhs, lhs.z / rhs};
    //     }
        
    //     friend Matrix operator<< (iostream lhs, T rhs)
    //     {
    //         for (auto thing: rhs)
    //             lhs << thing << " ";
    //         lhs << std::endl;
    //     }
    // };


    // template <typename T>
    // T dot(Matrix<T> a, Matrix<T> b)
    // {
    //     return a.x * b.x + a.y * b.y + a.z * b.z;

    // }

    // template<typename T>
    // Matrix<T> cross(const Matrix<T>& a, const Matrix<T>& b) {
    //     Matrix<T> result;
    //     result.x = a.y * b.z - a.z * b.y;
    //     result.y = a.z * b.x - a.x * b.z;
    //     result.z = a.x * b.y - a.y * b.x;
    //     return result;
    // }

    // template <typename T>
    // T len_squared(Matrix<T> vec)
    // {
    //     return dot(vec, vec);
    // }

    // template <typename T>
    // T len(Matrix<T> vec)
    // {
    //     return std::sqrt(len_squared(vec));
    // }

    // template <typename T>
    // Matrix<T> normalize(Matrix<T> Matrix)
    // {
    //     float normal = len(Matrix);
        
    //     Matrix.x /= normal;
    //     Matrix.y /= normal;
    //     Matrix.z /= normal;

    //     return Matrix;
    // }
