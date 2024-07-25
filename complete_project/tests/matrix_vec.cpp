#include "tests.hpp"
#include "Matrix.hpp"
#include "Vector.hpp"


#include <algorithm> 


/////EX00///////

TEST_CASE("Vector operations")
{
    // Test vector creation
    Vector<int, 3> vec1 = {1, 2, 3};
    Vector<int, 3> vec2 = {4, 5, 6};

    // Test subtraction
    SECTION("Vector Subtraction") {
        Vector<int, 3> result_sub = vec1 - vec2;
        Vector<int, 3> expected_sub = {-3, -3, -3}; // Expected result of vec1 - vec2
        REQUIRE(result_sub == expected_sub);
        result_sub = vec2 - vec1;
        expected_sub = {3, 3, 3}; // Expected result of vec2 - vec1
    }

    // Test scaling
    SECTION("Vector Scaling") {
        int scalar = 2;
        Vector<int, 3> result_scale = vec1 * scalar;
        Vector<int, 3> expected_scale = {2, 4, 6}; // Expected result of vec1 * scalar
        scalar = 1;
        result_scale = vec1 * scalar;
        expected_scale = {1, 2, 3}; // Expected result of vec1 * scalar
        REQUIRE(result_scale == expected_scale);
    
    }
}

TEST_CASE("Matrix operations")
{
    // Test matrix creation
    Matrix<int, 2, 3> mat1 = {{1, 2, 3}, {4, 5, 6}};
    Matrix<int, 2, 3> mat2 = {{7, 8, 9}, {10, 11, 12}};
    Matrix<int, 3, 3> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    // Test matrix addition
    SECTION("Matrix Addition") {
        Matrix<int, 2, 3> mat_result_add = mat1 + mat2;
        Matrix<int, 2, 3> expected_add = {{8, 10, 12}, {14, 16, 18}};
        REQUIRE(mat_result_add == expected_add);
    }

    // Test matrix subtraction
    SECTION("Matrix Subtraction") {
        Matrix<int, 2, 3> mat_result_sub = mat1 - mat2;
        Matrix<int, 2, 3> expected_sub = {{-6, -6, -6}, {-6, -6, -6}};
        REQUIRE(mat_result_sub == expected_sub);
    }

    // Test matrix size and square check
    SECTION("Matrix Size and Square Check") {
        auto size = matrix.getMatrixSize();
        REQUIRE(size.first == 3);
        REQUIRE(size.second == 3);

        REQUIRE(matrix.isSquareMatrix());
    }
}


/////EX01///////

TEST_CASE("Vector linear combination")
{
    // Define some vectors
    Vector<double, 3> e1({1.0, 0.0, 0.0});
    Vector<double, 3> e2({0.0, 1.0, 0.0});
    Vector<double, 3> e3({0.0, 0.0, 1.0});

    // Define coefficients
    std::vector<Vector<double, 3>> vectors = {e1, e2, e3};
    std::vector<double> coefs = {10.0, -2.0, 0.5};

    SECTION("Testing linear combination with 3 vectors")
    {
        Vector<double, 3> result = Vector<double, 3>::linear_combination(vectors, coefs);
        Vector<double, 3> expected_result({10.0, -2.0, 0.5});

        INFO("Expected result: " << expected_result);
        INFO("Actual result: " << result);
        REQUIRE(result == expected_result);
    }

    // Another set of vectors and coefficients
    Vector<double, 3> vec1({1.0, 2.0, 3.0});
    Vector<double, 3> vec2({0.0, 10.0, -100.0});
    std::vector<double> coefs2 = {10.0, -2.0};
    std::vector<Vector<double, 3>> vectors2 = {vec1, vec2};

    SECTION("Testing linear combination with 2 vectors")
    {
        Vector<double, 3> result = Vector<double, 3>::linear_combination(vectors2, coefs2);
        Vector<double, 3> expected_result({10.0, 0.0, 230.0});

        INFO("Expected result: " << expected_result);
        INFO("Actual result: " << result);
        REQUIRE(result == expected_result);
    }
}

/////EX03///////
constexpr float tolerance = 1e-6;

// Custom assertion for floating-point comparison
bool areClose(float a, float b, float tol) {
    return std::fabs(a - b) < tol;
}

TEST_CASE("Vector dot product") {
    // Initialize vectors
    Vector<float, 3> u({1.0f, 2.0f, 3.0f});
    Vector<float, 3> v({4.0f, 5.0f, 6.0f});
    
    // Expected result of the dot product
    float expected_result = 1.0f * 4.0f + 2.0f * 5.0f + 3.0f * 6.0f;
    
    SECTION("Computing dot product") {
        // Compute the dot product
        float result = u.dot(v);
        
        INFO("Expected result: " << expected_result);
        INFO("Actual result: " << result);
        
        // Check if the computed result matches the expected result within tolerance
        REQUIRE(areClose(result, expected_result, tolerance));
    }
}