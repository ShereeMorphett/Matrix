
#include "colours.hpp"
#include <vector>
#include "Vector.hpp"
#include "Matrix.hpp"
#include <stdexcept>
#include <iostream>


/*


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
