
#include "colours.hpp"
#include <vector>
#include "Vector.hpp"
#include "Matrix.hpp"



#include <stdexcept>
#include <iostream>





int main()
{
    {
        std::cout << FMAG("Testing mult_vec") << std::endl;

        Matrix<float, 2, 2> u = {{1.0, 0.0}, {0.0, 1.0}};
        Vector<float, 2> v = {4.0, 2.0};

        std::cout << FCYN("Expected Output: ") << std::endl;
        std::cout << FCYN("[4.0]    [2.0]") << std::endl;
        Vector<float, 2> result = u.mul_vec(v);
        std::cout << result << std::endl;
        std::cout << std::endl;

        u = {{2.0, 0.0}, {0.0, 2.0}};
        std::cout << FCYN("Expected Output: ") << std::endl;
        std::cout << FCYN("[8.0]    [4.0]") << std::endl;
        result = u.mul_vec(v);
        std::cout << result  << std::endl;
        std::cout << std::endl;

        u = {{2.0, -2.0}, {-2.0, 2.0}};
        std::cout << FCYN("Expected Output: ") << std::endl;
        std::cout << FCYN("[4.0]    [-4.0]") << std::endl;
        result = u.mul_vec(v);
        std::cout << result  << std::endl;
    }
    std::cout << FMAG("Testing mult_mac") << std::endl;

    {
        Matrix<float, 2, 2> u = {{1.0, 0.0}, {0.0, 1.0}};
        Matrix<float, 2, 2> v = {{1.0, 0.0}, {0.0, 1.0}};

        std::cout << FCYN("Expected Output: ") << std::endl;
        std::cout << FCYN("[1.0, 0.0]\n[0.0, 1.0]") << std::endl;
        Matrix<float, 2, 2>  result = u.mul_mat(v);
        std::cout << result  << std::endl;

        v = {{2.0, 1.0}, {4.0, 2.0}};
        std::cout << FCYN("Expected Output: ") << std::endl;
        std::cout << FCYN("[2.0, 1.0]\n[4.0, 2.0]") << std::endl;
        result = u.mul_mat(v);
        std::cout << result  << std::endl;



        u = {{3.0, -5.0}, {6.0, 8.0}};
        v = {{2.0, 1.0}, {4.0, 2.0}};

        std::cout << FCYN("Expected Output: ") << std::endl;
        std::cout << FCYN("[-14.0, -7.0]\n[44.0, 22.0]") << std::endl;
        result = u.mul_mat(v);
        std::cout << result  << std::endl;
    
    }



    return 0;
}