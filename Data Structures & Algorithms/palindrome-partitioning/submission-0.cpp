class Solution {
    vector<vector<string>> res;
    string s;
    void backtrack(vector<string>& curr, int start, int end) {
        if (end > s.size()) {
            if (start == s.size()) {
                res.push_back(curr);
            }
            return;
        }
        if (palindrome(start, end - 1)) {
            curr.push_back(string(s.begin() + start, s.begin() + end));
            backtrack(curr, end, end + 1);
            curr.pop_back();
        }
        backtrack(curr, start, end + 1);
    }

    bool palindrome(int start, int end) {
        while (start < end) {
            if (s[start++] != s[end--]) {
                return false;
            }
        }
        return true;
    }

public:
    vector<vector<string>> partition(string s) {
        this->s = s;
        vector<string> curr;
        backtrack(curr, 0, 1);
        return res;
    }
};
