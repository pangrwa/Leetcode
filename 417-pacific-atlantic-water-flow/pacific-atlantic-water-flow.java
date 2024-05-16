class Solution {
    public int[][] directions = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}}; 
    public int[][] heights; 
    public int ROWS;
    public int COLS; 

    public List<List<Integer>> pacificAtlantic(int[][] heights) {
        ROWS = heights.length; 
        COLS = heights[0].length; 
        this.heights = heights; 
        boolean[][] visited = new boolean[ROWS][COLS]; 
        int[][] possible = new int[ROWS][COLS];
        
        // pacific ocean 
        for (int i = 0; i < ROWS; ++i) {
            dfs(i, 0, visited, possible); 
        }
        for (int j = 0; j < COLS; ++j) {
            dfs(0, j, visited, possible); 
        }
        
        visited = new boolean[ROWS][COLS];  
        // atlantic ocean 
        for (int i = 0; i < ROWS; ++i) {
            dfs(i, COLS - 1, visited, possible); 
        }
        for (int j = 0; j < COLS; ++j) {
            dfs(ROWS - 1, j, visited, possible); 
        }

        List<List<Integer>> res = new ArrayList<>();
        for (int i = 0; i < ROWS; ++i) {
            for (int j = 0; j < COLS; ++j) {
                if (possible[i][j] == 2) {
                    List<Integer> coords = new ArrayList<>(); 
                    coords.add(i); 
                    coords.add(j); 
                    res.add(coords); 
                }
            }
        }
        return res; 
    }

    void dfs(int x, int y, boolean[][] visited, int[][] possible) {
        if (visited[x][y]) {
            return; 
        }
        visited[x][y] = true;
        possible[x][y] += 1; 
        for (int [] d : directions) {
            int a = x + d[0]; 
            int b = y + d[1]; 
            if (!withBounds(a, b) || 
                visited[a][b] || heights[a][b] < heights[x][y]) {
                continue; 
            }

            dfs(a, b, visited, possible); 
        }
    }

    public boolean withBounds(int a, int b) {
        return (a >= 0 && a < ROWS) && (b >= 0 && b < COLS); 
    }
}