class Solution {
    vector<string> res;
    void backtrack(string& curr, int total, int open) {
        if (total == 0 and open == 0) {
            res.push_back(curr);
            return;
        }
        // Open
        if (total) {
            curr.push_back('(');
            backtrack(curr, total - 1, open + 1);
            curr.pop_back();
        }
        // Close
        if (open) {
            curr.push_back(')');
            backtrack(curr, total, open - 1);
            curr.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        string curr = "";
        backtrack(curr, n, 0);
        return res;
    }
};
