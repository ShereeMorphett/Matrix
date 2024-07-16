#include "amv_math.hpp"
#include "colours.hpp"
#include <vector>
#include "Vector.hpp"


#include <stdexcept>
#include <iostream>

/*

    Implement the cosine angle function using the dot product and norms of the vectors.


*/




int main()
{

    Vector<float> u = {0.0, 0.0, 1.0};
    Vector<float> v = {1.0, 0.0, 0.0};

    std::cout << FCYN("Expected Output: ") << std::endl;
    std::cout << FCYN("[0.0]    [1.0]   [0.0]") << std::endl;
    std::cout << cross_product(u, v)  << std::endl;

    u = {1.0, 2.0, 3.0};
    v = {4.0, 5.0, 6.0};
    std::cout << FCYN("Expected Output: ") << std::endl;
    std::cout << FCYN("[-3.0]    [6.0]   [-3.0]") << std::endl;
    std::cout << cross_product(u, v) << std::endl;

    u = {4.0, 2.0, -3.0};
    v = {-2.0, -5.0, 16.0};
    std::cout << FCYN("Expected Output: ") << std::endl;
    std::cout << FCYN("[17.0]    [-58.0]   [-16.0]") << std::endl;
    std::cout << cross_product(u, v) << std::endl;

    return 0;
}