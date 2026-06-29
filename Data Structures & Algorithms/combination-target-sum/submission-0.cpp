class Solution {
    vector<vector<int>> res;
    void backtrack(vector<int>& nums, int target, vector<int>& curr, int i) {
        if (target == 0) {
            res.push_back(curr);
            return;
        }
        if (target < 0 or i == nums.size()) {
            return;
        }
        // Picked
        curr.push_back(nums[i]);
        backtrack(nums, target - nums[i], curr, i);
        curr.pop_back();
        // Not Picked
        backtrack(nums, target, curr, i + 1);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> curr;
        backtrack(nums, target, curr, 0);
        return res;
    }
};
