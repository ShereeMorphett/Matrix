#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <vector>
#include <iostream>
#include <initializer_list>
#include <stdexcept>

template <typename T>
struct Vector
{
    std::vector<T> components;

    Vector(const std::vector<T>& v) : components(v) {}
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
            throw std::invalid_argument("Vector subtraction requires vectors of the same size.");

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

    // Linear combination function as a member function
    static Vector<T> linear_combination(const Vector<Vector<T>>& u, const Vector<T>& coefs)
    {
        if (u.size() != coefs.size()) {
            throw std::invalid_argument("Vectors and coefficients must be of the same size.");
        }

        // Initialize result vector with zeros
        Vector<T> result(std::vector<T>(u[0].size(), 0));

        // Compute the linear combination
        for (size_t i = 0; i < u.size(); ++i) {
            result = result + (u[i] * coefs[i]);
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

#endif
