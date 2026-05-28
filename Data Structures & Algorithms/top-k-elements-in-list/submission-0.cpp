class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        auto cmp = [](pair<int, int> a, pair<int, int> b){
            return a.second > b.second;
        };
        for (int n : nums)
            mp[n]++;
        priority_queue<pair<int, int>, 
            vector<pair<int, int>>, 
            decltype(cmp)> pq;
        for (auto m : mp) {
            pq.push(m);
            if (pq.size() > k)
                pq.pop();
        }
        vector<int> res;
        while (!pq.empty()) {
            res.push_back(pq.top().first);
            pq.pop();
        }
        return res;
    }
};
