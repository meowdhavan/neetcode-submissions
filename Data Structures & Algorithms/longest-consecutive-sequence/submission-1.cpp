class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> seen;
        for (int e : nums) seen.insert(e);

        int ans = 0;

        for (int e : nums) {
            if (seen.contains(e - 1)) continue;

            int cur = 1;

            while (seen.contains(e + cur)) ++cur;
            ans = max(ans, cur);
        }

        return ans;
    }
};
