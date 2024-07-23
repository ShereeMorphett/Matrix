
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

    Gaussian elimination to transform the given matrix into its row echelon form

    Pivoting: Ensure that the leading coefficient (pivot) in each row is 1. 
            If it's not, swap rows or scale the row to make it so.
    Elimination: Use the pivot to eliminate the entries below it,
            ensuring that each subsequent row has zeros below the pivot.
    Handling Zero Rows: Any rows that are entirely zero should be moved to the bottom.

*/


int main()
{
        std::cout << FMAG("Testing Row Echelon") << std::endl;
        {
            std::cout << FMAG("Test 1") << std::endl;

            Matrix<float, 3, 3> u = {{1.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, {0.0, 0.0, 1.0}};

            std::cout << u << std::endl;
            Matrix<float, 3, 3> v = u.row_echelon();
            std::cout << FCYN("EXPECTED: ") << std::endl;
            std::cout << FCYN("[1.0, 0.0, 0.0]\n[0.0, 1.0, 0.0]\n[0.0, 0.0, 1.0] ") << std::endl;


            std::cout << v << std::endl;
            // [1.0, 0.0, 0.0]
            // [0.0, 1.0, 0.0]
            // [0.0, 0.0, 1.0]
        }
        {
            std::cout << FMAG("Test 2") << std::endl;
            Matrix<float, 2, 2> u = {{1.0, 2.0}, {3.0, 4.0}};
            std::cout << u << std::endl;
            Matrix<float, 2, 2> v = u.row_echelon();
            std::cout << FCYN("EXPECTED: ") << std::endl;
            std::cout << FCYN("[1.0, 0.0]\n[0.0, 1.0]") << std::endl;
            std::cout << v << std::endl;
            // // [1.0, 0.0]
            // // [0.0, 1.0]
        }
        {
            std::cout << FMAG("Test 3") << std::endl;
            Matrix<float, 2, 2> u = {{1.0, 2.0}, {2.0, 4.0}};
            std::cout << u << std::endl;
            Matrix<float, 2, 2> v = u.row_echelon();
            std::cout << FCYN("EXPECTED: ") << std::endl;
            std::cout << FCYN("[1.0, 2.0]\n[0.0, 0.0]") << std::endl;
            std::cout << v << std::endl;
            // // [1.0, 2.0]
            // // [0.0, 0.0]
        }
        {
            std::cout << FMAG("Test 4") << std::endl;
            Matrix<float, 3, 5> u = {{8.0, 5.0, -2.0, 4.0, 28.0}, {4.0, 2.5, 20.0, 4.0, -4.0}, {8.0, 5.0, 1.0, 4.0, 17.0}};
            std::cout << u << std::endl;
            Matrix<float, 3, 5> v = u.row_echelon();
            std::cout << FCYN("EXPECTED: ") << std::endl;
            std::cout << FCYN("[1.0, 0.625, 0.0, 0.0, -12.1666667]\n[0.0, 0.0, 1.0, 0.0, -3.6666667]\n[0.0, 0.0, 0.0, 1.0, 29.5 ]") << std::endl;
            std::cout << v << std::endl;
            // [1.0, 0.625, 0.0, 0.0, -12.1666667]
            // [0.0, 0.0, 1.0, 0.0, -3.6666667]
            // [0.0, 0.0, 0.0, 1.0, 29.5 ]*/
        }


    return 0;
}
