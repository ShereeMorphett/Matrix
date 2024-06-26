#include <vector>
#include <iostream>


// impl<K> Vector<K> {
// fn add(&mut self, v: &Vector<K>);
// fn sub(&mut self, v: &Vector<K>);
// fn scl(&mut self, a: K);
// }


#pragma once

#include <vector>
#include <sstream>
#include <limits>
#include <cmath>




/*std::vector<T> components;  // Use std::vector<T> to store components

    // Constructor to initialize from a std::vector<T>
    vector(const std::vector<T>& v) : components(v) {}

    // Default constructor initializes an empty vector
    vector() {}

    // Constructor to initialize from individual components
    vector(std::initializer_list<T> init) : components(init) {}

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
    vector operator+(const vector& rhs) const {
        if (size() != rhs.size()) {
            throw std::invalid_argument("Vector addition requires vectors of the same size.");
        }

        vector result;
        result.components.reserve(size());

        for (size_t i = 0; i < size(); ++i) {
            result.components.push_back(components[i] + rhs.components[i]);
        }

        return result;
    }*/


template <typename T>
struct vector
{
    std::vector<T> vec;

    friend vector operator* (vector lhs, vector rhs)
    {
        return {lhs.x * rhs.x, lhs.y * rhs.y, lhs.z * rhs.z};
    }

    friend vector operator+ (vector lhs, vector rhs)
    {
        return {lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z};
    }

    friend vector operator- (vector lhs, vector rhs)
    {
        return {lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z};
    }
    
    friend vector operator* (vector lhs, T rhs)
    {
        return {lhs.x * rhs, lhs.y * rhs, lhs.z * rhs};
    }
    
    friend vector operator- (vector lhs, T rhs)
    {
        return {lhs.x - rhs, lhs.y - rhs, lhs.z - rhs};
    }

    friend vector operator/ (vector lhs, T rhs)
    {
        return {lhs.x / rhs, lhs.y / rhs, lhs.z / rhs};
    }
    
    friend vector operator<< (iostream lhs, T rhs)
    {
        for (auto thing: rhs)
            lhs << thing << " ";
        lhs << std::endl;
        // return {lhs.x / rhs, lhs.y / rhs, lhs.z / rhs};
    }
};


template <typename T>
T dot(vector<T> a, vector<T> b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z;

}

template<typename T>
vector<T> cross(const vector<T>& a, const vector<T>& b) {
    vector<T> result;
    result.x = a.y * b.z - a.z * b.y;
    result.y = a.z * b.x - a.x * b.z;
    result.z = a.x * b.y - a.y * b.x;
    return result;
}

template <typename T>
T len_squared(vector<T> vec)
{
    return dot(vec, vec);
}

template <typename T>
T len(vector<T> vec)
{
    return std::sqrt(len_squared(vec));
}

template <typename T>
vector<T> normalize(vector<T> vector)
{
    float normal = len(vector);
    
    vector.x /= normal;
    vector.y /= normal;
    vector.z /= normal;

    return vector;
}
