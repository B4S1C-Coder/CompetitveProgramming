/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void dfsWithPathSumCalc(TreeNode* root, int curSum, std::vector<int>& pathSums) {
        if (!root) { return; }
        curSum += root->val;

        // If leaf node -> sum in pathSums
        if (!root->left && !root->right) {
            pathSums.push_back(curSum);
            return;
        }

        // If not leaf node -> go to left & right sub trees
        dfsWithPathSumCalc(root->left, curSum, pathSums);
        dfsWithPathSumCalc(root->right, curSum, pathSums);
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        std::vector<int> pathSums;
        dfsWithPathSumCalc(root, 0, pathSums);

        return (std::find(pathSums.begin(), pathSums.end(), targetSum) != pathSums.end());
    }
};
