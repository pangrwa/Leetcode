class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        // recall priority queue front of the queue contains
        // last element 
        struct MinComparator {
            bool operator()(const int a, const int b) const { 
                return a > b; 
            }
        };
        priority_queue<int, vector<int>, MinComparator> minHeap;  
        for (int i = 0; i < heights.size() - 1; ++i) {
            int heightDiff = heights[i + 1] - heights[i]; 
            if (heightDiff <= 0) {
                continue; 
            }
            minHeap.push(heightDiff); 
            if (minHeap.size() > ladders) { 
                int useBricks = minHeap.top(); 
                minHeap.pop(); 
                if (useBricks > bricks) {
                    return i; // furthest we can go 
                }
                bricks -= useBricks; 
            }
        }
        return heights.size() - 1; // furthest you can go 
    }
};

/*
ideally in the entire path, only use bricks for minimal difference
only have n number of ladders, so how to store all the max difference 
    for the ladders? 
We use a min heap that remains the size of n, so at the end of the path
    the min heap contains all the size diff that are ideal candidates
    of the ladders
*/ 