class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre, post;
        pre = nums;
        post = nums;
        for (int i = 1; i < n; i++) {
            pre[i] = pre[i-1] * nums[i];
        }
        for (int i = n-2; i >= 0; i--) {
            post[i] = post[i+1] * nums[i];
        }
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            int x = 1, y = 1;
            if (i > 0) {
                x = pre[i-1];
            }
            if (i < n-1) {
                y = post[i+1];
            }
            res[i] = x * y;
        }
        return res;
    }
};
