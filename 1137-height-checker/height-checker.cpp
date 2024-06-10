class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int n = heights.size();
        const int MAX_HEIGHT = 100; 
        vector<int> counts(MAX_HEIGHT, 0); 
        for (int i = 0; i < n; ++i) { 
            counts[heights[i] - 1]++; 
        }
        vector<int> sorted;
        for (int i = 0; i < MAX_HEIGHT; ++i) {
            while (counts[i] > 0) {
                sorted.push_back(i + 1); 
                counts[i]--; 
            }
        }
        
        int res = 0; 
        for (int i = 0; i < n; ++i) {
            if (heights[i] != sorted[i]) 
                res++; 
        }
        return res; 
    }
};