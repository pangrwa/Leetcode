class Solution {
public:
    bool judgeSquareSum(int c) {
        int left = 0; 
        // O(logc)
        int right = (long) sqrt(c); // largest value
        while (left <= right) { 
            long sum = pow(left, 2) + pow(right , 2); 
            if (sum == c) return true; 
            if (sum > c) {
                right--; 
            } else {
                left++; 
            }
        }
        return false; 
    }
};
/*
a, b < c
two pointers from 0 and c - 1 
if too big reduce right

i -> 0 - c
    remain = c - i^2
    check if remain is a square? 

sqrt(value) must not have a decimal? 
*/ 
