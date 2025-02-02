#include <cmath>
#include <algorithm>

class Solution {
public:
    std::vector<int> findClosestElements(std::vector<int>& arr, int k, int x) {

        // Sort the array based on distance from x
        std::stable_sort(arr.begin(), arr.end(), [x](const int& a, const int& b) -> bool {
            return std::abs(a - x) < std::abs(b - x);
        });

        // We only need the first k elements
        arr.resize(k);

        // Asceding order of the k elements
        std::sort(arr.begin(), arr.end());

        return arr;
    }
};
