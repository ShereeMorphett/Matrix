#include <iostream>
#include <vector>
#include "Vector.hpp"

int main() {
    // Define some vectors
    Vector<double> e1({1.0, 0.0, 0.0});
    Vector<double> e2({0.0, 1.0, 0.0});
    Vector<double> e3({0.0, 0.0, 1.0});

    // Define coefficients
    std::vector<Vector<double>> vectors = {e1, e2, e3};
    std::vector<double> coefs = {10.0, -2.0, 0.5};

    std::vector<double> vec1 = {1.0, 2.0, 3};
    std::vector<double> vec2 = {0.0, 10.0, -100.0};
    std::vector<double> coefs2 = {10.0, -2.0};
    std::vector<Vector<double>> vectors2 = {vec1, vec2};

    Vector<double> result = Vector<double>::linear_combination(vectors, coefs);
    std::cout << result << std::endl;

    result = Vector<double>::linear_combination(vectors2, coefs2);
    std::cout << result << std::endl;

    return 0;
}
