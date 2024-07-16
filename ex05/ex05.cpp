#include "amv_math.hpp"
#include "colours.hpp"
#include <vector>
#include "Vector.hpp"


#include <stdexcept>
#include <iostream>

/*


*/




int main() {

    Vector<float> u = {1.0, 0.0};
    Vector<float> v = {0.0, 1.0};

    std::cout << FCYN("Expectedt: ") << std::endl;
    std::cout << FCYN("1.0") << std::endl;
    std::cout << angle_cos(u, v);

    u = {-1.0, 1.0};
    v = {1.0, 1.0};
    std::cout << FCYN("Expected Output: ") << std::endl;
    std::cout << FCYN("0.0") << std::endl;
    std::cout << angle_cos(u, v);

    u = {-1.0, 1.0};
    v = {1.0, -1.0};
    std::cout << FCYN("Expected Output: ") << std::endl;
    std::cout << FCYN("-1.0") << std::endl;
    std::cout << angle_cos(u, v);


    u = {2.0, 1.0};
    v = {4.0, 2.0};
    std::cout << FCYN("Expected Output: ") << std::endl;
    std::cout << FCYN("1.0") << std::endl;
    std::cout << angle_cos(u, v);


    u = {1.0, 2.0, 3.0};
    v = {4.0, 5.0, 6.0};
    std::cout << FCYN("Expected Output: ") << std::endl;
    std::cout << FCYN("0.974631846") << std::endl;
    std::cout << angle_cos(u, v);

    return 0;
}