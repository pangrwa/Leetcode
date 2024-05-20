class Solution {
public:
    int currentXOR = 0; 
    int res = 0; 
    int subsetXORSum(vector<int>& nums) {
        backtrack(0, nums);
        return res; 
    }
    void backtrack(int index, vector<int>& nums) {
        if (index == nums.size()) {
            res += currentXOR; 
            return; 
        }
        // include current
        currentXOR = currentXOR ^ (nums[index]); 
        backtrack(index + 1, nums); 
        // remove current XOR
        currentXOR = currentXOR ^ (nums[index]);
        backtrack(index + 1, nums); 
    }
};

/*
note the commutative propertly of XOR
a = a XOR x XOR x (i can back the number by applying twice)
*/