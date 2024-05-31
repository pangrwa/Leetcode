class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int res = 0; 
        int n = arr.size(); 
        for (int i = 0; i < n; ++i) {
            int xorA = 0;
            for (int j = i + 1; j < n; ++j) { 
                xorA ^= arr[j - 1]; // build the left subarray

                int xorB = 0; 
                for (int k = j; k < n; ++k) { 
                    xorB ^= arr[k]; 
                    if (xorA == xorB) 
                        res++; 
                }
            }
        }
        return res; 
    }
};