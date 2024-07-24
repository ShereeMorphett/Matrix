
#include "colours.hpp"
#include <vector>
#include "Vector.hpp"
#include "Matrix.hpp"
#include <stdexcept>
#include <iostream>


/*
 |A| = ad − bc

    It is easy to remember when you think of a cross:
    a = {{a, b},
         {c, d}   }
    Left is positive (+ad),
    Right is negative (−bc)
   
    a = {{a, b, c},
         {e, f, g}, 
         {h, i ,j} }
    |A| = a(ei − fh) − b(di − fg) + c(dh − eg)


    . = determinant of
    |A| = a . {{e i},{f h}} − b . {{d f},{g i}} + c . {{d e}, {g h}}

*/


int main()
{
        std::cout << FMAG("Testing Determinant") << std::endl;
        {
            std::cout << FMAG("Test 1") << std::endl;
            Matrix<float, 2, 2> u = {{1.0, -1.0}, {-1.0, 1.0}};
            std::cout << FCYN("EXPECTED: ") << std::endl;
            std::cout << FCYN("0.0") << std::endl;
            std::cout << u.determinant() << std::endl;
        }
        {
            std::cout << FMAG("Test 2") << std::endl;
            Matrix<float, 3, 3> u = {{2.0, 0.0, 0.0}, {0.0, 2.0, 0.0}, {0.0, 0.0, 2.0}};
            std::cout << FCYN("EXPECTED: ") << std::endl;
            std::cout << FCYN("8.0") << std::endl;
            std::cout << u.determinant() << std::endl;
        }
        {
            std::cout << FMAG("Test 3") << std::endl;
            Matrix<float, 3, 3> u = {{8.0, 5.0, -2.0}, {4.0, 7.0, 20.0}, {7.0, 6.0, 1.0}};

            std::cout << FCYN("EXPECTED: ") << std::endl;
            std::cout << FCYN("-174.0") << std::endl;
            std::cout << u.determinant() << std::endl;
        }
        {
            Matrix<float, 4, 4> u = {{8.0, 5.0, -2.0, 4.0}, {4.0, 2.5, 20.0, 4.0}, {8.0, 5.0, 1.0, 4.0}, {28.0, -4.0, 17.0, 1.0}};
            std::cout << FCYN("EXPECTED: ") << std::endl;
            std::cout << FCYN("1032.0") << std::endl;
            std::cout << u.determinant() << std::endl;
        }

    return 0;
}
