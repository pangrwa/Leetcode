class Solution {
public:
    int specialArray(vector<int>& nums) {
        int right = 0; 
        int prev = -1; 
        int res = -1; 
        int n = nums.size();
        sort(nums.begin(), nums.end()); 
        while (right < n) {
            int cur = nums[right];
            if (cur == ( n - right)) return cur;
            if (cur > ( n - right) && prev < (n - right)) return n - right; 
        
            while ((right + 1 < n) && (nums[right] == nums[right + 1]))  {
                right++; 
            }
            prev = nums[right]; 
            right++; 
        }
        return res; 
    }
};

/*
answer lies within [1, n], n : size of the array

sort the array, compare elements with the remaning size of the array
if matches in size, then the cur element is a valid match

in the case where
[2 2 2], to middle 2 will mislead and think 2 is the crct sln,
    modify the sln to handle duplicates by shifting the pointer
to handle cases for numbers in between 1, n that are not handled by cur

*/