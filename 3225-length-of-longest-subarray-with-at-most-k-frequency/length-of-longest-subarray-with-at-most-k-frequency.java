class Solution {
    public int maxSubarrayLength(int[] nums, int k) {
        int res = Integer.MIN_VALUE;
        int left = 0, right = 0; 
        HashMap<Integer, Integer> window = new HashMap<>(); 
        while (right < nums.length) {
            window.put(nums[right], window.getOrDefault(nums[right], 0) + 1);
            while (window.get(nums[right]) > k) { // shrink the window
                window.put(nums[left], window.get(nums[left]) - 1);
                left++; 
            }
            
            res = Math.max(res, right - left + 1);  
            right++; 
        }
        return res; 
    }
}

/*
Use a sliding window that keeps of the elements and keep a counter
- if we wish to add a new element into the window
    check if the element exceeds k 
- if that exceeds k then we try to shrink the subarray until we can 
    fit it 
*/