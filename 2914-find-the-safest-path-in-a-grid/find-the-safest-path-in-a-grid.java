class Solution {
    public int ROWS;
    public int COLS; 
    public int[][] directions = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}}; 
    public int maximumSafenessFactor(List<List<Integer>> grid) {
        ROWS = grid.size();
        COLS = grid.get(0).size(); 
        adjustGrid(grid); 
        return modifiedDijkstra(grid); 
    }
    // modify dijkstra to priortise paths with higher maximum safety value
    // since we want to track the minimum of the max path, before push the new coordinate
    // modify the coordinate to take the minimum of the path we have seen 
    public int modifiedDijkstra(List<List<Integer>> grid) {
        PriorityQueue<ArrayList<Integer>> maxHeap = new PriorityQueue<>(
            (a, b) -> b.get(0).compareTo(a.get(0))
        );
        ArrayList<Integer> startPoint = new ArrayList<>();
        startPoint.add(grid.get(0).get(0)); 
        startPoint.add(0); 
        startPoint.add(0);
        grid.get(0).set(0, -1); //visited
        maxHeap.add(startPoint); 

        while (maxHeap.size() != 0) {
            List<Integer> cur = maxHeap.poll(); 
            if (cur.get(1) == (ROWS - 1) && cur.get(2) == (COLS - 1)) {
                    return cur.get(0); // max safety factor
            }
            for (int[] d : directions) {
                int a = cur.get(1) + d[0];
                int b = cur.get(2) + d[1]; 

                if (!withinBounds(a, b) || grid.get(a).get(b) == -1) {
                    continue; 
                }
                int minPath = Math.min(cur.get(0), grid.get(a).get(b));
                ArrayList<Integer> neigh = new ArrayList<>();
                neigh.add(minPath);
                neigh.add(a);
                neigh.add(b); 
                grid.get(a).set(b, -1); // mark as visited
                maxHeap.add(neigh); 
            }
        }
        return -1; // won't reach here

    }
    public void adjustGrid(List<List<Integer>> grid) { 
        
        Queue<List<Integer>> startPoints = new LinkedList<>(); 
        for (int i = 0; i < ROWS; ++i) {
            for (int j = 0; j < COLS; ++j) {
                if (grid.get(i).get(j).equals(1)) {
                    ArrayList<Integer> coords = new ArrayList<>();
                    coords.add(i); 
                    coords.add(j); 
                    startPoints.add(coords); 
                    grid.get(i).set(j, 0); 
                } else {
                    grid.get(i).set(j, -1); 
                }
            }
        }
        int layer = 0; 
        while (!startPoints.isEmpty()) {
            int size = startPoints.size(); 
            for (int i = 0; i < size; ++i) {
                List<Integer> cur = startPoints.poll(); 
                for (int[] d : directions) {
                    int x = cur.get(0) + d[0];
                    int y = cur.get(1) + d[1]; 
                    if (!withinBounds(x, y) || grid.get(x).get(y) != -1) {
                        continue; 
                    }
                    grid.get(x).set(y, layer + 1); // mark as visited
                    List<Integer> newCoords = new ArrayList<>();
                    newCoords.add(x);
                    newCoords.add(y);
                    startPoints.add(newCoords); 
                }
            }
            layer += 1; 
        }
        return;
    }

    public boolean withinBounds(int x, int y) {
        return (x >= 0 && x < ROWS) && (y >= 0 && y < COLS); 
    }
}