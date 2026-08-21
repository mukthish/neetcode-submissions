class Solution {
    vector<vector<int>> dp;
    bool helper(vector<int>& nums, int i, int target) {
        if (i == nums.size()) {
            return target == 0;
        }
        if (target < 0) {
            return false;
        }
        if (dp[i][target] != -1) {
            return dp[i][target];
        }
        return helper(nums, i + 1, target - nums[i]) or helper(nums, i + 1, target);
    }

   public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);

        if (sum % 2) {
            return false;
        }
        dp = vector<vector<int>>(nums.size(), vector<int>(sum, -1));

        return helper(nums, 0, sum / 2);
    }
};
