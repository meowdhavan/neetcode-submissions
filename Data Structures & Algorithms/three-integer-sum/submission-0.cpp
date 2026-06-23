class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;

        for (int i = 0; i < nums.size() - 1; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int l = i + 1;
            int r = nums.size() - 1;

            while (l < r) {
                int curSum = nums[i] + nums[l] + nums[r];

                if (curSum == 0) {
                    ans.push_back({nums[i], nums[l], nums[r]});

                    --r;
                    while (r > 0 && nums[r] == nums[r + 1]) --r;

                    ++l;
                    while (l < nums.size() && nums[l] == nums[l - 1]) ++l;
                } else if (curSum > 0) {
                    --r;
                } else {
                    ++l;
                }
            }
        }

        return ans;
    }
};
