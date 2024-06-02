class Solution:
    def singleNumber(self, nums: List[int]) -> List[int]:
        xor_sum = 0
        for num in nums: 
            xor_sum ^= num
        # resulting xor_sum is the xor sum of the 2 numbers
        # find the first differing bit
        right_mask = xor_sum & (-xor_sum)
        
        xor_a = 0
        xor_b = 0
        for num in nums:
            if (num & right_mask) == 0:
                xor_a ^= num
            else:
                xor_b ^= num
        return [xor_a, xor_b]