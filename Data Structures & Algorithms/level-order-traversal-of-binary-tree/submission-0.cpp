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
    unordered_map<int, vector<int>> res;

    void dfs(TreeNode *root, int depth) {
        if (root == nullptr) return;

        res[depth].push_back(root->val);

        dfs(root->left, depth + 1);
        dfs(root->right, depth + 1);
    }
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        res.clear();
        dfs(root, 0);

        vector<vector<int>> ans(res.size());

        for (int i = 0; i < res.size(); ++i) {
            ans[i] = res[i];
        }

        return ans;
    }
};
