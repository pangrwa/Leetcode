class Solution:
    def countTriplets(self, arr: List[int]) -> int:
        prefix_sum = [0,]
        ps = 0
        for num in arr: 
            ps ^= num
            prefix_sum.append(ps)

        n = len(prefix_sum)
        res = 0
        for i in range(n): # i + 1: represents the start point
            for j in range(i + 1, n):
                # this means the XOR sum from i + 1 -> j = 0
                if (prefix_sum[i] == prefix_sum[j]): 
                    # count the number of valid triplets
                    res += (j - (i + 1))
        return res