# Matrix/Vector Math Library

## Overview

This project is a comprehensive matrix/vector mathematics library implemented as part of a linear algebra learning module. The library provides a wide range of functionalities to perform operations on vectors and matrices, with a focus on efficiency and accuracy. This library is designed to be used in various mathematical computations, graphics processing, and machine learning applications.

## Features

### Basic Operations

- **Addition and Subtraction**: Support for element-wise addition and subtraction of vectors and matrices.
- **Scaling**: Multiplication of vectors and matrices by a scalar value.
- **Dot Product**: Calculation of the dot product of two vectors.
- **Cross Product**: Computation of the cross product of two 3D vectors.

### Advanced Operations

- **Linear Combination**: Combination of multiple vectors using scalar coefficients.
- **Linear Interpolation**: Interpolating between two vectors or matrices.
- **Norm**: Calculation of vector norms (e.g., Euclidean norm).
- **Cosine Similarity**: Computation of the cosine similarity between two vectors.

### Matrix-Specific Operations

- **Matrix Multiplication**: Support for matrix-vector and matrix-matrix multiplication.
- **Trace**: Calculation of the trace of a square matrix.
- **Transpose**: Transposition of matrices.
- **Row-Echelon Form**: Conversion of matrices to row-echelon form.
- **Determinant**: Calculation of the determinant of square matrices.
- **Inverse**: Computation of the inverse of invertible matrices.
- **Rank**: Determination of the rank of a matrix.

## Requirements

To implement the library, the following requirements must be met:

- **Generic Types**: The programming language must support generic types to handle various numerical types.
- **First-Class Functions**: The language must support functions as first-class citizens, allowing for higher-order functions and lambda expressions.
- **Optional**: Support for operator overloading is recommended but not mandatory.

## Constraints

- **No Mathematical Libraries**: You are not allowed to use any external mathematical libraries, including those in the standard library of your language, unless explicitly permitted.
- **Complexity Considerations**: Time and space complexities must be calculated for each function and must be efficient relative to the size of the input data.
