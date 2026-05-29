class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<int> row(9), col(9), box(9);
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char c = board[i][j];
                if (!isdigit(c)) 
                    continue;
                int k = (i / 3) * 3 + j / 3;
                int val = c - '0';
                if (row[i] & (1 << val) or col[j] & (1 << val) or box[k] & (1 << val)) {
                    return false;
                } else {
                    row[i] |= (1 << val);
                    col[j] |= (1 << val);
                    box[k] |= (1 << val);
                }
            }
        }
        return true;
    }
};
