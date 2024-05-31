class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size(); 
        int res = 0; 
        int prefixSum = 0; 
        for (int i = 0; i < n; ++i) {
            prefixSum = arr[i]; 
            for (int j = i + 1; j < n; ++j) {
                prefixSum ^= arr[j];
                if (prefixSum == 0)
                    res += j - i; 
            }
        }
        return res; 
    }
};