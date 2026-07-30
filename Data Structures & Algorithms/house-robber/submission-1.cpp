class Solution {
    int backtrack(vector<int>& nums, vector<int>& dp, int i) {
        if (i >= nums.size()) {
            return 0;
        }
        if (dp[i] != -1) {
            return dp[i];
        }
        int pick = nums[i] + backtrack(nums, dp, i+2);
        int notPick = backtrack(nums, dp, i+1);
        return dp[i] = max(pick, notPick);
    }
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return backtrack(nums, dp, 0);
    }
};
