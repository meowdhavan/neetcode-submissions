class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> res;

        for (string s : strs) {
            vector<int> f(26);
            for (char c : s) ++f[c - 'a'];

            string k;
            for (int i = 0; i < 26; ++i) {
                k += to_string(f[i]) + ":";
            }

            res[k].push_back(s);
        }

        vector<vector<string>> ans;

        for (auto &[k, v] : res) {
            ans.push_back(v);
        }

        return ans;
    }
};
