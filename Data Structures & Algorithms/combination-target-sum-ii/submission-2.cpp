class Solution {
    vector<vector<int>> res;
    void backtrack(vector<int>& candidates, int target, vector<int>& curr, int i) {
        if (target == 0) {
            res.push_back(curr);
            return;
        }
        if (target < 0 or i == candidates.size()) {
            return;
        }
        // Picked
        curr.push_back(candidates[i]);
        backtrack(candidates, target - candidates[i], curr, i + 1);
        curr.pop_back();
        // Not Picked
        while (i + 1 < candidates.size() and candidates[i] == candidates[i + 1]) {
            i++;
        }
        backtrack(candidates, target, curr, i + 1);
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> curr;
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, curr, 0);
        return res;
    }
};
