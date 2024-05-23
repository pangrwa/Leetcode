class Solution {
public:
    unordered_map<int, int> tracer; 
    int beautifulSubsets(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end()); 
        return backtrack(0, nums, k) - 1; // to account for empty subset
    }

    int backtrack(int idx, vector<int>& nums, int k) {
        if (idx == nums.size()) {
            return 1;
        }

        // include current element
        int count = 0; 
        if (tracer[nums[idx] - k] == 0) { // continue beautiful
            tracer[nums[idx]]++; 
            count += backtrack(idx + 1, nums, k); 
            tracer[nums[idx]]--;
        }
        // dont include element or the current element cause it to not be beautiful
        count += backtrack(idx + 1, nums, k); 
        return count; 
    }
};

/*
beautiful only, nums[idx] - k or nums[idx] + k not in the subset
if we build the subset in an increasing order, then we now nums[idx] + k will never exist in the
subset

during the backtracking
1. if nums[idx - k] in the subset trace
    numBeautiful++ 
*/