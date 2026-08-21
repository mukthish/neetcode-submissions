class Solution {
   public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return false;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum & 1) return false;
        int target = sum >> 1;
        vector<bool> memo(target + 1, false);
        memo[0] = true;
        for (int i = 0; i < n; i++) {
            vector<bool> temp = memo;
            for (int curr = 1; curr <= target; curr++) {
                if (curr - nums[i] >= 0) {
                    memo[curr] = temp[curr] or temp[curr - nums[i]];
                }
            }
        }
        return memo[target];
    }
};
