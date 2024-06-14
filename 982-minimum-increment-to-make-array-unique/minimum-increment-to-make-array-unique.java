class Solution {
    public int minIncrementForUnique(int[] nums) {
        int max = 0;
        int res = 0; 
        for (int val : nums) {
            max = Math.max(val, max); 
        }  
        // if all n (10) elements are 1, per say, then 
            // we need at least 10 space
        int[] freq = new int[nums.length + max];  
        for (int i = 0; i < nums.length; ++i) {
            freq[nums[i]] += 1; 
        }

        for (int i = 0; i < freq.length; ++i) {
            if (freq[i] > 1) {
                int carryOver = freq[i] - 1; 
                freq[i + 1] += carryOver; 
                freq[i] = 1; 
                res += carryOver; 
            }
        }
        return res; 
    }
}

/*
count how many smaller elements than you? e
*/ 