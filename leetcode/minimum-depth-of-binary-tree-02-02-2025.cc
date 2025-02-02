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

#include <queue>
#include <utility>

class Solution {
public:

    // Breadth First Search
    int minDepth(TreeNode* root) {
        if (!root) { return 0; }

        std::queue<std::pair<TreeNode*, int>> bfsQ;
        bfsQ.push({root, 1});

        while (!bfsQ.empty()) {
            TreeNode* node = bfsQ.front().first;
            int depth = bfsQ.front().second;

            bfsQ.pop();

            // If leaf node, return depth
            if (!node->left && !node->right) { return depth; }

            if (node->left) { bfsQ.push({ node->left, depth + 1 }); }
            if (node->right) { bfsQ.push({ node->right, depth + 1 }); }
        }

        return 0;
    }
};
