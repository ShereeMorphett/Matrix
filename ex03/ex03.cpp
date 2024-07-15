#include "amv_math.hpp"
#include "colours.hpp"
#include <vector>
#include "Vector.hpp"


#include <stdexcept>
#include <iostream>

/*
    You must write a function that computes the dot product of two vectors of the same
    dimension.
    You must also turn in a main function in order to test your function, ready to be
    compiled (if necessary) and run.
    VII.0.2 Instructions
    Let u, v ∈ V , where V is a vector space of finite dimension over the real numbers R
    (represented as the type f32).
    The function must compute and return the scalar ⟨u|v⟩ = u·v, called the dot product,
    or inner product, of u and v.
    If both vectors have different dimensions, the behaviour is undefined.

*/




int main() {

    Vector<float> u = {1.0f, 2.0f, 3.0f};
    Vector<float> v = {4.0f, 5.0f, 6.0f};
    Vector<float> result;
    
    std::cout << u.dot(v) << std::endl;


    return 0;
}