
#include "colours.hpp"
#include <vector>
#include "Vector.hpp"
#include "Matrix.hpp"
#include <stdexcept>
#include <iostream>


/*
    You must write a function that computes the trace of the given matrix
    fn trace::<K>(&mut self) -> K;
*/



int main()
{
    {
        std::cout << FMAG("Testing trace") << std::endl;
        {
            Matrix<float, 2, 2> u = {{1.0, 0.0}, {0.0, 1.0}};
            
            std::cout << FCYN("Expected Output: ") << std::endl;
            std::cout << FCYN("2.0") << std::endl;
            float result = u.trace();
            std::cout << result << std::endl;
            std::cout << std::endl;

        Matrix<float, 3, 3> u = {{2.0, -5.0, 0.0}, {4.0, 3.0, 7.0}, {-2.0, 3.0, 4.0}};
        std::cout << FCYN("Expected Output: ") << std::endl;
        std::cout << FCYN("9.0") << std::endl;
        std::cout << u.trace() << std::endl;
        std::cout << std::endl;

        u = {{-2.0, -8.0, 4.0}, {1.0, -23.0, 4.0}, {0.0, 6.0, 4.0}};
        std::cout << FCYN("Expected Output: ") << std::endl;
        std::cout << FCYN("-21.0") << std::endl;
        std::cout << u.trace() << std::endl;
        std::cout << std::endl;
    }
   


    return 0;
}