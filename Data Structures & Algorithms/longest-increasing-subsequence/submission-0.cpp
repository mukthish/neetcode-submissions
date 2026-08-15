class Solution {
    vector<vector<int>> dp;
    int dfs(vector<int>& nums, int i, int j) {
        if (i == nums.size()) {
            return 0;
        }
        if (dp[i][j + 1]) {
            return dp[i][j + 1];
        }

        // skip
        int LIS = dfs(nums, i + 1, j);

        // pick
        if (j == -1 or nums[j] < nums[i]) {
            LIS = max(LIS, 1 + dfs(nums, i+1, i));
        }

        return dp[i][j + 1] = LIS;
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        dp = vector<vector<int>>(n, vector<int>(n + 1));
        return dfs(nums, 0, -1);
    }
};
