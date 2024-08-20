
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Weverything"
#endif

#include <catch2/catch_test_macros.hpp> ///////

#ifdef __clang__
#pragma clang diagnostic pop
#endif

#include <cmath>  // For std::fabs
#include <limits> // For std::numeric_limits

// Custom assertion for floating-point comparison
bool approx_equal(double a, double b, double tol)
{
    return std::fabs(a - b) < tol;
}

#define CHECK_APPROX_EQUAL_EPS(actual_, expected_, eps_)                         \
    do                                                                           \
    {                                                                            \
        const auto cae_expected = static_cast<double>(expected_);                \
        INFO("expected: " << cae_expected << "    " << #expected_);              \
                                                                                 \
        const auto cae_actual = static_cast<double>(actual_);                    \
        INFO("  actual: " << cae_actual << "    " << #actual_);                  \
                                                                                 \
        const auto cae_eps = static_cast<double>(eps_);                          \
        INFO(" epsilon: " << cae_eps);                                         \
                                                                                                                       \
        CHECK(approx_equal(cae_expected, cae_actual, cae_eps));                \
    } while (false)

#define CHECK_APPROX_EQUAL(actual_, expected_) CHECK_APPROX_EQUAL_EPS(actual_, expected_, 0.0001)

// this is ignoring all clang warnings ONLY from catch2
