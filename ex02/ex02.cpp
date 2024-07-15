#include "amv_math.hpp"
#include "colours.hpp"
#include "Vector.hpp"

#include <vector>

#include <stdexcept>
#include <iostream>

/*
    You must write a function that computes a linear interpolation between two objects of
    the same type.
    You must also turn in a main function in order to test your function, ready to be
    compiled (if necessary) and run.
    The n in the complexity limit is the dimension of the vector/matrix,
    ie, the total number of coordinates.
    Let t ∈ [0; 1](⊂ R) (ie, t is real, and 0 ≤ t ≤ 1) be a scalar.
    • Let f : (V × V × [0; 1]) → V be the function to implement.
    The value of t allows us to "slide" between the two values.
    21
    Enter the Matrix An introduction to Linear Algebra
    • If t = 0, then f(u, v, t) = u.
    • If t = 1, then f(u, v, t) = v.
    • If t = 0.5, then the function returns a value at the exact middle in between of u
    and v (the isobarycenter, which can be understood as the center of gravity, of the
    two points).
    The prototype of the function to write is the following:

    fn lerp::<V>(u: V, v: V, t: f32) -> V;

    Even though linear interpolation is most often used to get points on
    the segment between u and v, technically, the formula should give
    you any point on the infinite line drawn by the points u and v, if
    any value for t is accepted. This is relevant when defining rays in
    raytracing, for example.
*/


int main() {

    std::vector<float> u = {1.0f, 2.0f, 3.0f};
    std::vector<float> v = {4.0f, 5.0f, 6.0f};
    std::vector<float> result;

    // t = 0
    result = lerp(u, v, 0.0f);
    std::cout << "lerp(u, v, 0.0) = ";
    printVector(result);

    // t = 0.5
    result = lerp(u, v, 0.5f);
    std::cout << "lerp(u, v, 0.5) = ";
    printVector(result);

    // t = 1
    result = lerp(u, v, 1.0f);
    std::cout << "lerp(u, v, 1.0) = ";
    printVector(result);



    return 0;
}