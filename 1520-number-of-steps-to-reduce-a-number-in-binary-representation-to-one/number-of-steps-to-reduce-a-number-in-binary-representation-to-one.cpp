class Solution {
public:
    int numSteps(string s) {
        int res = 0;
        int carry = 0; // to represent to bringing over of 1 bit when +
        for (int i = s.size() - 1; i > 0; --i) {
            if ( ((s[i] - '0') + carry) % 2 == 1) { // odd
                carry = 1; // bringing the 1 bit over
                res += 2; 
            } else {
                res += 1; 
            }
        }
        // carry = 1, apply one last operation to remove the last 0
        return res + carry; 
    }
};

/*
modify the question to removing the N-1 last number of bits
- iterate from back to front
    -1: + 2 operations since odd (+1, divide by two to remove the 0)
    -0: + 1 operation since even
- careful when bit is 1 cuz you + 1, have carryover of 1

*/ 