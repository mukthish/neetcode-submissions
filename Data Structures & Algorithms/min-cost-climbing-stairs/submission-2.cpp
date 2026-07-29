class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        // vector<int> res = {cost[0], cost[1]};
        vector<int> res(2);
        for (int i = 2; i <= n; i++) {
            res[0] = min(res[0] + cost[i-2], res[1] + cost[i-1]);
            swap(res[0], res[1]);
        }
        return min(res[0] + cost[n-1], res[1]);
    }
};
