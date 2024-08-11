#include <iostream>
// #include <vector>
#include "Matrix.hpp"
#include "Vector.hpp"
#include "colours.hpp"





int main()
{
    {
        std::cout << FCYN("\n~~~~Vec Addition~~~~\n")  << std::endl;
        Vector<int,2> u = {0, 0};
        Vector<int, 2> v = {0, 0};
        std::cout << FMAG("Expected: [0,0]")  << std::endl;
        std::cout << "result:  " << u + v  << std::endl;

        u = {1, 0};
        v = {0, 1};
        std::cout << FMAG("Expected: [1,1]")  << std::endl;

        std::cout << "result:  " << u + v  << std::endl;
        
        
        u = {1, 1};
        v = {1, 1};
        std::cout << FMAG("Expected: [2,2]")  << std::endl;
        std::cout << "result:  " << u + v  << std::endl;

        u = {21, 21};
        v = {21, 21};
        std::cout << FMAG("Expected: [42, 42]")  << std::endl;
        std::cout << "result:  " << u + v  << std::endl;
        
        u = {-21, 21};
        v = {21, -21};

        std::cout << FMAG("Expected: [0, 0]")  << std::endl;
        std::cout << "result:  " << u + v  << std::endl;
    }

    {
        Vector<int, 10> u = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        Vector<int, 10> v = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
        std::cout << FMAG("Expected: [9, 9, 9, 9, 9, 9, 9, 9, 9]")  << std::endl;
        std::cout << "result:  " << u + v  << std::endl;
    }

    {
        std::cout << FCYN("\n~~~~Matrix Addition~~~~\n")  << std::endl;
        Matrix<int, 2, 2> u = {{0, 0}, {0, 0}};
        Matrix<int, 2, 2> v = {{0, 0}, {0, 0}};
        std::cout << FMAG("Expected: [0, 0] [0, 0]")  << std::endl;
        std::cout << "result:  " << u + v  << std::endl;


        u = {{0, 0}, {0, 0}};
        v = {{1, 0}, {0, 1}};
        std::cout << FMAG("Expected: [1, 0] [0, 1]")  << std::endl;
        std::cout << "result:  " << u + v  << std::endl;

        u = {{1, 1}, {1, 1}};
        v = {{1, 1}, {1, 1}};
        std::cout << FMAG("Expected: [2, 2] [2, 2]")  << std::endl;
        std::cout << "result:  " << u + v  << std::endl;

        u = {{21, 21}, {21, 21}};
        v = {{21, 21}, {21, 21}};
        std::cout << FMAG("Expected: [42, 42] [42, 42]")  << std::endl;
        std::cout << "result:  " << u  + v  << std::endl;
    }

    std::cout << FCYN("\n~~~~Vector Subtraction~~~~\n")  << std::endl;
    {
        Vector<int,2> u = {0, 0};
        Vector<int, 2> v = {0, 0};
        std::cout << FMAG("Expected: [0, 0]")  << std::endl;

        std::cout << FMAG("Expected: [0, 0]")  << std::endl;
        std::cout << "result:  " << u - v  << std::endl;

        u = {1, 0};
        v = {0, 1};
        std::cout << FMAG("Expected: [1, -1]")  << std::endl;
        std::cout << "result:  " << u - v  << std::endl;
        
        
        u = {1, 1};
        v = {1, 1};
        std::cout << FMAG("Expected: [0, 0]")  << std::endl;
        std::cout << "result:  " << u - v  << std::endl;

        u = {21, 21};
        v = {21, 21};
        std::cout << FMAG("Expected: [0, 0]")  << std::endl;
        std::cout << "result:  " << u - v  << std::endl;

        
        u = {-21, 21};
        v = {21, -21};

        std::cout << FMAG("Expected: [0, 0]")  << std::endl;
        std::cout << "result:  " << u - v  << std::endl;

    }

    {
        Vector<int, 10> u = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        Vector<int, 10> v = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
        std::cout << "result:  " << u - v  << std::endl;
        std::cout << FMAG("Expected: [-9, -8, -7, -6, -5, -4, -3, -2, -1, -0]")  << std::endl;
    }
    {    
        std::cout << FCYN("\n~~~~Matrix Subtraction~~~~\n")  << std::endl;
        Matrix<int, 2, 2> u = {{0, 0}, {0, 0}};
        Matrix<int, 2, 2> v = {{0, 0}, {0, 0}};
        std::cout << FMAG("Expected: [0, 0] [0, 0]")  << std::endl;
        std::cout << "result:  " << u - v  << std::endl;

        u = {{1, 0}, {0, 1}};
        v = {{0, 0}, {0, 0}};
        std::cout << FMAG("Expected: [1, 0] [0, 1]")  << std::endl;
        std::cout << "result:  " << u - v  << std::endl;

        u = {{1, 0}, {0, 1}};
        v = {{1, 0}, {0, 1}};
        std::cout << FMAG("Expected: [0, 0] [0, 0]")  << std::endl;
        std::cout << "result:  " << u - v  << std::endl;

        u = {{21, 21}, {21, 21}};
        v = {{21, 21}, {21, 21}};
        std::cout << FMAG("Expected: [0, 0] [0, 0]")  << std::endl;
        std::cout << "result:  " << u - v  << std::endl;
    }
    {
        std::cout << FCYN("\n~~~~Vec Multiply~~~~\n")  << std::endl;
        Vector<int, 2> u = {0, 0};
        Vector<int, 2> v = {0, 0};

        std::cout << FMAG("Expected: [0, 0]")  << std::endl;
        std::cout << "result:  " << u * 1 << std::endl;

        u = {1, 1};
        std::cout << FMAG("Expected: [1, 1]")  << std::endl;
        std::cout << "result:  " << u * 1  << std::endl;
        
        u = {1, 1};
        std::cout << FMAG("Expected: [0, 0]")  << std::endl;
        std::cout << "result:  " << u * 2  << std::endl;


        u = {21, 21};
        std::cout << FMAG("Expected: [0, 0]")  << std::endl;
        std::cout << "result:  " << u * 2  << std::endl;


        u = {42, 42};
        std::cout << FMAG("Expected: [0, 0]")  << std::endl;
        std::cout << "result:  " << u * static_cast<float>(0.5)  << std::endl;
    }
    {
        std::cout << FCYN("\n~~~~Matrix Multiply~~~~\n")  << std::endl;

        Matrix<float, 2, 2> u = {{0.0, 0.0}, {0.0, 0.0}};
        std::cout << FMAG("Expected: [0, 0], [0, 0]")  << std::endl;
        std::cout << "result:  " << u * 0  << std::endl;

        u = {{1.0, 0.0}, {0.0, 1.0}};

       std::cout << FMAG("Expected: [1, 0], [0, 1]")  << std::endl;
       std::cout << "result:  " << u * 1  << std::endl;

        u = {{1.0, 2.0}, {3.0, 4.0}};
        std::cout << FMAG("Expected: [2, 4], [6, 8]")  << std::endl;
        std::cout << "result:  " << u * 2  << std::endl;

        u = {{21.0, 21.0}, {21.0, 21.0}};
        std::cout << FMAG("Expected: [10.5, 10.5], [10.5, 10.5]")  << std::endl;
        std::cout << "result:  " << u * 0.5  << std::endl;
    }


    std::cout << FCYN("\n~~~~Linear Combination~~~~\n")  << std::endl;
    {
        Vector<Vector<double, 2>, 1> vectors = { Vector<double, 2>{-42., 42.} };
        Vector<double, 1> coefficients = { -1. };
        auto result = Vector<double, 2>::linear_combination(vectors, coefficients);
        std::cout << "Test 1 result: " << result << std::endl;
        std::cout << FMAG("Expected: [42, -42]")  << std::endl;
    }
    {
        Vector<Vector<double, 1>, 3> vectors = {
            Vector<double, 1>{-42.},
            Vector<double, 1>{-42.},
            Vector<double, 1>{-42.}
        };
        Vector<double, 3> coefficients = { -1., 1., 0. };
        auto result = Vector<double, 1>::linear_combination(vectors, coefficients);
        std::cout << "Test 2 result: " << result << std::endl;
        std::cout << FMAG("Expected: [0]")  << std::endl;  
    }

    {
        Vector<Vector<double, 2>, 3> vectors =
        {
            Vector<double, 2>{-42., 42.},
            Vector<double, 2>{1., 3.},
            Vector<double, 2>{10., 20.}
        };
        Vector<double, 3> coefficients = { 1., -10., -1. };
        auto result = Vector<double, 2>::linear_combination(vectors, coefficients);
        std::cout << FMAG("Expected: [-62, -8]")  << std::endl;
        std::cout << "Test 3 result: " << result << std::endl;
    }

    {
        Vector<Vector<double, 3>, 2> vectors = {
            Vector<double, 3>{-42., 100., -69.5},
            Vector<double, 3>{1., 3., 5.}
        };
        Vector<double, 2> coefficients = { 1., -10. };
        auto result = Vector<double, 3>::linear_combination(vectors, coefficients);
        std::cout << FMAG("Expected: [-52, 70, -119.5]")  << std::endl;
        std::cout << "Test 4 result: " << result << std::endl;
    }

    std::cout << FCYN("\n~~~~Linear Interpolation~~~~\n")  << std::endl;
    {
        std::cout << FMAG("Expected: 0")  << std::endl;
        std::cout << lerp(0, 1, 0) << std::endl;
        
        std::cout << FMAG("Expected: 1")  << std::endl;
        std::cout << lerp(0, 1, 1) << std::endl;

        std::cout << FMAG("Expected: 21")  << std::endl;
        std::cout << lerp(0, 42, 0.5) << std::endl;
        
        std::cout << FMAG("Expected: 0")  << std::endl;
        std::cout << lerp(-42, 42, 0.5) << std::endl;

        std::cout << FMAG("Expected: [0.0] [0.0]")  << std::endl;
        std::cout << lerp(Vector<double, 2> {-42, 42}, Vector<double, 2> {42, -42}, 0.5) << std::endl;
    }
    {
        std::cout << FCYN("\n~~~~Dot Product~~~~\n")  << std::endl;

        Vector<double, 2> u = {0,0};
        Vector<double, 2> v = {0,0};

        std::cout << FMAG("Expected: 0")  << std::endl;
        std::cout << u.dot(v) << std::endl;

        u = {1, 0};
        v = {0, 0};
        std::cout << FMAG("Expected: 0")  << std::endl;
        std::cout << u.dot(v) << std::endl;

        u = {1,0};
        v = {1, 0};
        std::cout << FMAG("Expected: 1")  << std::endl;
        std::cout << u.dot(v) << std::endl;

        u = {1, 0};
        v = {0, 1};
        std::cout << FMAG("Expected: 0")  << std::endl;
        std::cout << u.dot(v) << std::endl;

        u = {1,1};
        v = {1,1};
        std::cout << FMAG("Expected: 2")  << std::endl;
        std::cout << u.dot(v) << std::endl;

        u = {4, 2};
        v = {2, 1};
        std::cout << FMAG("Expected: 10")  << std::endl;
        std::cout << u.dot(v) << std::endl;
    }

    {
        std::cout << FCYN("\n~~~~Euclidean Norm~~~~\n")  << std::endl;

        Vector<double, 1> u = {0};
        Vector<double, 2> v = {0,0};

        std::cout << FMAG("Expected: 0")  << std::endl;
        std::cout << u.norm() << std::endl;

        u = {1};
        std::cout << FMAG("Expected: 1")  << std::endl;
        std::cout << u.norm() << std::endl;

        std::cout << FMAG("Expected: 0")  << std::endl;
        std::cout << v.norm() << std::endl;

        v = {1, 0};
        std::cout << FMAG("Expected: 1")  << std::endl;
        std::cout << v.norm() << std::endl;

        v = {2,1};
        std::cout << FMAG("Expected: 2.236067977")  << std::endl;
        std::cout << v.norm() << std::endl;

        v = {4,2};
        std::cout << FMAG("Expected: 4.472135955")  << std::endl;
        std::cout << v.norm() << std::endl;
        
        v = {-4,-2};
        std::cout << FMAG("Expected: 4.472135955")  << std::endl;
        std::cout << v.norm() << std::endl;
    }

    {
        std::cout << FCYN("\n~~~~Manhattan Norm ~~~~\n")  << std::endl;

        Vector<double, 1> u = {0};
        Vector<double, 2> v = {0,0};

        std::cout << FMAG("Expected: 0")  << std::endl;
        std::cout << u.norm_one() << std::endl;

        u = {1};
        std::cout << FMAG("Expected: 1")  << std::endl;
        std::cout << u.norm_one() << std::endl;

        std::cout << FMAG("Expected: 0")  << std::endl;
        std::cout << v.norm_one() << std::endl;

        v = {1, 0};
        std::cout << FMAG("Expected: 1")  << std::endl;
        std::cout << v.norm_one() << std::endl;

        v = {2,1};
        std::cout << FMAG("Expected: 3")  << std::endl;
        std::cout << v.norm_one() << std::endl;

        v = {4,2};
        std::cout << FMAG("Expected: 6")  << std::endl;
        std::cout << v.norm_one() << std::endl;
        
        v = {-4,-2};
        std::cout << FMAG("Expected: 6")  << std::endl;
        std::cout << v.norm_one() << std::endl;
    }
    {
        std::cout << FCYN("\n~~~~supremum Norm ~~~~\n")  << std::endl;

        Vector<double, 1> u = {0};
        Vector<double, 2> v = {0,0};

        std::cout << FMAG("Expected: 0")  << std::endl;
        std::cout << u.norm_inf() << std::endl;

        u = {1};
        std::cout << FMAG("Expected: 1")  << std::endl;
        std::cout << u.norm_inf() << std::endl;

        std::cout << FMAG("Expected: 0")  << std::endl;
        std::cout << v.norm_inf() << std::endl;

        v = {1, 0};
        std::cout << FMAG("Expected: 1")  << std::endl;
        std::cout << v.norm_inf() << std::endl;
    }
    {
        std::cout << FCYN("\n~~~~Cosine ~~~~\n")  << std::endl;

        Vector<double, 2> u = {1, 0};
        Vector<double, 2> v = {0, 1};
        std::cout << FMAG("Expected: 0]")  << std::endl;
        std::cout << angle_cos(u, v) << std::endl;

        u = {8, 7};
        v = {3, 2};
        std::cout << FMAG("Expected: 0.9914542655425437")  << std::endl;
        std::cout << angle_cos(u, v) << std::endl;


        u = {1, 1};
        v = {1, 1};
        std::cout << FMAG("Expected: 1")  << std::endl;
        std::cout << angle_cos(u, v) << std::endl;

        u = {4, 2};
        v = {1, 1};
        std::cout << FMAG("Expected: 0.9486832980505138")  << std::endl;
        std::cout << angle_cos(u, v) << std::endl;
        
        u = {-7,3};
        v = {6, 4};
        std::cout << FMAG("Expected: -0.5462677805469223")  << std::endl;
        std::cout << angle_cos(u, v) << std::endl;
    }

    {
        std::cout << FCYN("\n~~~~Cross product ~~~~\n")  << std::endl;

        Vector<int, 3> u = {0, 0, 0};
        Vector<int, 3> v = {0, 0, 0};
        std::cout << FMAG("Expected: [0, 0, 0]")  << std::endl;
        std::cout << cross_product(u, v) << std::endl;

        u = {1, 0, 0};
        v = {0, 0, 0};
        std::cout << FMAG("Expected: [0, 0, 0]")  << std::endl;
        std::cout << cross_product(u, v) << std::endl;


        u = {1, 0, 0};
        v = {0, 1, 0};
        std::cout << FMAG("Expected: [0, 0, 1]")  << std::endl;
        std::cout << cross_product(u, v) << std::endl;

        u = {8, 7, -4};
        v = {3, 2, 1};
        std::cout << FMAG("Expected: [15, -20, -5]")  << std::endl;
        std::cout << cross_product(u, v) << std::endl;


        u = {1, 1, 1};
        v = {0, 0, 0};
        std::cout << FMAG("Expected: [0, 0, 0]")  << std::endl;
        std::cout << cross_product(u, v) << std::endl;
        
        u = {1, 1, 1};
        v = {1, 1, 1};
        std::cout << FMAG("Expected: [0, 0, 0]")  << std::endl;
        std::cout << cross_product(u, v) << std::endl;
    }

    {
        std::cout << FCYN("\n~~~~Linear transform ~~~~\n")  << std::endl;

        Matrix<int, 2, 2> u = {{0, 0}, {0, 0}};
        Vector<int, 2> v = {0, 0};
        std::cout << FMAG("Expected: [0, 0]")  << std::endl;
        std::cout << u.mul_vec(v) << std::endl;

        u = {{1, 0}, {0, 1}};
        v = {3, 2};
        std::cout << FMAG("Expected: [3, 2]")  << std::endl;
        std::cout << u.mul_vec(v) << std::endl;


        u = {{1, 1}, {1, 1}};
        v = {4, 2};
        std::cout << FMAG("Expected: [6, 6]")  << std::endl;
        std::cout << u.mul_vec(v) << std::endl;

        u = {{2, 0}, {0, 2}};
        v = {2, 1};
        std::cout << FMAG("Expected: [4, 2]")  << std::endl;
        std::cout << u.mul_vec(v) << std::endl;
    }
    {
        Matrix<double, 2, 2> u = {{0.5, 0}, {0, 0.5}};
        Vector<double, 2> v = {4, 2};
        std::cout << FMAG("Expected: [2, 1]")  << std::endl;
        std::cout << u.mul_vec(v) << std::endl;
    }
    {
        std::cout << FCYN("\n~~~~Trace~~~~\n")  << std::endl;
        Matrix<int, 2, 2> u = {{0, 0}, {0, 0}};
 
        std::cout << FMAG("Expected: 0")  << std::endl;
        std::cout << u.trace() << std::endl;

        u = {{1, 0}, {0, 1}};
 
        std::cout << FMAG("Expected: 2")  << std::endl;
        std::cout << u.trace() << std::endl;
        
        u = {{1, 2}, {3, 4}};
        std::cout << FMAG("Expected: 5")  << std::endl;
        std::cout << u.trace() << std::endl;
        
        u = {{8, 7}, {4, 2}};
        std::cout << FMAG("Expected: 10")  << std::endl;
        std::cout << u.trace() << std::endl;

        Matrix<int, 3, 3> v = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
        std::cout << FMAG("Expected: 3")  << std::endl;
        std::cout << v.trace() << std::endl;
    }

    return 0;
}