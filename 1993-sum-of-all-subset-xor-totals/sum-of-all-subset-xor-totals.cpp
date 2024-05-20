class Solution {
public:
    int res = 0;
    int size; 
    stack<int> trace; 
    int subsetXORSum(vector<int>& nums) {
        size = nums.size(); 
        backtrack(0, nums); 
        return res; 
    }

    void backtrack(int cur, vector<int>& nums) {
        if (cur == size) {
            res += calcXOR(nums); 
            return; 
        }
        // include cur
        trace.push(cur); 
        backtrack(cur + 1, nums);
        // exclue cur
        trace.pop(); 
        backtrack(cur + 1, nums);
    }

    int calcXOR(vector<int>& nums) {
        stack<int> copy = trace; 
        int start = 0;
        while (!copy.empty()) {
            start = start ^ (nums[copy.top()]); 
            copy.pop(); 
        }
        // reverse start
        start = start ^ 0; 
        return start; 
    }
};

/*
count the number of subsets? 
*/ 