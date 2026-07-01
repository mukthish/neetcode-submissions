class Solution {
    vector<vector<char>> board;
    string word;
    bool dfs (int w, int i, int j, vector<vector<int>>& vis) {
        if (w == word.size()) {
            return true;
        }
        if (i < 0 or i >= board.size() or j < 0 or j >= board[0].size() or vis[i][j]) {
            return false;
        }
        bool res = false;
        if (board[i][j] == word[w]) {
            vis[i][j] = 1;
            res = dfs(w+1, i+1, j, vis)
                or dfs(w+1, i-1, j, vis)
                or dfs(w+1, i, j+1, vis)
                or dfs(w+1, i, j-1, vis);
            vis[i][j] = 0;
        }
        return res;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        this->board = board;
        this->word = word;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                vector<vector<int>> vis(board.size(), vector<int>(board[0].size(), 0));
                if (dfs(0, i, j, vis)) {
                    return true;
                }
            }
        }
        return false;
    }
};
