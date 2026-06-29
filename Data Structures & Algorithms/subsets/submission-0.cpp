class Solution {
    vector<vector<int>> res;
    void helper(vector<int>& nums, int i, vector<int> curr) {
        if (i == nums.size()) {
            res.push_back(curr);
            return;
        }
        // Not Picked
        helper(nums, i + 1, curr);
        // Picked
        curr.push_back(nums[i]);
        helper(nums, i + 1, curr);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        helper(nums, 0, {});
        return res;
    }
};
