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
bool are_close(float a, float b, float tol)
{
    return std::fabs(a - b) < tol;
}

TEST_CASE("Vector dot product") {
    // Initialize vectors
    Vector<float, 2> u({0.0f, 0.0f});
    Vector<float, 2> v({1.0f, 1.0f});

    // Expected result of the dot product
    
    float expected_result = 0.0f;
    
    SECTION("Computing dot product")
    {
        // Compute the dot product
        { 
            auto result = u.dot(v);
            INFO("Expected result: " << expected_result);
            INFO("Actual result: " << result);        
            REQUIRE(are_close(result, expected_result, tolerance));
        }

        {
            u = {1.0f, 1.0f};
            v = {1.0f, 1.0f};
            auto result = u.dot(v);
            expected_result = 2.0f;
            INFO("Expected result: " << expected_result);
            INFO("Actual result: " << result);        
            REQUIRE(are_close(result, expected_result, tolerance));
        }
        {
            u = {-1.0f, 6.0f};
            v = {3.0f, 2.0f};
            auto result = u.dot(v);
            expected_result = 9.0f;
            INFO("Expected result: " << expected_result);
            INFO("Actual result: " << result);        
            REQUIRE(are_close(result, expected_result, tolerance));
        }
    }
}

    /////EX04///////

    TEST_CASE("Vector norms")
    {
        Vector<float, 3> u = {0.0, 0.0, 0.0};
        Vector<float, 3> v = {1.0, 2.0, 3.0};
        Vector<float, 2> w = {-1.0, -2.0};

        SECTION("Manhattan norm (L1 norm)") {
            REQUIRE(are_close(u.norm_one(), 0.0, tolerance));

            REQUIRE(are_close(v.norm_one(), 6.0, tolerance));

            REQUIRE(are_close(w.norm_one(), 3.0, tolerance));
        }

        SECTION("Euclidean norm (L2 norm)") {
            REQUIRE(are_close(u.norm(), 0.0, tolerance));
            REQUIRE(are_close(v.norm(), 3.74165738, tolerance));
            REQUIRE(are_close(w.norm(), 2.236067977, tolerance));
        }

        SECTION("Supremum norm (L∞ norm)") {
            REQUIRE(are_close(u.norm_inf(), 0.0, tolerance));
            REQUIRE(are_close(v.norm_inf(), 3.0, tolerance));
            REQUIRE(are_close(w.norm_inf(), 2.0, tolerance));
            
        }
    }

    /////EX05///////

    TEST_CASE("Vector angle cosine") {
        Vector<float, 2> u, v;
        Vector<float, 3> a, b;

        SECTION("Case 1") {
            u = {1.0, 0.0};
            v = {1.0, 0.0};
            REQUIRE(are_close(angle_cos(u, v), 1.0, 0.01));
        }

        SECTION("Case 2") {
            u = {-1.0, 1.0};
            v = {1.0, 1.0};
            REQUIRE(are_close(angle_cos(u, v), 0.0, 0.01));
        }

        SECTION("Case 3") {
            u = {-1.0, 1.0};
            v = {1.0, -1.0};
            REQUIRE(are_close(angle_cos(u, v), -1.0, 0.01));
        }

        SECTION("Case 4") {
            u = {2.0, 1.0};
            v = {4.0, 2.0};
            REQUIRE(are_close(angle_cos(u, v), 1.0, 0.01));
        }

        SECTION("Case 5") {
            a = {1.0, 2.0, 3.0};
            b = {4.0, 5.0, 6.0};
            REQUIRE(are_close(angle_cos(a, b), 0.974631846, 0.01));
        }
    }

    /////EX06///////

    TEST_CASE("Vector cross product")
    {
        Vector<float, 3> u, v;

        SECTION("Case 1") {
            u = {0.0, 0.0, 1.0};
            v = {1.0, 0.0, 0.0};
            Vector<float, 3> result = cross_product(u, v);
            REQUIRE(are_close(result[0], 0.0, 0.01));
            REQUIRE(are_close(result[1], 1.0, 0.01));
            REQUIRE(are_close(result[2], 0.0, 0.01));
        }

        SECTION("Case 2") {
            u = {1.0, 2.0, 3.0};
            v = {4.0, 5.0, 6.0};
            Vector<float, 3> result = cross_product(u, v);
            REQUIRE(are_close(result[0], -3.0, 0.01));
            REQUIRE(are_close(result[1], 6.0, 0.01));
            REQUIRE(are_close(result[2], -3.0, 0.01));
        }

        SECTION("Case 3") {
            u = {4.0, 2.0, -3.0};
            v = {-2.0, -5.0, 16.0};
            Vector<float, 3> result = cross_product(u, v);
            REQUIRE(are_close(result[0], 17.0, 0.01));
            REQUIRE(are_close(result[1], -58.0, 0.01));
            REQUIRE(are_close(result[2], -16.0, 0.01));
        }
    }

    /////EX07///////

    TEST_CASE("Matrix-vector multiplication") {
        Matrix<float, 2, 2> u;
        Vector<float, 2> v, result;

        SECTION("Case 1") {
            u = {{1.0, 0.0}, {0.0, 1.0}};
            v = {4.0, 2.0};
            result = u.mul_vec(v);
            REQUIRE(are_close(result[0], 4.0, 0.01));
            REQUIRE(are_close(result[1], 2.0, 0.01));
        }

        SECTION("Case 2") {
            u = {{2.0, 0.0}, {0.0, 2.0}};
            v = {4.0, 2.0};
            result = u.mul_vec(v);
            REQUIRE(are_close(result[0], 8.0, 0.01));
            REQUIRE(are_close(result[1], 4.0, 0.01));
        }

        SECTION("Case 3") {
            u = {{2.0, -2.0}, {-2.0, 2.0}};
            v = {4.0, 2.0};
            result = u.mul_vec(v);
            REQUIRE(are_close(result[0], 4.0, 0.01));
            REQUIRE(are_close(result[1], -4.0, 0.01));
        }
    }

    TEST_CASE("Matrix-matrix multiplication") {
        Matrix<float, 2, 2> u, v, result;

        SECTION("Case 1") {
            u = {{1.0, 0.0}, {0.0, 1.0}};
            v = {{1.0, 0.0}, {0.0, 1.0}};
            result = u.mul_mat(v);  
            REQUIRE(are_close(result[0][0], 1.0, 0.01));
            REQUIRE(are_close(result[0][1], 0.0, 0.01));
            REQUIRE(are_close(result[1][0], 0.0, 0.01));
            REQUIRE(are_close(result[1][1], 1.0, 0.01));
        }

        SECTION("Case 2") {
            u = {{1.0, 0.0}, {0.0, 1.0}};
            v = {{2.0, 1.0}, {4.0, 2.0}};
            result = u.mul_mat(v);
 
            REQUIRE(are_close(result[0][0], 2.0, 0.01));
            REQUIRE(are_close(result[0][1], 1.0, 0.01));
            REQUIRE(are_close(result[1][0], 4.0, 0.01));
            REQUIRE(are_close(result[1][1], 2.0, 0.01));
        }

        SECTION("Case 3") {
            u = {{3.0, -5.0}, {6.0, 8.0}};
            v = {{2.0, 1.0}, {4.0, 2.0}};
            result = u.mul_mat(v);
            REQUIRE(are_close(result[0][0], -14.0, 0.01));
            REQUIRE(are_close(result[0][1], -7.0, 0.01));
            REQUIRE(are_close(result[1][0], 44.0, 0.01));
            REQUIRE(are_close(result[1][1], 22.0, 0.01));
        }
    }


    /////EX08///////

    TEST_CASE("Matrix trace calculation")
    {
        SECTION("2x2 Matrix Trace") {
            Matrix<float, 2, 2> u = {{1.0, 0.0}, {0.0, 1.0}};
            float result = u.trace();
            REQUIRE(are_close(result, 2.0, 0.01));
        }

        SECTION("3x3 Matrix Trace - Case 1") {
            Matrix<float, 3, 3> u = {{2.0, -5.0, 0.0}, {4.0, 3.0, 7.0}, {-2.0, 3.0, 4.0}};
            float result = u.trace();
            REQUIRE(are_close(result, 9.0, 0.01));
        }

        SECTION("3x3 Matrix Trace - Case 2") {
            Matrix<float, 3, 3> u = {{-2.0, -8.0, 4.0}, {1.0, -23.0, 4.0}, {0.0, 6.0, 4.0}};
            float result = u.trace();
            REQUIRE(are_close(result, -21.0, 0.01));
        }
    }

    /////EX09///////

    TEST_CASE("Matrix transpose calculation")
    {
        SECTION("2x2 Matrix Transpose") {
            Matrix<float, 2, 2> u = {{1.0, 0.0}, {0.0, 1.0}};
            Matrix<float, 2, 2> v = u.transpose();
            REQUIRE(are_close(v[0][0], 1.0, 0.01));
            REQUIRE(are_close(v[0][1], 0.0, 0.01));
            REQUIRE(are_close(v[1][0], 0.0, 0.01));
            REQUIRE(are_close(v[1][1], 1.0, 0.01));
        }

        SECTION("3x3 Matrix Transpose - Case 1") {
            Matrix<float, 3, 3> u = {{1.0, 1.0, 1.0}, {2.0, 2.0, 2.0}, {3.0, 3.0, 3.0}};
            Matrix<float, 3, 3> v = u.transpose();
            REQUIRE(are_close(v[0][0], 1.0, 0.01));
            REQUIRE(are_close(v[0][1], 2.0, 0.01));
            REQUIRE(are_close(v[0][2], 3.0, 0.01));
            REQUIRE(are_close(v[1][0], 1.0, 0.01));
            REQUIRE(are_close(v[1][1], 2.0, 0.01));
            REQUIRE(are_close(v[1][2], 3.0, 0.01));
            REQUIRE(are_close(v[2][0], 1.0, 0.01));
            REQUIRE(are_close(v[2][1], 2.0, 0.01));
            REQUIRE(are_close(v[2][2], 3.0, 0.01));
        }   
    }

    /////EX11///////
    TEST_CASE("Matrix determinant calculation")
    {
        SECTION("2x2 Matrix Determinant") {
            Matrix<float, 2, 2> u = {{1.0, -1.0}, {-1.0, 1.0}};
            float det = u.determinant();
            REQUIRE(are_close(det, 0.0, 0.01));
        }

        SECTION("3x3 Diagonal Matrix Determinant") {
            Matrix<float, 3, 3> u = {{2.0, 0.0, 0.0}, {0.0, 2.0, 0.0}, {0.0, 0.0, 2.0}};
            float det = u.determinant();
            REQUIRE(are_close(det, 8.0, 0.01));
        }

        SECTION("3x3 General Matrix Determinant") {
            Matrix<float, 3, 3> u = {{8.0, 5.0, -2.0}, {4.0, 7.0, 20.0}, {7.0, 6.0, 1.0}};
            float det = u.determinant();
            REQUIRE(are_close(det, -174.0, 0.01));
        }

        SECTION("4x4 General Matrix Determinant") {
            Matrix<float, 4, 4> u = {{8.0, 5.0, -2.0, 4.0}, {4.0, 2.5, 20.0, 4.0}, {8.0, 5.0, 1.0, 4.0}, {28.0, -4.0, 17.0, 1.0}};
            float det = u.determinant();
            REQUIRE(are_close(det, 1032.0, 0.01));
        }
    }

    /////EX12///////
    TEST_CASE("Matrix inverse calculation")
    {
        SECTION("3x3 Identity Matrix Inverse") {
            Matrix<float, 3, 3> u = {{1.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, {0.0, 0.0, 1.0}};
            Matrix<float, 3, 3> result = u.inverse();
            REQUIRE(are_close(result[0][0], 1.0, 0.01));
            REQUIRE(are_close(result[0][1], 0.0, 0.01));
            REQUIRE(are_close(result[0][2], 0.0, 0.01));
            REQUIRE(are_close(result[1][0], 0.0, 0.01));
            REQUIRE(are_close(result[1][1], 1.0, 0.01));
            REQUIRE(are_close(result[1][2], 0.0, 0.01));
            REQUIRE(are_close(result[2][0], 0.0, 0.01));
            REQUIRE(are_close(result[2][1], 0.0, 0.01));
            REQUIRE(are_close(result[2][2], 1.0, 0.01));
        }

        SECTION("3x3 Diagonal Matrix Inverse") {
            Matrix<float, 3, 3> u = {{2.0, 0.0, 0.0}, {0.0, 2.0, 0.0}, {0.0, 0.0, 2.0}};
            Matrix<float, 3, 3> result = u.inverse();
            REQUIRE(are_close(result[0][0], 0.5, 0.01));
            REQUIRE(are_close(result[0][1], 0.0, 0.01));
            REQUIRE(are_close(result[0][2], 0.0, 0.01));
            REQUIRE(are_close(result[1][0], 0.0, 0.01));
            REQUIRE(are_close(result[1][1], 0.5, 0.01));
            REQUIRE(are_close(result[1][2], 0.0, 0.01));
            REQUIRE(are_close(result[2][0], 0.0, 0.01));
            REQUIRE(are_close(result[2][1], 0.0, 0.01));
            REQUIRE(are_close(result[2][2], 0.5, 0.01));
        }

        SECTION("3x3 General Matrix Inverse") {
            Matrix<float, 3, 3> u = {{8.0, 5.0, -2.0}, {4.0, 7.0, 20.0}, {7.0, 6.0, 1.0}};
            Matrix<float, 3, 3> result = u.inverse();
            REQUIRE(are_close(result[0][0], 0.649425287, 0.01));
            REQUIRE(are_close(result[0][1], 0.097701149, 0.01));
            REQUIRE(are_close(result[0][2], -0.655172414, 0.01));
            REQUIRE(are_close(result[1][0], -0.781609195, 0.01));
            REQUIRE(are_close(result[1][1], -0.126436782, 0.01));
            REQUIRE(are_close(result[1][2], 0.965517241, 0.01));
            REQUIRE(are_close(result[2][0], 0.143678161, 0.01));
            REQUIRE(are_close(result[2][1], 0.074712644, 0.01));
            REQUIRE(are_close(result[2][2], -0.206896552, 0.01));
        }
    }


    /////EX12///////

    TEST_CASE("Matrix rank calculation")
    {
        SECTION("Test 1: 3x3 Identity Matrix Rank") {
            Matrix<float, 3, 3> u = {{1.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, {0.0, 0.0, 1.0}};
            int result = u.rank();
            REQUIRE(result == 3);
        }

        SECTION("Test 2: 3x4 Matrix Rank") {
            Matrix<float, 3, 4> u = {{1.0, 2.0, 0.0, 0.0}, {2.0, 4.0, 0.0, 0.0}, {-1.0, 2.0, 1.0, 1.0}};
            int result = u.rank();
            REQUIRE(result == 2);
        }

        SECTION("Test 3: 4x3 Matrix Rank") {
            Matrix<float, 4, 3> u = {{8.0, 5.0, -2.0}, {4.0, 7.0, 20.0}, {7.0, 6.0, 1.0}, {21.0, 18.0, 7.0}};
            int result = u.rank();
            REQUIRE(result == 3);
        }
    }
