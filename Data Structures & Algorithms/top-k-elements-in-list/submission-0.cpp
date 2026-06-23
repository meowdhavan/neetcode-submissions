class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>> pq;

        unordered_map<int, int> f;

        for (int e : nums) {
            ++f[e];
        }

        for (auto &[k, v] : f) {
            pq.push({v, k});
        }

        vector<int> ans;

        for (int i = 0; i < k; ++i) {
            auto &[_, n] = pq.top();
            ans.push_back(n);
            
            pq.pop();
        }

        return ans;
    }
};
