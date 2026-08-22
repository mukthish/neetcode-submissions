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
        for (auto& n : nums) {
            for (int j = target; j >= n; j--) {
                memo[j] = memo[j] or memo[j - n];
            }
        }
        return memo[target];
    }
};
