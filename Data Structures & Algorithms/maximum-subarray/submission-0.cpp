class Solution {
   public:
    int maxSubArray(vector<int>& nums) {
        int curr = 0, mx = -10001;

        for (auto& n : nums) {
            curr += n;
            mx = max(curr, mx);
            if (curr < 0) {
                curr = 0;
            }
        }

        return mx;
    }
};
