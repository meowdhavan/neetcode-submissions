class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int curMin = prices[0];
        int ans = 0;

        for (int e : prices) {
            curMin = min(curMin, e);
            ans = max(ans, e - curMin);
        }

        return ans;
    }
};
