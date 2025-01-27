#include <algorithm>
#include <unordered_map>

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        std::vector<int> v = score;
        std::sort(v.begin(), v.end(), std::greater<int>());

        std::unordered_map<int, std::string> lookup;

        for (int i = 0; i < v.size(); i++) {
            if (i == 0) {
                lookup[v[i]] = "Gold Medal";
                continue;
            }
            if (i == 1) {
                lookup[v[i]] = "Silver Medal";
                continue;
            }
            if (i == 2) {
                lookup[v[i]] = "Bronze Medal";
                continue;
            }
            lookup[v[i]] = std::to_string(i + 1);
        }

        std::vector<std::string> res;

        for (int i = 0; i < score.size(); i++) {
            res.push_back(lookup[score[i]]);
        }

        return res;

    }
};
