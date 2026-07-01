class Solution {
    vector<string> res;
    string digits;
    vector<vector<char>> map = {
        {},
        {},
        {'a', 'b', 'c'},
        {'d', 'e', 'f'},
        {'g', 'h', 'i'},
        {'j', 'k', 'l'},
        {'m', 'n', 'o'},
        {'p', 'q', 'r', 's'},
        {'t', 'u', 'v'},
        {'w', 'x', 'y', 'z'}
    };
    void backtrack(string& curr, int i) {
        if (i == digits.size()) {
            if (i) {
                res.push_back(curr);
            }
            return;
        }
        vector<char> options = map[digits[i] - '0'];
        for (int j = 0; j < options.size(); j++) {
            curr.push_back(options[j]);
            backtrack(curr, i + 1);
            curr.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        this->digits = digits;
        string curr = "";
        backtrack(curr, 0);
        return res;
    }
};
