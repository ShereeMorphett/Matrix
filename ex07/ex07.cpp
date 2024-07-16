#include "amv_math.hpp"
#include "colours.hpp"
#include <vector>
#include "Vector.hpp"
#include "Matrix.hpp"



#include <stdexcept>
#include <iostream>

/*

let u = Matrix::from([
[2., 0.],
[0., 2.],
]);
let v = Vector::from([4., 2.]);
println!("{}", u.mul_vec(&v));
// [8.]
// [4.]
let u = Matrix::from([
[2., -2.],
[-2., 2.],
]);
let v = Vector::from([4., 2.]);
println!("{}", u.mul_vec(&v));
// [4.]
// [-4.]
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




int main()
{
    Matrix<float, 2, 2> u = {{1.0, 0.0}, {0.0, 1.0}};
    Vector<float> v = {4.0, 2.0};

    std::cout << FCYN("Expected Output: ") << std::endl;
    std::cout << FCYN("[4.0]    [2.0]") << std::endl;
    std::cout << u.mul_vec(v)  << std::endl;


    u = {{2.0, 0.0}, {0.0, 1.0}};
    v = {8.0, 4.0};
    std::cout << FCYN("Expected Output: ") << std::endl;
    std::cout << FCYN("[8.0]    [4.0]") << std::endl;
    std::cout <<u.mul_vec(v) << std::endl;


    return 0;
}