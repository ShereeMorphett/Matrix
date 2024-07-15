#include "amv_math.hpp"
#include "colours.hpp"
#include <vector>
#include "Vector.hpp"


#include <stdexcept>
#include <iostream>

/*
    You must write functions that compute different kinds of norms.
    You must also turn in a main function in order to test your functions, ready to be
    compiled (if necessary) and run.
    VIII.0.2 Instructions
    Let v be a vector of a vector space V .
    You must implement the following norms:
    - 1-norm: ∥v∥1 (also called the Taxicab norm or Manhattan norm)
    - 2-norm: ∥v∥ or ∥v∥2 (also called the Euclidean norm)
    - ∞-norm: ∥v∥∞ (also called the supremum norm)

    let u = Vector::from([0., 0., 0.]);
    println!("{}, {}, {}, {}", u.norm_1(), u.norm(), u.norm_inf());
    // 0.0, 0.0, 0.0
    let u = Vector::from([1., 2., 3.]);
    println!("{}, {}, {}, {}", u.norm_1(), u.norm(), u.norm_inf());
    // 6.0, 3.74165738, 3.0
    let u = Vector::from([-1., -2.]);
    println!("{}, {}, {}, {}", u.norm_1(), u.norm(), u.norm_inf());
    // 3.0, 2.236067977, 2.0


*/




int main() {

    Vector<float> u = {0.0, 0.0, 0.0};
    Vector<float> v = {1.0, 2.0, 3.0};
    Vector<float> w = {-1.0, -2.0};

/*    let u = Vector::from([-1., -2.]);
    println!("{}, {}, {}, {}", u.norm_1(), u.norm(), u.norm_inf());
    // 3.0, 2.236067977, 2.0
*/

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