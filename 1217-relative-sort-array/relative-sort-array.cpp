class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> count(1001, 0); 
        for (int i : arr1) {
            count[i]++;
        }

        vector<int> res;
        for (int i : arr2) {
            while (count[i] > 0) {
                res.push_back(i); 
                count[i]--; 
            }
        }
        for (int i = 0; i < count.size(); ++i) {
            while (count[i] > 0) {
                res.push_back(i);
                count[i]--; 
            }
        }
        return res; 
    }
};