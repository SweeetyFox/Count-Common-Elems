#include <vector>
#include <unordered_set>

// function returns amount of common elements in two std::vectors
// a, b - vectors
unsigned count_common_elements(const std::vector<int> &a, const std::vector<int> &b) {
    unsigned common = 0; // amount of common elements, the answer
    std::unordered_set<int> uset;
    size_t n = a.size(), m = b.size();

    // we put smaller array to set, in order to use less memory
    // I can't swap constant arrays directly, so I use 'pointers'
    auto a_pointer = a.begin();
    auto b_pointer = b.begin();
    if (n > m) {
        std::swap(a_pointer, b_pointer);
        std::swap(n, m);
    }

    for (size_t i = 0; i < n; ++i) {
        uset.insert(*(a_pointer++));
    }
    for (size_t i = 0; i < m; ++i) {
        if (uset.find(*(b_pointer++)) != uset.end()) // if one more common element found,
            common++;                                // increment the answer
    }
    return common;
}