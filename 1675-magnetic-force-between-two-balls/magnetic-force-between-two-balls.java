class Solution {

    public boolean isValidForce(int[] position, int force, int m) {
        int prev = position[0]; 

        int counter = 1; 
        for (int i = 1; i < position.length; ++i) { 
            if (position[i] - prev >= force) { 
                prev = position[i]; 
                counter++; 
            }
            if (counter == m) {
                return true; 
            }
        }
        return false; 
    }

    public int maxDistance(int[] position, int m) {
        Arrays.sort(position);
        int n = position.length; 
        int left = 1; // minimum distance between balls
        int right = position[n - 1] - 1; // max distance between balls
        int res = 1; 

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (isValidForce(position, mid, m)) {
                res = mid; 
                left = mid + 1; 
            } else {
                right = mid - 1;
            }
        }
        return res; 
    }
}

/*
goal: make sure all the balls are evenly spread out
*/ 