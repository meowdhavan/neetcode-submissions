class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> exists;
        int ans = 0;

        for (int e : nums) {
            exists.insert(e);
        }

        for (int e : nums) {
            if (exists.contains(e - 1)) continue;

            int cur = e;
            while (exists.contains(cur + 1)) ++cur;

            ans = max(ans, cur - e + 1);
        }

        return ans;
    }
};
