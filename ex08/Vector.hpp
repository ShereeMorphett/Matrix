#pragma once

#include <iostream>
#include <array>
#include <sstream>
#include <limits>
#include <cmath>
#include <cassert>


template <typename T, size_t Size>
struct VectorStorage
{
    std::array<T, Size> components;

    VectorStorage() = default;
    VectorStorage(const VectorStorage&) = default;
    VectorStorage& operator=(const VectorStorage&) = default;
};

template <typename T, size_t Size>
struct VectorInit;

template <typename T>
struct VectorInit<T, 2> : public VectorStorage<T, 2>
{
    VectorInit() = default;
    VectorInit(const VectorInit&) = default;
    VectorInit& operator=(const VectorInit&) = default;

    using base = VectorStorage<T, 2>;

    VectorInit(T x, T y)
     : base{ {{ x, y }} }
    {}
};

template <typename T>
struct VectorInit<T, 3> : public VectorStorage<T, 3>
{
    VectorInit() = default;
    VectorInit(const VectorInit&) = default;
    VectorInit& operator=(const VectorInit&) = default;

    using base = VectorInit<T, 3>;

    VectorInit(T x, T y, T z)
     : base{ {{ x, y, z }} }
    {}
};

template <typename T>
struct VectorInit<T, 4> : public VectorStorage<T, 4>
{
    VectorInit() = default;
    VectorInit(const VectorInit&) = default;
    VectorInit& operator=(const VectorInit&) = default;

    using base = VectorInit<T, 4>;

    VectorInit(T x, T y, T z, T w)
     : base{ {{ x, y, z, w }} }
    {}

};

template <typename T, size_t Size>
struct Vector : public VectorInit<T, Size>
{
    Vector() = default;
    Vector(const Vector&) = default;
    Vector& operator=(const Vector&) = default;

    using base = VectorInit<T, Size>;
    using base::base;

    size_t size() const
    {
        return Size;
    }

    T& operator[](size_t index)
    {
        return base::components[index];
    }

    const T& operator[](size_t index) const
    {
        return base::components[index];
    }

    //CHANGE LOTS
    Vector<T, Size> operator+(const Vector& rhs) const
    {
        Vector<T, Size> result;
        for (size_t i = 0; i < size(); ++i)
        {
            result[i] = (*this)[i] + rhs[i];
        }
        return result;
    }
    
    Vector<T, Size> operator-(const Vector& rhs) const
    {
        Vector<T, Size> result;
        for (size_t i = 0; i < size(); ++i)
        {
            result[i] = (*this)[i] - rhs[i];
        }
        return result;
    }

    Vector<T, Size> operator*(const Vector& rhs) const
    {
        Vector<T, Size> result;
        for (size_t i = 0; i < size(); ++i)
        {
            result[i] = (*this)[i] * rhs[i];
        }
        return result;
    }
    
    
    T dot(const Vector<T, Size>& b) const
    {
        T result = T();
        for (size_t i = 0; i < size(); ++i)
        {
            result += (*this)[i] * b[i];
        }
        return result;
    }


    T norm_one() const
    {
        T result = T();

        for (auto i : base::components)
        {
            result += std::abs(i);
        }

        return result;
    }


    T norm() const
    {
        T result = T();

        for (auto i : base::components)
        {
            result += i * i;
        }

        return std::sqrt(result);

    }

    T norm_inf() const
    {

        if (base::components.empty())
        {
            return 0.0;
        }

        T max_val = std::abs(base::components[0]);

        for (const auto& el : base::components)
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

template<typename T>
Vector<T, 3> cross_product(const Vector<T, 3>& v, const Vector<T, 3>& u)
{
    Vector<T, 3> result;
    result[0] = v[1] * u[2] - v[2] * u[1];
    result[1] = v[2] * u[0] - v[0] * u[2];
    result[2] = v[0] * u[1] - v[1] * u[0];
    return result;
}


template <typename VecType>
VecType lerp( VecType const & u, VecType  const & v, float t)
{
    if (u.size() != v.size()) {
        throw std::invalid_argument("Vectors must be of the same size");
    }

    VecType result;
    for (size_t i = 0; i < u.size(); ++i)
    {
        result[i] = lerp_single(u[i], v[i], t);
    }

    return result;
}


// Method to compute the cosine of the angle between two vectors
// The cosine of the angle between two vectors 
// u and v can be found using the dot product and the magnitudes (norms) of the vectors
template <typename T, size_t Size>
T angle_cos(const Vector<T, Size>& u, const Vector<T, Size>& v)
{
    T dot_product = u.dot(v);
    T norm_product = u.norm() * v.norm();
    assert(norm_product != 0);
    return dot_product / norm_product;
}

template <typename T, size_t Size>
std::ostream& operator<<(std::ostream & os, Vector<T, Size> const & vec)
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
