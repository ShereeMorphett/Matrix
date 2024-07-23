
#include "colours.hpp"
#include <vector>
#include "Vector.hpp"
#include "Matrix.hpp"
#include <stdexcept>
#include <iostream>


/*
    You must write a function that computes the transpose matrix of a given matrix
    fn transpose::<K>(&mut self) -> Matrix::<K>;

    The time complexity here is relative to assignment of values, unlike
    the other exercises, where the base operation counted is addition or
    multiplication.
    XIII.1 Conjugate transpose

    Here, you might want to know that the transposition of complex matrices uses something
    called the conjugate transpose, using the conjugation operation of the complex numbers.
    The reason why this is different is linked to the fact that every complex number
    z = a + ib can be represented uniquely as a 2-by-2 real matrix of the form:
    "
    a −b
    b a #
    called a rotation-scaling matrix. Adding or multiplying or inverting these matrices
    is precisely equivalent ("isomorphic") to the same operations on the complex numbers;
    while the conjugate of a complex number is precisely the transpose of this real matrix.
    If you imagine replacing every 1-by-1 coordinate in an n-by-m complex matrix by its
    corresponding 2-by-2 rotation-scaling matrix, then run a simple transpose over this 2n-by2m matrix, you will get a 2m-by-2n real matrix. If you change the order of operations,
    and do the transpose first, before expanding the coefficients into 2-by-2 blocks, you’ll
    realize that you need to use the conjugate transpose, rather than a simple transpose, to
    get to the same final 2m-by-2n matrix.
    There’s a commutative diagram hiding here. Can you figure it out? ;)

*/


int main()
{
        std::cout << FMAG("Testing Transpose") << std::endl;
        {
            Matrix<float, 2, 2> u = {{1.0, 0.0}, {0.0, 1.0}};
            std::cout << u << std::endl;
            Matrix<float, 2, 2> v = u.transpose();
            std::cout << v << std::endl;
        }

        Matrix<float, 3, 3> u = {{1, 1, 1}, {2, 2, 2}, {3, 3, 3}};
        std::cout << u << std::endl;
        Matrix<float, 3, 3> v = u.transpose();
        std::cout << v << std::endl;
        std::cout << std::endl;



    return 0;
}