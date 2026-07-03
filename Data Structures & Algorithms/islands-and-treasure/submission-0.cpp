class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }
        vector<vector<int>> dir = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int r = row + dir[i][0];
                int c = col + dir[i][1];
                if (r < 0 or c < 0 or r >= grid.size() or c >= grid[0].size() or grid[r][c] != INT_MAX or grid[r][c] == -1) {
                    continue;
                } else {
                    q.push({r,c});
                    grid[r][c] = grid[row][col] + 1;
                }
            }
        }
    }
};
