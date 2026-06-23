class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) return 0;

        unordered_set<char> seen;
        int l = 0, r = 0;

        int ans = 1;
        seen.insert(s[0]);

        while (l < s.size()) {
            if (r < s.size() - 1 && !seen.contains(s[r + 1])) {
                ++r;
                seen.insert(s[r]);
            } else {
                ++l;
                seen.erase(s[l - 1]);
            }

            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};
