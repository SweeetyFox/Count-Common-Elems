#include <vector>
#include <unordered_set>

// function returns amount of common elements in two std::vectors
// a, b - vectors
unsigned count_common_elements(std::vector<int> const &a, std::vector<int> const &b) {
    unsigned common = 0; // amount of common elements, the answer
    std::unordered_set<int> uset;
    size_t n = a.size(), m = b.size();

    // we put smaller array to set, in order to use less memory
    // constant arrays cannot be swapped directly, so we use iterators
    auto a_iterator = a.begin();
    auto b_iterator = b.begin();
    if (n > m) {
        std::swap(a_iterator, b_iterator);
        std::swap(n, m);
    }

    for (size_t i = 0; i != n; ++i) {
        uset.insert(*(a_iterator++));
    }
    for (size_t i = 0; i != m; ++i) {
        if (uset.find(*(b_iterator++)) != uset.end()) // if one more common element found,
            ++common;                                 // increment the answer
    }
    return common;
}