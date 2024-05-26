class Solution {
public:
    int checkRecord(int n) {
        vector<vector<int>> dp(n + 1, vector< int>(6, 0));
        long mod = 1000000007; 
        // set base case, 0 absent 0 late
        dp[0][0] = 1;

        for (int i = 1; i < n + 1; ++i) {
            // handle present
                // absent 1 day
            int present = (dp[i - 1][3] + dp[i - 1][4]) % mod; 
            present = (present + dp[i - 1][5]) % mod; 
            dp[i][3] = present; 
                // absent 0 day
            present = (dp[i - 1][0] + dp[i - 1][1]) % mod;
            present = (present + dp[i - 1][2]) % mod; 
            dp[i][0] = present; 

            // handle absent
            dp[i][3] = (dp[i][3] + present) % mod; 

            // handle late
            dp[i][1] = dp[i - 1][0] % mod; 
            dp[i][2] = dp[i - 1][1] % mod; 
            dp[i][4] = dp[i - 1][3] % mod; 
            dp[i][5] = dp[i - 1][4] % mod; 
        }

        int res = 0; 
        for (int i = 0; i < 6; ++i) {
            res = (res + dp[n][i]) % mod; 
        }
        return res; 
    }
};

/*
A < 2 && L < 3
note: 
the order in which the student was late or absent doens't matter
how do we break the subproblem down?
given, the number eligible records for the problem of n - 1
    what happens on the nth day, the student is A, L or P
f(i) = all(f(i - 1) +  A, L, P) st total (A < 2 && L < 3) 

ideally we want to keep track of all the strings but answer may be large
there are only 6 constants we can  of, only these will make it valid
1. Absent 1 day, late 0 represent trackwith 3th idx
2. Absent 1 day, late 1 represent with 4st idx
3. Absent 1 day, late 2 represent with 5nd idx
4. Absent 0 day, and so on , 0, 1, 2

f(i) = 
    present = just take all the constants from f(i - 1), reset late days
    absent = f(i)(absent 1 day) take from f(i - 1) absent 0 day, reset late
    late = f(i) late 1 day take take from f(i - 1) late 0 day
        f(i) late 2 day take from f(i -1 ) late 1 day

base case: all the values we are taking from f(i -1) should initalise as 1
time: O(n) 
space: O(n) 
*/ 