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
    bool validate(TreeNode* root, int mn, int mx) {
        if (root == nullptr) return true;
        if (mn >= root->val || root->val >= mx) return false;

        bool leftOk = validate(root->left, mn, min(mx, root->val));
        bool rightOk = validate(root->right, max(mn, root->val), mx);

        return leftOk && rightOk;
    }

    bool isValidBST(TreeNode* root) {
        return validate(root, INT_MIN, INT_MAX);
    }
};
