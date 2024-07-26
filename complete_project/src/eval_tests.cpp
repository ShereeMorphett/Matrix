#include <iostream>
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
        std::cout << "result:  " << u * 1  << std::endl;

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
        std::cout << "result:  " << u * 0.5  << std::endl;
    }
    {

        Matrix<float, 2, 2> u = {{0.0, 0.0}, {0.0, 0.0}};
        Matrix<float, 2, 2> v = {{0.0, 0.0}, {0.0, 0.0}};
        std::cout << "result:  " << u * 0  << std::endl;

        u = {{1.0, 0.0}, {0.0, 1.0}};

        std::cout << "result:  " << u * 1  << std::endl;

        u = {{1.0, 2.0}, {3.0, 4.0}};
        v = {{1,0, 1.0}, {1.0, 1.0}};
        std::cout << "result:  " << u * 2  << std::endl;

        u = {{21.0, 21.0}, {21.0, 21.0}};
        std::cout << "result:  " << u  * 0.5 << std::endl;

    }



    return 0;
}