class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0];
        int curMax = 1;
        int curMin = 1;
        for (auto &n : nums) {
            int temp = curMax * n;
            curMax = max(max(n * curMax, n * curMin), n);
            curMin = min(min(temp, n * curMin), n);
            res = max(res, curMax);
        }
        return res;
    }
};
