class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xorSum = 0; 
        for (int num : nums) {
            xorSum ^= num; 
        }
        // find the differing bit which is reprsented by a 1 in xorSum
        int mask = 1; 
        while ((xorSum & mask) == 0) {
            mask = mask << 1; // shift the bit inwards
        }

        int firstNum = 0, secondNum = 0; 
        for (int num : nums) {
            if ((num & mask) == 0) { // don't match differing bit
                firstNum ^= num; 
            } else {
                secondNum ^= num; 
            }
        }
        return {firstNum, secondNum}; 
    }
};

/*
O(n) and O(1)
how do you know if an element appeared twice?
    - intuitively you can just count in hash table
    - i can't really use the index as a "visited table" 
        because the max value exceeds th length
- we know for sure only 2 variables appear only once
    - use 2 variables to keep track of the numbers that we have seen once
        - if we seen the number before, remove it 
            ( we won't see the value again since its twice )
    - but this approach won't work what if all the unique values appear
        in first half of the array [1 2 3 4 1 2], need to keep track
            of 1 2 3 4 

- could you bit XOR reversible property, but we have two unique numbers
    how do we separate the two numbers out? 

since every number has its own bit representation
    -> suppose two represenattion a and b
    -> a and b will have aat least 1 bit that is different
    -> when we xor 1 and 0 -> gives us a value of 1
    -> find that differing bit using a mask operation 
the goal here is to put the two numbesr in different XOR x and y
-> based on the differing bit the two numbers will XOR into different variable
-> how do we guarantee that the x and y will the contain the numbers?
    -> every num is in nums that get's xored in to x and y will have a
        corresponding duplicate to cancel it out afterwards!
*/ 