class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

        unordered_map<int, int> f;

        for (int e : nums) {
            ++f[e];
        }

        for (auto &[num, freq] : f) {
            pq.push({freq, num});

            if (pq.size() > k) pq.pop();
        }

        vector<int> ans;

        while (!pq.empty()) {
            auto &[_, num] = pq.top();
            ans.push_back(num);

            pq.pop();
        }

        return ans;
    }
};
