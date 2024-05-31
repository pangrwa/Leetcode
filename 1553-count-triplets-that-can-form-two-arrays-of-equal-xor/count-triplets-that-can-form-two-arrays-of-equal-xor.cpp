class Solution {
public:
    int countTriplets(vector<int>& arr) {
        vector<int> prefixSum;
        prefixSum.push_back(0); // start point
        int a = 0; 
        for (int i : arr) {
            a ^= i; 
            prefixSum.push_back(a); 
        }

        int res = 0; 
        for (int i = 0; i < prefixSum.size(); ++i) {
            for (int j = i + 1; j < prefixSum.size(); ++j) {
                if (prefixSum[i] == prefixSum[j]) {
                    res += (j - (i + 1)); 
                }
            }
        }
        return res; 
    }
};