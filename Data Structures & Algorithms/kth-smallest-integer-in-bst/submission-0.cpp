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
    int _k, cur = 0;
    int ans = -1;

    void dfs(TreeNode *root) {
        if (root == nullptr) return;

        dfs(root->left);

        ++cur;
        if (ans == -1 && cur == _k) {
            ans = root->val;
        }

        dfs(root->right);
    }

    int kthSmallest(TreeNode* root, int k) {
        _k = k;
        dfs(root);
        return ans;
    }
};
