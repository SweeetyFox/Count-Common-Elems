#include <algorithm>
#include <vector>
#include <random>
#include <unordered_set>
#include "gtest.h"

unsigned count_common_elements(std::vector<int> &a, std::vector<int> &b);

// function 'transfers' r-value vectors from tests to l-value vectors for count_common_elements
unsigned count(std::vector<int> a, std::vector<int> b) {
    return count_common_elements(a, b);
}

// function returns two random std::vectors and amount of common elements
// a, b - vectors
// common - amount of common elements
// array_size - maximum vector's size
void generate_random_vectors(std::vector<int> &a, std::vector<int> &b, size_t &common, int array_size) {
    std::mt19937 int_random(static_cast<unsigned int>(time(0)));
    std::unordered_set<int> st;

    auto betw_random = std::bind(std::uniform_int_distribution<int>(0, array_size / 2), int_random);

    common = betw_random();
    unsigned not_common_a = betw_random(), not_common_b = betw_random();

    for (size_t i = 0; i < common; ++i) {
        int x;
        do {
            x = int_random();
        } while (st.find(x) != st.end());
        st.insert(x);

        a.push_back(x);
        b.push_back(x);
    }

    for (size_t i = 0; i < not_common_a; ++i) {
        int x;
        do {
            x = int_random();
        } while (st.find(x) != st.end());
        st.insert(x);

        a.push_back(x);
    }

    for (size_t i = 0; i < not_common_b; ++i) {
        int x;
        do {
            x = int_random();
        } while (st.find(x) != st.end());
        st.insert(x);

        b.push_back(x);
    }

    std::shuffle(std::begin(a), std::end(a), int_random);
    std::shuffle(std::begin(b), std::end(b), int_random);
}

TEST(hand_made_tests, extreme_cases)
{
    EXPECT_TRUE(count({}, {}) == 0);
    EXPECT_TRUE(count({INT32_MAX}, {INT32_MAX}) == 1);
    EXPECT_TRUE(count({INT32_MIN}, {INT32_MIN}) == 1);
    EXPECT_TRUE(count({INT32_MAX}, {INT32_MIN}) == 0);
    EXPECT_TRUE(count({INT32_MIN}, {INT32_MAX}) == 0);
    EXPECT_TRUE(count({INT32_MIN}, {}) == 0);
    EXPECT_TRUE(count({INT32_MAX}, {}) == 0);
    EXPECT_TRUE(count({}, {INT32_MIN}) == 0);
    EXPECT_TRUE(count({}, {INT32_MAX}) == 0);
}

TEST(hand_made_tests, tricky_cases)
{
    EXPECT_TRUE(count({239}, {239}) == 1);
    EXPECT_TRUE(count({-239}, {239}) == 0);
    EXPECT_TRUE(count({0}, {-0}) == 1);
    EXPECT_TRUE(count({42}, {239}) == 0);
    EXPECT_TRUE(count({}, {239}) == 0);
    EXPECT_TRUE(count({239}, {}) == 0);
}

const size_t EASY = 10;     // amount of tests to be generated,
const size_t MEDIUM = 1000; // more tests - harder to pass
const size_t HARD = 100000;

const int SMALL = 10;       // maximum arrays size
const int AVERAGE = 1000;   // more elements - harder to pass
const int BIG = 100000;

//
//  random tests with small arrays
//
TEST(random_tests, small_arrays_cases_easy)
{
    size_t common;
    for (int i = 0; i < EASY; ++i) {
        std::vector<int> a, b;
        generate_random_vectors(a, b, common, SMALL);

        EXPECT_TRUE(count({a}, {b}) == common);
    }
}

TEST(random_tests, small_arrays_cases_medium)
{
    size_t common;
    for (int i = 0; i < MEDIUM; ++i) {
        std::vector<int> a, b;
        generate_random_vectors(a, b, common, SMALL);

        EXPECT_TRUE(count({a}, {b}) == common);
    }
}

TEST(random_tests, small_arrays_cases_hard)
{
    size_t common;
    for (int i = 0; i < HARD; ++i) {
        std::vector<int> a, b;
        generate_random_vectors(a, b, common, SMALL);

        EXPECT_TRUE(count({a}, {b}) == common);
    }
}

//
//  random tests with average arrays
//
TEST(random_tests, average_arrays_cases_easy)
{
    size_t common;
    for (int i = 0; i < EASY; ++i) {
        std::vector<int> a, b;
        generate_random_vectors(a, b, common, AVERAGE);

        EXPECT_TRUE(count({a}, {b}) == common);
    }
}

TEST(random_tests, average_arrays_cases_medium)
{
    size_t common;
    for (int i = 0; i < MEDIUM; ++i) {
        std::vector<int> a, b;
        generate_random_vectors(a, b, common, AVERAGE);

        EXPECT_TRUE(count({a}, {b}) == common);
    }
}

//
//  random tests with big arrays
//
TEST(random_tests, big_arrays_cases_easy)
{
    size_t common;
    for (int i = 0; i < EASY; ++i) {
        std::vector<int> a, b;
        generate_random_vectors(a, b, common, BIG);

        EXPECT_TRUE(count({a}, {b}) == common);
    }
}

//
//  ! ACHTUNG !
//
//  These two tests are huge, so run them only under release mode.
//  To change debug mode on release (OS X), please follow these steps:
//  (Settings -> Build, Execution, Deployment -> CMake) and change Debug on Release.
//
//  On my computer these two tests took: ~34.313 ms & ~38.439 ms
//        all other tests together took: ~2.932 ms
//                             in total: ~75.684 ms
//

//TEST(random_tests, average_arrays_cases_HARD)
//{
//    size_t common;
//    for (int i = 0; i < HARD; ++i) {
//        std::vector<int> a, b;
//        generate_random_vectors(a, b, common, AVERAGE);
//
//        EXPECT_TRUE(count({a}, {b}) == common);
//    }
//}
//
//TEST(random_tests, big_arrays_cases_medium)
//{
//    size_t common;
//    for (int i = 0; i < MEDIUM; ++i) {
//        std::vector<int> a, b;
//        generate_random_vectors(a, b, common, BIG);
//
//        EXPECT_TRUE(count({a}, {b}) == common);
//    }
//}