#include "amv_math.hpp"
#include "colours.hpp"
#include <vector>
#include "Vector.hpp"
#include "Matrix.hpp"



#include <stdexcept>
#include <iostream>





int main()
{
    Matrix<float, 2, 2> u = {{1.0, 0.0}, {0.0, 1.0}};
    Vector<float, 2> v = {4.0, 2.0};

    std::cout << FCYN("Expected Output: ") << std::endl;
    std::cout << FCYN("[4.0]    [2.0]") << std::endl;
    Vector<float, 2> result = u.mul_vec(v);
    std::cout << result  << std::endl;

    u = {{2.0, 0.0}, {0.0, 2.0}};
    std::cout << FCYN("Expected Output: ") << std::endl;
    std::cout << FCYN("[8.0]    [4.0]") << std::endl;
    result = u.mul_vec(v);
    std::cout << result  << std::endl;

    u = {{2.0, -2.0}, {-2.0, 2.0}};
    std::cout << FCYN("Expected Output: ") << std::endl;
    std::cout << FCYN("[4.0]    [-4.0]") << std::endl;
    result = u.mul_vec(v);
    std::cout << result  << std::endl;

    // u = {{1.0, 0.0}, {0.0, 1.0}};
    // u[0] = {2.0, 0.0};
    // u[1] = {0.0, 2.0};

/*
let u = Matrix::from([
[1., 0.],
[0., 1.],
]);
let v = Matrix::from([
[1., 0.],
[0., 1.],
35
Enter the Matrix An introduction to Linear Algebra
]);
println!("{}", u.mul_mat(&v));
// [1., 0.]
// [0., 1.]
let u = Matrix::from([
[1., 0.],
[0., 1.],
]);
let v = Matrix::from([
[2., 1.],
[4., 2.],
]);
println!("{}", u.mul_mat(&v));
// [2., 1.]
// [4., 2.]
let u = Matrix::from([
[3., -5.],
[6., 8.],
]);
let v = Matrix::from([
[2., 1.],
[4., 2.],
])
*/

    return 0;
}