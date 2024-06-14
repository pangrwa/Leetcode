class Solution {
    public int minIncrementForUnique(int[] nums) {
        Arrays.sort(nums);
        int res = 0;
        for (int i = 1; i < nums.length; ++i) {
            if (nums[i] <= nums[i - 1]) {
                res += (nums[i - 1] - nums[i] + 1); 
                nums[i] = nums[i - 1] + 1; 
            }
        }
        return res; 
    }
}

/*
the benefit here is that you only can increment by 1

how do you decide which numbers to move? 
numbers that are already in their spot it's better to remain
    as it is
    3 2 1 1, just move 1 -> 4, rather than move all numbers up?
    but this can result in O(n^2) to determine wat number to choose 
*/