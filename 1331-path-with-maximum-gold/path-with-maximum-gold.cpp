class Solution {
public:
    int ROWS; 
    int COLS;
    int directions[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}}; 

    int getMaximumGold(vector<vector<int>>& grid) {
        int res = 0;
        ROWS = grid.size();
        COLS = grid[0].size(); 
        vector<vector<bool>> visited(ROWS, vector(COLS, false));

        for (int i = 0; i < ROWS; ++i) {
            for (int j = 0; j < COLS; ++j) {
                if (grid[i][j] != 0) {
                    res = max(res, dfs(i, j, grid, visited));
                }
            }
        }
        return res; 
    }
    
    int dfs(int x, int y, vector<vector<int>>& grid, vector<vector<bool>>& visited) {
        visited[x][y] = true; 
        int pathSum = 0; 
        for (const auto& d : directions) {
            int a = x + d[0]; 
            int b = y + d[1];
            if (!withBounds(a, b) || visited[a][b] || grid[a][b] == 0) {
                continue; 
            }
            pathSum = max(pathSum, dfs(a, b, grid, visited)); 
        }
        visited[x][y] = false; 
        return pathSum + grid[x][y]; 
    }

    bool withBounds(int a, int b) {
        return (a >= 0 && a < ROWS) && (b >= 0 && b < COLS); 
    }
};