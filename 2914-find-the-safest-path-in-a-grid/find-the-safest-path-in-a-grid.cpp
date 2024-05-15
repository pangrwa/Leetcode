class Solution {
public:
    int ROWS;
    int COLS; 
    const int directions[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}}; 

    int pathContainsSf(vector<vector<int>>& grid, int sf) {
        std::queue<std::pair<int, int>> q;
        std::vector<vector<bool>> visited(ROWS, vector<bool>(COLS, false));
        q.push(make_pair(0, 0));
        visited[0][0] = true; 
        while (!q.empty()) {
            int s = q.size();
            for (int i = 0; i < s; ++i) {
                pair<int, int> cur = q.front();
                q.pop();
                if (cur.first == ROWS - 1 && cur.second == COLS - 1) {
                    return true; // valid path found; 
                }

                for (const auto& d : directions) {
                    int x = cur.first + d[0]; 
                    int y = cur.second + d[1];
                    if (
                        (x < 0 || y < 0) ||
                        (x >= ROWS || y >= COLS) ||
                        visited[x][y]
                    ) {
                        continue;
                    }
                    if (grid[x][y] >= sf) {
                        visited[x][y] = true; 
                        q.push(make_pair(x, y)); 
                    }
                }
            }
        }
        return false; 
    }
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        std::queue<std::pair<int, int>> q; 
        std::vector<std::pair<int, int>> thiefs; 
        ROWS = grid.size(); 
        COLS = grid[0].size(); 
        for (int i = 0; i < ROWS; ++i) {
            for (int j = 0; j < COLS; ++j) {
                if (grid[i][j] == 1) {
                    pair<int, int> p = make_pair(i, j); 
                    q.push(p);
                    grid[i][j] = 0; // thieves
                } else {
                    grid[i][j] = -1;
                }
            }
        }
                
        int level = 0; 
        while (!q.empty()) {
            int s = q.size(); 
            for (int i = 0; i < s; ++i) {
                std::pair<int, int> cur = q.front();
                q.pop(); 
                for (const auto &d : directions) {
                    int x = cur.first + d[0]; 
                    int y = cur.second + d[1];
                    
                    if (
                        x < 0 || y < 0 || 
                        x >= ROWS || y >= COLS ||
                        grid[x][y] >= 0
                    ) {
                        continue; // visited
                    }
                    grid[x][y] = level + 1; // update safety factor
                    q.push(make_pair(x,  y));
                }
            }
            level++; 
        }
        
        int start = 0; 
        int end = grid[0][0]; // the starting point contains the max possible sf
        int res = -1; // start point gurantees thou
        while (start <= end) {
            int mid = (start + end) / 2;
            if (pathContainsSf(grid, mid)) {
                res = mid;
                start = mid + 1; // try to find a better path
            } else {
                end = mid - 1; // when mid becomes 0, path always contains it
            }
        }
        return res; 
    }
};


/*
Basically fnd all paths from starting -> said point
For each path you should have a safeness factor,
    If there exists a coordinate that is closer to a thief, you have
    to update the safety factor of that path
At the end of each path, select the path with the highest factor

How do you determine at every point the closeness to a thief? 
    It seems inefficent at every point we branch out to find a 1, that's 
    really just O(v + e)^2
    Maybe we can do a precompuation? Given all the thiefs, we store the min
    distance nearest to a thief. Then we replace all theiefs with 0 
    But if every cell is a thief that means we are doing lots of multiple of DFS
    BUT we can do a single BFS with all starting points of thiefs
    That's like spreading the waves, if the cell has been visited before (value > 0)
    the we can guarentee that's the minimum factor that we have seen 

/
After getting all the safeness factor of each cell. The starting point contains
the maximum possible safeness factor, cuz even if we have other cell that have
better safeness factor, the path want's to have the minimum of it. 
*/