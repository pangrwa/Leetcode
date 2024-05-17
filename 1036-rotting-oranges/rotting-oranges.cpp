class Solution {
public:
    int ROWS; 
    int COLS; 
    int orangesRotting(vector<vector<int>>& grid) {
        ROWS = grid.size(); 
        COLS = grid[0].size(); 
        int directions[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}}; 
        queue<pair<int, int>> rottenOranges; 
        for (int i = 0; i < ROWS; ++i) {
            for (int j = 0; j < COLS; ++j) {
                if (grid[i][j] == 2) {
                    rottenOranges.push(make_pair(i, j));
                    grid[i][j] = 0; // mark as visited
                }
            }
        }

        int res = 0; 
        while (!rottenOranges.empty()) {
            int s = rottenOranges.size(); 
            for (int i = 0; i < s; ++i) {
                pair<int, int>& cur = rottenOranges.front(); 
                for (const auto& d : directions) {
                    int a = cur.first + d[0]; 
                    int b = cur.second + d[1]; 
                    if (!withinBounds(a, b) || grid[a][b] == 0) {
                        continue; 
                    }
                    grid[a][b] = 0; // visited
                    rottenOranges.push(make_pair(a, b)); 
                }
                rottenOranges.pop(); 
            }
            if (!rottenOranges.empty()) {
                res++;
            }
        }

        for (int i = 0; i < ROWS; ++i) {
            for (int j = 0; j < COLS; ++j) {
                if (grid[i][j] == 1) return -1; // still has fresh 
            }
        }
        return res;  
    }

    bool withinBounds(int a, int b) {
        return (a >= 0 && a < ROWS) && (b >= 0 && b < COLS); 
    }
};