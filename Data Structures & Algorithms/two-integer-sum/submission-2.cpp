class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> a(nums.size());
        for (int i = 0; i < nums.size(); ++i) {
            a[i] = {nums[i], i};
        }

        sort(a.begin(), a.end());

        int l = 0, r = a.size() - 1;

        while (l < r) {
            int cur = a[l].first + a[r].first;

            if (cur == target) {
                vector<int> ans = {a[l].second, a[r].second};
                if (ans[0] > ans[1]) {
                    swap(ans[0], ans[1]);
                }
                return ans;
            } else if (cur > target) --r;
            else ++l;
        }

        return {-1, -1};
    }
};
