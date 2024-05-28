class Solution {
public:
    bool canJump(vector<int>& nums) {
        int minJumps = 0; 
        int n = nums.size(); 
        for (int i = n - 2; i >= 0; --i) {
            minJumps++; 
            if (nums[i] >= minJumps) {
                minJumps = 0; // solve the subproblem of jump to i
            }
        }
        return minJumps == 0; 
    }
};
/*
whether can reach the end depends on whether or not we can reach
the first f(n - i) such that nums[n - i] has enough jump power to 
reach the end. 
*/