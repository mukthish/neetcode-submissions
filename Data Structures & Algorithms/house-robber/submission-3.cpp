class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }
        vector<int> dp(2);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < n; i++) {
            int temp = dp[1];
            dp[1] = max(dp[1], dp[0] + nums[i]);
            dp[0] = temp;
        }
        return dp[1];
    }
};
