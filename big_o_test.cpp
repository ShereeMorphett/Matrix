#include <iostream>
#include <chrono>



//https://www.geeksforgeeks.org/analysis-algorithms-big-o-analysis/


// Function to measure
void vector_add(std::vector<int>& v1, std::vector<int>& v2)
{
    std::vector<int> result;
    for (size_t i = 0; i < v1.size(); ++i) {
        result.push_back(v1[i] + v2[i]);
    }
}

int main() {
    std::vector<int> v1(1000, 1);
    std::vector<int> v2(1000, 2);

    auto start = std::chrono::high_resolution_clock::now();

    // Call function multiple times to get a stable average time
    for (int i = 0; i < 1000; ++i) {
        vector_add(v1, v2);
    }

    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> elapsed_seconds = end - start;
    double elapsed_time = elapsed_seconds.count() / 1000;  // Average time per call

    std::cout << "Average execution time: " << elapsed_time << " seconds" << std::endl;

    return 0;
}
