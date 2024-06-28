#pragma once

#include <iostream>
#include <vector>
#include <sstream>
#include <limits>
#include <cmath>


template <typename T>
struct Vector
{
    std::vector<T> components;  // Use std::vector<T> to store components

    // Constructor to initialize from a std::vector<T>
    Vector(const std::vector<T>& v) : components(v) {};

    // Default constructor initializes an empty vector
    Vector() {}

    // Constructor to initialize from individual components
    Vector(std::initializer_list<T> init) : components(init) {}

    // Accessor to get size of the vector
    size_t size() const {
        return components.size();
    }

    // Access operator to get individual components
    T& operator[](size_t index) {
        return components[index];
    }

    const T& operator[](size_t index) const {
        return components[index];
    }

    // Vector arithmetic operators
    Vector operator+(const Vector& rhs) const
    {
        if (size() != rhs.size()) {
            throw std::invalid_argument("Vector addition requires vectors of the same size.");
        }
        Vector result;
        result.components.reserve(size());
        for (size_t i = 0; i < size(); ++i) {
            result.components.push_back(components[i] + rhs.components[i]);
        }

        return result;
    }
    
    // Vector arithmetic operators
    Vector operator-(const Vector& rhs) const
    {
        if (size() != rhs.size()) {
            throw std::invalid_argument("Vector addition requires vectors of the same size.");
        }
        Vector result;
        result.components.reserve(size());
        for (size_t i = 0; i < size(); ++i) {
            result.components.push_back(components[i] - rhs.components[i]);
        }

        return result;
    }
        // Vector arithmetic operators
    Vector operator*(const T scalar) const
    {
        Vector result;
        result.components.reserve(size());
        for (size_t i = 0; i < size(); ++i) {
            result.components.push_back(components[i] * scalar);
        }

        return result;
    }

};

template <typename T>
std::ostream& operator<<(std::ostream& os, const Vector<T>& vec)
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
// struct Vector
// {
//     std::vector<T> components;

//     vector(const std::vector<T>& v)
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

//     friend vector operator* (vector lhs, vector rhs)
//     {
//         return {lhs.x * rhs.x, lhs.y * rhs.y, lhs.z * rhs.z};
//     }

//     friend vector operator+ (vector lhs, vector rhs)
//     {
//         return {lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z};
//     }

//     friend vector operator- (vector lhs, vector rhs)
//     {
//         return {lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z};
//     }
    
//     friend vector operator* (vector lhs, T rhs)
//     {
//         return {lhs.x * rhs, lhs.y * rhs, lhs.z * rhs};
//     }
    
//     friend vector operator- (vector lhs, T rhs)
//     {
//         return {lhs.x - rhs, lhs.y - rhs, lhs.z - rhs};
//     }

//     friend vector operator/ (vector lhs, T rhs)
//     {
//         return {lhs.x / rhs, lhs.y / rhs, lhs.z / rhs};
//     }
    
//     friend vector operator<< (iostream lhs, T rhs)
//     {
//         for (auto thing: rhs)
//             lhs << thing << " ";
//         lhs << std::endl;
//     }
// };


// template <typename T>
// T dot(vector<T> a, vector<T> b)
// {
//     return a.x * b.x + a.y * b.y + a.z * b.z;

// }

// template<typename T>
// vector<T> cross(const vector<T>& a, const vector<T>& b) {
//     vector<T> result;
//     result.x = a.y * b.z - a.z * b.y;
//     result.y = a.z * b.x - a.x * b.z;
//     result.z = a.x * b.y - a.y * b.x;
//     return result;
// }

// template <typename T>
// T len_squared(vector<T> vec)
// {
//     return dot(vec, vec);
// }

// template <typename T>
// T len(vector<T> vec)
// {
//     return std::sqrt(len_squared(vec));
// }

// template <typename T>
// vector<T> normalize(vector<T> vector)
// {
//     float normal = len(vector);
    
//     vector.x /= normal;
//     vector.y /= normal;
//     vector.z /= normal;

//     return vector;
// }
