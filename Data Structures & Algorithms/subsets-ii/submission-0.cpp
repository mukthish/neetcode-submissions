class Solution {
    vector<vector<int>> res;
    void helper(vector<int>& nums, int i, vector<int>& curr) {
        if (i >= nums.size()) {
            res.push_back(curr);
            return;
        }
        // Picked
        curr.push_back(nums[i]);
        helper(nums, i + 1, curr);
        curr.pop_back();
        // Not Picked
        while (i + 1 < nums.size() and nums[i] == nums[i + 1]) {
            i++;
        }
        helper(nums, i + 1, curr);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> curr;
        sort(nums.begin(), nums.end());
        helper(nums, 0, curr);
        return res;
    }
};
