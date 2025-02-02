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
    vector<int> inorderTraversal(TreeNode* root) {
       std::vector<int> traversal;
       driver(root, traversal);
       return traversal;
    }

    void driver(TreeNode* node, std::vector<int>& t) {
        if (node == nullptr) { return; }
        driver(node->left, t);
        t.push_back(node->val);
        driver(node->right, t);
    }
};
