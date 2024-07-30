#include "amv_math.hpp"
#include "colours.hpp"
#include <vector>
#include "Vector.hpp"
#include <stdexcept>
#include <iostream>




int main() {

    Vector<float> u = {0.0, 0.0, 0.0};
    Vector<float> v = {1.0, 2.0, 3.0};
    Vector<float> w = {-1.0, -2.0};

    std::cout << FCYN("Expected Output: ") << std::endl;
    std::cout << FCYN("0.0\n6.0\n3.0") << std::endl;


    std::cout << "Manhattan norm    " << u.norm_one() << std::endl;
    std::cout << "Manhattan norm    " << v.norm_one() << std::endl;
    std::cout << "Manhattan norm    " << w.norm_one() << std::endl;

    std::cout << FCYN("Expected Output: ") << std::endl;
    std::cout << FCYN("0.0\n3.74165738\n2.236067977") << std::endl;

    std::cout << "Euclidean norm    " << u.norm() << std::endl;
    std::cout << "Euclidean norm    " << v.norm() << std::endl;
    std::cout << "Euclidean norm    " << w.norm() << std::endl;

    std::cout << FCYN("Expected Output: ") << std::endl;
    std::cout << FCYN("0.0\n2.0\n3.0") << std::endl;

    std::cout << "supremum norm    " << u.norm_inf() << std::endl;
    std::cout << "supremum norm    " << v.norm_inf() << std::endl;
    std::cout << "supremum norm    " << w.norm_inf() << std::endl;



    return 0;
}