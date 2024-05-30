class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int count = 0;
        for (int i = 0; i < arr.size(); ++i) {
            // calculates the first subarray from i -> j - 1; 
            int xorA = 0; 
            for (int j = i + 1; j < arr.size(); ++j) {
                xorA ^= arr[j - 1]; 
                // calculates the second subarray from j -> k; 
                int xorB = 0; 
                for (int k = j; k < arr.size(); ++k) {
                    xorB ^= arr[k]; 
                    if (xorA == xorB) {
                        count++; 
                    }
                }
            }
        }
        return count; 
    }
};
/*
recall xor operation 
opoosite value -> 1
same value -> 0

i -> j - 1
j -> k 

brute force -> consider all triplets and check if it satisfies
    -> bottleneck n^3 to get coords and still need to spend another n
    -> to check whether the condition is satisified

optmise this just buy calcaulating the XOR  values for pairs, 
key (XOR values) -> array of pairs
iterate across the pairs to see if there's any matching one!

can't use DP to solve this question, there's no idea of subproblems



*/