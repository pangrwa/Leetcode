class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> freq1; 
        for (int i : nums1) {
            freq1.insert(i); 
        }
        vector<int> res; 
        for (int i : nums2) {
            if (freq1.contains(i)) {
                res.push_back(i);
                freq1.erase(i); 
            }
        }
        return res; 
    }
};