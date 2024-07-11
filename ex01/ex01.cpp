#include "Vector.hpp"
#include "Matrix.hpp"
#include "colours.hpp"
#include <stdexcept>
#include <iostream>

/*Linear combinations are fundamental operations in various fields of science, engineering, and computer science. They are used to solve numerous real-world problems. 

Here are some common use cases for linear combinations in programming:

1. Computer Graphics and Image Processing
Transformation of Coordinates: Linear combinations are used to transform coordinates of points in space. This is essential in 3D graphics for translating, scaling, and rotating objects.
Blending and Interpolation: Linear combinations are used to interpolate between colors or shapes, creating smooth transitions in animations or blending images.

2. Machine Learning and Data Science
Linear Regression: Linear combinations are at the core of linear regression models, where the goal is to find the best-fit line for a set of data points.
Feature Engineering: Combining different features linearly to create new features that might be more predictive or useful for a model.
Neural Networks: The weighted sum (linear combination) of inputs is calculated at each neuron in a neural network.

3. Signal Processing
Filtering: Linear combinations of signal samples are used in the design of filters that can remove noise or extract certain features from a signal.
Fourier Transforms: Decomposing a signal into its constituent frequencies involves linear combinations.

4. Physics and Engineering
Solving Systems of Linear Equations: Linear combinations are used to solve systems of linear equations, which are common in engineering for modeling physical systems.
Mechanics: Calculating the resultant of multiple forces acting on a body involves taking the linear combination of vectors representing the forces.

5. Economics and Finance
Portfolio Management: In finance, a portfolio is a linear combination of different assets. The goal is often to find the optimal combination that maximizes return while minimizing risk.
Cost Functions: Linear combinations are used in defining and optimizing cost functions.

6. Robotics
Motion Planning: Calculating the trajectory of a robot involves linear combinations of vectors to determine the path and movement.
Control Systems: Linear control systems often use linear combinations of state variables to design controllers that maintain desired performance.

Explanation of the Example
Points in Space: pointA and pointB represent two points in 3D space.
Interpolation Factor: t is the interpolation factor. When t is 0.5, it calculates the midpoint. When t is 0, it returns pointA, and when t is 1, it returns pointB.
Linear Combination: The interpolated point is calculated as a linear combination of pointA and pointB.
This simple example demonstrates how linear combinations can be used in computer graphics to interpolate between points, a common operation in animations and modeling.

https://en.wikipedia.org/wiki/Linear_combination

https://www.youtube.com/watch?v=WJlQzgS_itI



*/


int main() {
    // Define some vectors
    Vector<double> v1({1.0, 2.0, 3.0});
    Vector<double> v2({4.0, 5.0, 6.0});
    Vector<double> v3({7.0, 8.0, 9.0});

    // Define coefficients
    Vector<double> coefs = {0.5, 1.5, -1.0};

    // Collect vectors into a vector
    Vector<Vector<double>> vectors = {v1, v2, v3};

    try {
        // Calculate the linear combination
        Vector<double> result = Vector<double>::linear_combination(vectors, coefs);

        // Display the result
        std::cout << FGRN("\nLinear combination result: \n") << std::endl;
        std::cout << result << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
