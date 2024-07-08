/*Fused Multiply-Add
It computes the value x * y + z with an exact double-length product,
followed by an addition with a single rounding. 
Numerical computation often needs pairs of multiply and add operations,
for which the FMA is well-suited */


#include "Vector.hpp"
#include "Matrix.hpp"
#include "colours.hpp"

/*You must write a function that computes a linear combination of the vectors provided,
using the corresponding scalar coefficients.

You must also turn in a main function in order to test your function, ready to be
compiled (if necessary) and run.

• Let u = (u1, ..., uk) ∈ V
k be a list of size k, containing vectors (V is a vector space).
• Let λ = (λ1, ..., λk) ∈ Kk be a list of size k, containing scalars.
You must calculate the linear combination of the vectors of u scaled by their respective
coefficients in λ.
If the two arrays provided as input are not of the same size, or if the array’s contents
are incoherent, the result is undefined.
The prototype of the function to write is the following:

fn linear_combination::<K>(u: &[Vector<K>], coefs: &[K]) -> Vector<K>;

*/


int main() {
    // Define some vectors
    Vector<double> v1({1.0, 2.0, 3.0});
    Vector<double> v2({4.0, 5.0, 6.0});
    Vector<double> v3({7.0, 8.0, 9.0});

    // Define coefficients
    std::vector<double> coefs = {0.5, 1.5, -1.0};

    // Collect vectors into a vector
    std::vector<Vector<double>> vectors = {v1, v2, v3};

    try {
        // Calculate the linear combination
        Vector<double> result = linear_combination(vectors, coefs);

        // Display the result
        std::cout <<  FGRN("\nLinear combination result: \n") << std::endl;
        std::cout << result << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}