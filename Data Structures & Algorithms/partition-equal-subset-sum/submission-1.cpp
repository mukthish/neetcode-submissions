class Solution {
   public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return false;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum & 1) return false;
        int target = sum >> 1;
        vector<vector<bool>> memo(n, vector<bool>(target + 1, false));
        for (int i = 0; i < n; i++) memo[i][0] = true;
        if (nums[0] <= target) memo[0][nums[0]] = true;
        for (int i = 1; i < n; i++) {
            for (int curr = 1; curr <= target; curr++) {
                bool skip = memo[i - 1][curr];
                bool pick = false;
                if (curr - nums[i] >= 0) {
                    pick = memo[i - 1][curr - nums[i]];
                }
                memo[i][curr] = pick or skip;
            }
        }
        return memo[n-1][target];
    }
};
