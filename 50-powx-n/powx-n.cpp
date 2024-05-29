class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) {
            return 1; 
        }
        if (n < 0) {
            return (double) 1 / calc(x, abs(n)); 
        }
        return calc(x, n); 
    }

    double calc(double x, int n) {
        if (n == 0) return 1; 
        if (n == 1) return x; 
        double result = calc(x, n/2); 
        result = result * result; // symmetric
        if (n % 2 == 0) { 
            return result; 
        }
        return result * x; // to account for the remainder      
    }
};

/*
trivial solution is to do in O(n)

1 = 0 
2 = 1
0 * 1
x^n = x * x * x ... * x (for n times) 
can break this up into subproblmes
*/ 