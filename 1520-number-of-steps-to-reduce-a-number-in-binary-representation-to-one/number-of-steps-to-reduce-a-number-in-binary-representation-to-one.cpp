class Solution {
public:
    int numSteps(string s) {
        int res = 0; 
        while (s.size() > 1) {
            int n = s.size() - 1; 
            if (s[n] == '1') { // odd
                int idx = n; 
                while (idx >= 0 && s[idx] == '1') {
                    s[idx] = '0'; 
                    idx--; 
                }
                if (idx == -1) {
                    s = '1' + s; 
                } else {
                    s[idx] = '1'; 
                }
            } else {    // even
                s = s.substr(0, n); 
            }
            res++; 
        }
        return res; 
    }
};


/*
how to determine if a number if odd or even in binary representation?
- the LSB

how to add 1?
-  100 011
- iterate from the back till you see the first 0
how to divide by 2? 
- slice the substr
*/ 