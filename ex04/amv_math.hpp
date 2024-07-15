
#include <vector>

#include <iostream>

/*
Linear interpolation (lerp) is a method to find a point along the line between two points,
 based on a parameter 𝑡 t that ranges from 0 to 1.

Formula:
lerp( 𝑢 , 𝑣 , 𝑡 ) = 𝑢 + 𝑡 × ( 𝑣 − 𝑢)
lerp(u,v,t)=u+t×(v−u)

Lerp is widely used due to its simplicity and efficiency in creating smooth transitions and 
interpolations across various fields and applications. Whether it's moving objects in a game,
blending colors in a graphic design tool, or filling in missing data points, 
lerp provides a straightforward solution.
*/

template <typename T>
void printVector(const std::vector<T>& vec)
{
    std::cout << "[";
    for (size_t i = 0; i < vec.size(); ++i)
    {
        std::cout << vec[i];
        if (i < vec.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;
}


