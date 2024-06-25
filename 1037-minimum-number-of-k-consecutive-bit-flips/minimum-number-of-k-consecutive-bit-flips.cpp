class Solution {
public:
    void printValue(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            cout << nums[i] << " ";
        }
        cout << '\n';
    }
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        int prev = 0;
        int numOfFlips = 0; 
        for (int i = 0; i < n; ++i) {
            // if previous state has initialised a flip
            // remove that flip from the sliding window
            if (i - k >= 0 && nums[i - k] == 2) {
                numOfFlips--;
            }
            if (nums[i] == 1) {
                if (numOfFlips % 2 == 1) {
                    if (i + k > nums.size()) {
                        return -1; 
                    }
                    nums[i] = 2; // mark as flipped
                    numOfFlips++;
                    prev++;
                }
            } else {
                if (numOfFlips % 2 == 0) {
                    if (i + k > nums.size()) {
                        return -1; 
                    }
                    nums[i] = 2; // mark as flipped
                    numOfFlips++;
                    prev++;
                }
                // if the value is 0 and numOfFlips is odd implies
                // that the current value is 1 and we keep it that way 
            }
        }
        return prev;
    }
};

/*
goal: make every element in the array to be 1
when would it great to flip a 1 to 0?
- i dont think theres such as case, there are only 4 main cases
    0...1...0
    0..1..0..1 
    1..0..1..0 
    1..0..1
- the only case where flips 1s to 0s then flip back to 1s is equal is in case 1

but the question is restricted to subarray of length k
- subproblem: how to know if its possible in the first place?
- knowing who to flip
    - intuitively make sure that all the left bits are 1, doesn't make sense 
        to sacrifice one of the left bit to 0, to make it back to 1, there are two cases
        1. cause some of the left bits of 0, to flip to 0s, which creates the same problem
        2. cause some of the right bits to flip to 0s, which goes back to the same problem
    
can we break it down into subproblems using DP?
- if we understand that have we to make all the left bits 1 first means 
     we need to solve the problem from left to right
- but it isn't really like breaking into subproblems because we are only 
    looking at the preivoous problem but we always modifying the new 
    problem (which is the next k vallues in the window)
-> subproblem -> greedy solution

How can optimise the problem from nk to n? 
parity invariance - number of times an index flipped determines the final value
*/