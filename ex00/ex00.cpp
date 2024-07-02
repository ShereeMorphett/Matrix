// IV.0.1 Goal
// You must write functions that can add and subtract two vectors, or two matrices, of the
// same size; and a function to multiply a vector, or a matrix, by a scalar (ie, "scaling").
// You must also turn in a main function in order to test your functions, ready to be
// compiled (if necessary) and run.
// IV.0.2 Instructions
// You must write 3 functions.
// - The first one must compute the addition of 2 vectors.
// - The second one must compute the subtraction of a vector by another vector.
// - The third one must compute the scaling of a vector by a scalar.
// If the mathematical operation is nonsensical (ie, summing a vector and a scalar, or
// 16
// Enter the Matrix An introduction to Linear Algebra
// vectors of different sizes), the result is undefined.


#include "Vector.hpp"
#include "Matrix.hpp"
#include "colours.hpp"



int main() {
    // Test vector creation
    Vector<int> vec1 = {1, 2, 3};
    Vector<int> vec2 = {4, 5, 6};

    // Test addition
    std::cout <<  FGRN("Testing Vector Addition\n") << std::endl;
    Vector<int> result_add = vec1 + vec2;
    std::cout <<  FGRN("Expected output: Addition: 4, 7, 9") << std::endl;
    std::cout << "Addition: " << result_add << std::endl;

    // Test subtraction
    std::cout <<  FGRN("\nTesting Vector Subtraction\n") << std::endl;
    Vector<int> result_sub = vec1 - vec2;
    std::cout <<  FGRN("Expected output: Subtraction: 3, 3, 3") << std::endl;
    std::cout << "Subtraction: " << result_sub << std::endl;

    // Test scaling
    int scalar = 2;
    std::cout <<  FGRN("\nTesting Vector scaling\n") << std::endl;
    std::cout <<  FGRN("Expected output: Scaling: 2, 4, 6") << std::endl;
    Vector<int> result_scale = vec1 * scalar;
    std::cout << "Scaling: " << result_scale << std::endl;

    // Test matrix creation
    Matrix<int, 2, 3> mat1 = {{1, 2, 3}, {4, 5, 6}};
    Matrix<int, 2, 3> mat2 = {{7, 8, 9}, {10, 11, 12}};
    Matrix<int, 3, 3> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    // Test matrix addition
    std::cout <<  FGRN("Testing Matrix Addition\n") << std::endl;
    Matrix<int, 2, 3> mat_result_add = mat1 + mat2;
    std::cout <<  FGRN("Expected output: Addition: {9, 10, 13}, {14, 16, 18}") << std::endl;
    std::cout << "Addition: " << mat_result_add << std::endl;


    // Test matrix subtraction
    std::cout <<  FGRN("Testing Matrix subtraction\n") << std::endl;
    Matrix<int, 2, 3> mat_result_sub = mat1 - mat2;
    std::cout <<  FGRN("Expected output: subtraction: {-6, -6, -6}, {-6, -6, -6}") << std::endl;
    std::cout << "subtraction: " << mat_result_sub << std::endl;



    std::cout <<  FGRN("Testing Matrix size and square\n") << std::endl;
    std::cout << KCYN << matrix << RST << std::endl;
    auto size = matrix.getMatrixSize();
    std::cout << "Rows: " << size.first << ", Columns: " << size.second << std::endl;

    if (matrix.isSquareMatrix())
        std::cout << "The matrix is square." << std::endl;
    else
        std::cout << "The matrix is not square." << std::endl;


    return 0;
}