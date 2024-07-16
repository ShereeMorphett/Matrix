#pragma once

#include <iostream>
#include <vector>
#include <sstream>
#include <limits>
#include <cmath>
#include <cassert>


template <typename T>
struct Vector
{
    std::vector<T> components;

    Vector(const std::vector<T>& v) : components(v) {};
    Vector() {}

    // Constructor to initialize from individual components
    Vector(std::initializer_list<T> init) : components(init) {}

    size_t size() const
    {
        return components.size();
    }

    T& operator[](size_t index)
    {
        return components[index];
    }

    const T& operator[](size_t index) const
    {
        return components[index];
    }

    Vector operator+(const Vector& rhs) const
    {
        if (size() != rhs.size())
            throw std::invalid_argument("Vector addition requires vectors of the same size.");

        Vector result;
        result.components.reserve(size());
        for (size_t i = 0; i < size(); ++i)
        {
            result.components.push_back(components[i] + rhs.components[i]);
        }
        return result;
    }
    
    Vector operator-(const Vector& rhs) const
    {
        if (size() != rhs.size())
            throw std::invalid_argument("Vector addition requires vectors of the same size.");
    
        Vector result;
        result.components.reserve(size());
        for (size_t i = 0; i < size(); ++i)
        {
            result.components.push_back(components[i] - rhs.components[i]);
        }

        return result;
    }

    Vector operator*(const T scalar) const
    {
        Vector result;
        result.components.reserve(size());
        for (size_t i = 0; i < size(); ++i)
        {
            result.components.push_back(components[i] * scalar);
        }

        return result;
    }
    
    
    T dot(Vector const & b) const
    {
        if (components.size() != b.size())
        {
            throw std::invalid_argument("Vectors must be of the same size");
        }

        T result;

        for (size_t i = 0; i < b.size(); ++i)
        {
            result += components[i] * b[i];
        }

        return result;
    }


    T norm_one() const
    {
        T result = 0;

        for (auto i : components)
        {
            result += std::abs(i);
        }

        return result;
    }


    T norm() const
    {
        T result = 0;

        for (auto i : components)
        {
            result += i * i;
        }

        return std::sqrt(result);

    }

    T norm_inf() const
    {

        if (components.empty())
        {
            return 0.0;
        }

        T max_val = std::abs(components[0]);

        for (const auto& el : components)
        {
            if (std::abs(el) > max_val)
                max_val = std::abs(el);
        }

        return max_val;
    }

};


template <typename T>
T lerp_single(T const & u, T const & v, float t)
{
    return u + t * (v - u);
}

template <typename VecType>
VecType lerp( VecType const & u, VecType  const & v, float t) {
    if (u.size() != v.size()) {
        throw std::invalid_argument("Vectors must be of the same size");
    }

    VecType result;
    for (size_t i = 0; i < u.size(); ++i) {
        result[i] = lerp_single(u[i], v[i], t);
    }

    return result;
}


// Method to compute the cosine of the angle between two vectors

template <typename T>
T angle_cos(const Vector<T>& u, const Vector<T>& v)
{
    T dot_product = u.dot(v);
    T norm_product = u.norm() * v.norm();
    assert(norm_product != 0);
    return dot_product / norm_product;
}


template <typename T>
std::ostream& operator<<(std::ostream & os, Vector<T> const & vec)
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
