class Solution {
    vector<int> dp;
    int dfs(int i, vector<int>& nums) {
        if (i == nums.size()) 
            return 0;
        if (dp[i]) 
            return dp[i];

        int LIS = 1;
        for (int j = i + 1; j < nums.size(); j++) {
            if (nums[j] > nums[i])
                LIS = max(LIS, 1 + dfs(j, nums));
        }
        return dp[i] = LIS;
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        dp = vector<int>(nums.size());
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            res = max(res, dfs(i, nums));
        }   
        return res;
    }
};
