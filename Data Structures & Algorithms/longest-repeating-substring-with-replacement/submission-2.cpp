class Solution {
public:
    int characterReplacement(string s, int k) {
        if (s.empty()) return 0;

        unordered_map<char, int> f;
        int maxF = 0;

        int l = 0;
        int ans = 0;
        
        for (int r = 0; r < s.size(); ++r) {
            ++f[s[r]];
            maxF = max(maxF, f[s[r]]);

            while (l < s.size() && r - l + 1 > maxF + k) {
                --f[s[l]];
                ++l;
            }

            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};
