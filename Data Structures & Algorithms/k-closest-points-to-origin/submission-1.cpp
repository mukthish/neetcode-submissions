class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<float, vector<int>>> pq;
        for (auto& p : points) {
            pq.push({sqrt(p[0]*p[0] + p[1]*p[1]), p});
            if (pq.size() > k) {
                pq.pop();
            }
        }
        vector<vector<int>> res;
        while (!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};
