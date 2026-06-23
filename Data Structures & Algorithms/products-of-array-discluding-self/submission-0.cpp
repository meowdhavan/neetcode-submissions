class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector<int> ans(n);

        long long int mul = 1;
        int zeroCnt = 0;
        for (int e : nums) {
            if (e == 0) ++zeroCnt;
            else mul *= e;
        }

        if (zeroCnt >= 2) return ans;

        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                ans[i] = mul;
            } else {
                ans[i] = (zeroCnt == 1 ? 0 : mul / nums[i]);
            }
        }

        return ans;
    }
};
