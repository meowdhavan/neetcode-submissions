class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) return 0;

        unordered_set<char> seen = {s[0]};
        int l = 0, r = 0;
        int ans = 1;

        while (l < s.size()) {
            if (r < s.size() - 1 && !seen.contains(s[r + 1])) {
                ++r;
                seen.insert(s[r]);
            } else {
                seen.erase(s[l]);
                ++l;
            }

            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};
