#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> reconstructMatrix(int upper, int lower, std::vector<int>& colsum) {
        const int colzise = colsum.size();
        std::vector<std::vector<int>> result(2, std::vector<int>(colzise, 0));

        int up = upper, low = lower;

        for (int i = 0; i < colzise; i++) {
            if (colsum[i] == 2) {
                result[0][i] = 1;
                result[1][i] = 1;
                up--; low--;
            } else if (colsum[i] == 1) {
                if (up > low) {
                    result[0][i] = 1;
                    up--;
                } else {
                    result[1][i] = 1;
                    low--;
                }
            }
        }

        if (up == 0 && low == 0) {
            return result;
        }

        return {};
    }
};

int main() {
    return 0;
}
