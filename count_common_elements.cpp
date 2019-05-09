#include <vector>
#include <unordered_set>

unsigned count_common_elements(std::vector<int> a, std::vector<int> b) {
    std::unordered_set<int> uset;
    size_t n = a.size(), m = b.size();
    unsigned cnt = 0;

    // we put the smaller array to set, in order to use less memory
    if (n < m) {
        for (size_t i = 0; i < n; ++i) {
            uset.insert(a[i]);
        }

        for (size_t i = 0; i < m; ++i) {
            if (uset.find(b[i]) != uset.end()) // if one more common element found,
                cnt++;                         // increment the answer
        }
    } else {
        for (size_t i = 0; i < m; ++i) {
            uset.insert(b[i]);
        }

        for (size_t i = 0; i < n; ++i) {
            if (uset.find(a[i]) != uset.end())
                cnt++;
        }
    }

    return cnt;
}