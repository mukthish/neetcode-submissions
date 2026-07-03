class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int ROW = grid.size(), COL = grid[0].size();
        queue<pair<int, int>> q;
        int count = 0;
        for (int i = 0; i < ROW; i++) {
            for (int j = 0; j < COL; j++) {
                if (grid[i][j] == 1) {
                    count++;
                } else if (grid[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }
        int res = 0;
        vector<vector<int>> dir = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        while (count > 0 and !q.empty()) {
            int n = q.size(); 
            res +=1;
            for (int i = 0; i < n; i++) {
                auto [row, col] = q.front();
                q.pop();
                for (int j = 0; j < 4; j++) {
                    int r = row + dir[j][0];
                    int c = col + dir[j][1];
                    if (r < 0 or c < 0 or r >= ROW or c >= COL or grid[r][c] == 0 or grid[r][c] == 2) {
                        continue;
                    } else {
                        count--;
                        grid[r][c] = 2;
                        q.push({r, c});
                    }
                } 
            }
        }
        return count ? -1 : res;
    }
};
