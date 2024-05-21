class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0; 
        int right = 0; 
        int res = numeric_limits<int>::min();
        while (right < nums.size()) {
            int cur = nums[right];
            if (cur == 0) {
                k -= 1; 
            }
            if (k < 0) {
                if (nums[left] == 0) k += 1; 
                left++; 
            }
            res = max(res, right - left + 1); 
            right++; 
        }
        return res; 
    }
};