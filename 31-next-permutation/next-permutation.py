class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        idx = len(nums) - 2
        while (idx >= 0):
            if (nums[idx] < nums[idx + 1]):
                # find the first greater element
                for i in range(len(nums) - 1, -1, -1): 
                    if nums[i] > nums[idx]:
                        nums[idx], nums[i] = nums[i], nums[idx]
                        break
                break
            idx -= 1
        # reverse
        start = idx + 1
        end = len(nums) - 1
        while (start < end):
            nums[start], nums[end] = nums[end], nums[start]
            start += 1
            end -= 1
        
         

'''
Note that the first permutation order is always in increasing order
likewise the last permutation order is always in decreasing order

how to find the next permutation? 
iterate from ths nums[i] < num[i + 1]
        - this permutation is not the last order
        - find the first number that is just greater than nums[i], swap it
        - sort evyerthing from i + 1 onwards in increasing order to 
            reset, so that "subarray" is a a e back of nums
    if therenew permtation order to handle
        
'''