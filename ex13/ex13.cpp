
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


/*

    let u = Matrix::from([
    [ 8., 5., -2.],
    [ 4., 7., 20.],
    [ 7., 6., 1.],
    [21., 18., 7.],
    ]);
    println!("{}", u.rank());
    // 3

*/

int main()
{
        std::cout << FMAG("Testing inverse") << std::endl;
        {
            std::cout << FMAG("Test 1") << std::endl;
            Matrix<float, 3, 3> u = {{1.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, {0.0, 0.0, 1.0}};
            std::cout << FCYN("EXPECTED: ") << std::endl;
            std::cout << FCYN("3") << std::endl;
            std::cout << u.rank() << std::endl;
        }
        {
            std::cout << FMAG("Test 2") << std::endl;
            Matrix<float, 3, 4> u = {{1.0, 2.0, 0.0, 0.0}, { 2.0, 4.0, 0.0, 0.0}, {-1.0, 2.0, 1.0, 1.0}};
            std::cout << FCYN("EXPECTED: ") << std::endl;
            std::cout << FCYN("2") << std::endl;
            std::cout << u.rank() << std::endl;
        }
        {
            std::cout << FMAG("Test 3") << std::endl;
            Matrix<float, 4, 3> u = {{8.0, 5.0, -2.0}, {4.0, 7.0, 20.0}, {7.0, 6.0, 1.0}, {21.0, 18.0, 7.0}};
            std::cout << FCYN("EXPECTED: ") << std::endl;
            std::cout << FCYN("3") << std::endl;
            std::cout << u.rank() << std::endl;
        }

    return 0;
}
