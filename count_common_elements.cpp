#include <vector>
#include <unordered_set>

// function returns amount of common elements in two std::vectors
// a, b - vectors
unsigned count_common_elements(std::vector<int> &a, std::vector<int> &b) {
    std::unordered_set<int> uset;
    size_t n = a.size(), m = b.size();
    unsigned common = 0; // amount of common elements, the answer
    bool array_swap_done = false;

    // we put smaller array to set, in order to use less memory
    if (n > m) {
        std::swap(a, b), std::swap(n, m);
        array_swap_done = true;
    }
    for (size_t i = 0; i < n; ++i) {
        uset.insert(a[i]);
    }
    for (size_t i = 0; i < m; ++i) {
        if (uset.find(b[i]) != uset.end()) // if one more common element found,
            common++;                      // increment the answer
    }
    // we have to revert the changes, in order to keep function's invariant
    if (array_swap_done) {
        swap(a, b);
    }
    return common;
}