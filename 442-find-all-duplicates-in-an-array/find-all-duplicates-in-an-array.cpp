class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        std::vector<int> res; 
        for (int i = 0; i < nums.size(); ++i) {
            int trueValue = abs(nums[i]) - 1; 
            if (nums[trueValue] < 0) { // visited before
                res.push_back(trueValue + 1); 
            } else {
                nums[trueValue] = -nums[trueValue]; 
            }
        }
        return res; 
    }
};


/*
n <= len(array)
Think of using indexes
since values > 0
Use the index as a "visisted" set
*/ 