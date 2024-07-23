
#include "colours.hpp"
#include <vector>
#include "Vector.hpp"
#include "Matrix.hpp"
#include <stdexcept>
#include <iostream>


/*
    You must write a function that computes the row-echelon form of the given matrix.
    Let A ∈ Km×n, where K is the real numbers (represented as the type f32) and (m, n) ∈ N2
    (represented as two values of type u32).

     row_echelon::<K>(&mut self) -> Matrix::<K>;

*/


int main()
{
        std::cout << FMAG("Testing Row Echelon") << std::endl;
        {
            Matrix<float, 3, 3> u = {{1.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, {0.0, 0.0, 1.0}};

            std::cout << u << std::endl;
            Matrix<float, 3, 3> v = u.row_echelon();
            std::cout << v << std::endl;
            // // [1.0, 0.0]
            // // [0.0, 1.0]
        }
        {
            Matrix<float, 2, 2> u = {{1.0, 2.0}, {3.0, 4.0}};
            std::cout << u << std::endl;
            Matrix<float, 2, 2> v = u.row_echelon();
            std::cout << v << std::endl;
            // // [1.0, 0.0]
            // // [0.0, 1.0]
        }
        {
            Matrix<float, 2, 2> u = {{1.0, 2.0}, {2.0, 4.0}};
            std::cout << u << std::endl;
            Matrix<float, 2, 2> v = u.row_echelon();
            std::cout << v << std::endl;
            // // [1.0, 2.0]
            // // [0.0, 0.0]
        }

        Matrix<float, 5, 3> u = {{8.0, 5.0, -2.0, 4.0, 28.0}, {4.0, 2.5, 20.0, 4.0, -4.0}, {8.0, 5.0, 1.0, 4.0, 17.0}};
        std::cout << u << std::endl;
        Matrix<float, 5, 3> v = u.row_echelon();
        std::cout << v << std::endl;
        // [1.0, 0.625, 0.0, 0.0, -12.1666667]
        // [0.0, 0.0, 1.0, 0.0, -3.6666667]
        // [0.0, 0.0, 0.0, 1.0, 29.5 ]*/


    return 0;
}
