#include <vector>
#include <stack>

class Solution {
public:
    std::vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> traversal;
        std::stack<TreeNode*> stk;
        TreeNode* curr = root;

        while (curr != nullptr || !stk.empty()) {
            // Go to the leftmost node
            while (curr != nullptr) {
                stk.push(curr);
                curr = curr->left;
            }
            
            // Process the top node
            curr = stk.top();
            stk.pop();
            traversal.push_back(curr->val);

            // Move to the right subtree
            curr = curr->right;
        }

        return traversal;
    }
};

