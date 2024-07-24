
#include "colours.hpp"
#include <vector>
#include "Vector.hpp"
#include "Matrix.hpp"
#include <stdexcept>
#include <iostream>


/*

    The inverse of a matrix is another matrix that, when multiplied by the given matrix, 
    yields the multiplicative identity. For a matrix A, its inverse is A-1. And A.A-1 = I, 
    where I is denoted as the identity matrix.

    there is no concept of dividing by a matrix.
    But we can multiply by an inverse, which achieves the same thing.

*/


int main()
{
        std::cout << FMAG("Testing inverse") << std::endl;
        {
            std::cout << FMAG("Test 1") << std::endl;
            Matrix<float, 2, 2> u = {{1.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, {0.0, 0.0, 1.0}};
            std::cout << FCYN("EXPECTED: ") << std::endl;
            std::cout << FCYN("[1.0, 0.0, 0.0]\n[0.0, 1.0, 0.0]\n[0.0, 0.0, 1.0]") << std::endl;
            std::cout << u.inverse() << std::endl;
        }
        {
            std::cout << FMAG("Test 2") << std::endl;
            Matrix<float, 3, 3> u = {{2.0, 0.0, 0.0}, {0.0, 2.0, 0.0}, {0.0, 0.0, 2.0}};
            std::cout << FCYN("EXPECTED: ") << std::endl;
            std::cout << FCYN("[0.5, 0.0, 0.0]\n[0.0, 0.5, 0.0]\n[0.0, 0.0, 0.5]") << std::endl;
            std::cout << u.inverse() << std::endl;
        }
        {
            std::cout << FMAG("Test 3") << std::endl;
            Matrix<float, 3, 3> u = {{8.0, 5.0, -2.0}, {4.0, 7.0, 20.0}, {7.0, 6.0, 1.0}};
            std::cout << FCYN("EXPECTED: ") << std::endl;
            std::cout << FCYN("[0.649425287, 0.097701149, -0.655172414]\n[-0.781609195, -0.126436782, 0.965517241]\n[0.143678161, 0.074712644, -0.206896552]") << std::endl;
            std::cout << u.inverse() << std::endl;
        }

    return 0;
}
