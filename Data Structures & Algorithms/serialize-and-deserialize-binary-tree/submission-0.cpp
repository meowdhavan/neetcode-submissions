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

class Codec {
    pair<string, string> findSubs(string s) {
        int depth = 0;

        string first, second;

        int start = 0;

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '[') {
                ++depth;
            } else if (s[i] == ']') {
                --depth;

                if (depth == 0) {
                    if (start == 0) first = s.substr(start, i - start + 1);
                    else second = s.substr(start, i - start + 1);

                    start = i + 1;
                }
            }
        }

        return {first, second};
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr) return "[]";

        string ans = "[";
        ans += to_string(root->val);
        ans += serialize(root->left);
        ans += serialize(root->right);
        ans += "]";

        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "[]") return nullptr;

        string curVal;

        int i = 1;
        while (i < data.size() && data[i] != '[') {
            curVal += data[i];
            ++i;
        }

        string remaining = data.substr(i, data.size() - i);
        auto [left, right] = findSubs(remaining);

        TreeNode *curNode = new TreeNode(stoi(curVal), deserialize(left), deserialize(right));

        return curNode;
    }
};
