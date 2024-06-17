class Solution {
public:
    bool existsSquare(int left, int right, int goal) {
        while (left <= right) { 
            long mid = left + (long) ( (right - left) / 2 ); 
            if (mid * mid == goal) {
                return true; 
            }
            if (mid * mid > goal) { 
                right = mid - 1; 
            } else {
                left = mid + 1; 
            }
        }
        return false; 
    }
    bool judgeSquareSum(int c) {
        for (long i = 0; i * i <= c; ++i) { 
            int remain = c - (i * i); 
            if (existsSquare(0, remain, remain)) {
                return true; 
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
