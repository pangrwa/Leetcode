class Solution {
    public int numberOfSubarrays(int[] nums, int k) {
        int oddCounter = 0;
        int n = nums.length; 
        int left = 0;
        int right = 0; 
        int res = 0; 
        
        while (right < n) {
            int cur = nums[right];
            if (cur % 2 != 0) {
                oddCounter++; 
            }
            if (oddCounter == k) {
                // count the number of even numbers on the right
                int ext = right + 1; 
                while (ext < n && (nums[ext] % 2 == 0)) {
                    ext++; 
                }
                int numEven = ext - right; 
                
                while (oddCounter == k) {
                    if (nums[left] % 2 != 0) {
                        oddCounter--; 
                    }
                    res += numEven; 
                    left++;
                }
            }
            right++; 
        }
        return res; 
    }
}

/*
counting the total number of odd numbers is important, because 
*/ 