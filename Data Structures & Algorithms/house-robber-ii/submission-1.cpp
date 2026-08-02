class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }
        int a = 0, b = nums[0];
        for (int i = 1; i < n-1; i++) {
            int pick = nums[i] + a;
            int not_pick = b;
            a = b;
            b = max(pick, not_pick);
        }
        int res = b;
        a = 0, b = nums[1];
        for (int i = 2; i < n; i++) {
            int pick = nums[i] + a;
            int not_pick = b;
            a = b;
            b = max(pick, not_pick);
        }
        res = max(res, b);
        return res;
    }
};
