class Solution {
public:
    bool checkValidString(string s) {
        vector<vector<bool>> dp(s.size() + 1, vector<bool>(s.size() + 1, false)); 
        int n = s.size();
        dp[n][0] = true; // "" can close with 0 open brackets 
        for (int i = n - 1; i >= 0; --i) {
            for (int j = 0; j <= i; ++j) { // # number of open bracket
                char cur = s[i];
                if (cur == '(') {
                    dp[i][j] = dp[i + 1][j + 1]; 
                } else if (cur == ')' && j > 0) {
                    dp[i][j] = dp[i + 1][j - 1]; 
                } else if (cur == '*') {
                    bool ifClose = j > 0 ? dp[i + 1][j - 1] : false; 
                    dp[i][j] = ifClose || dp[i + 1][j + 1] || dp[i + 1][j]; 
                }
            }
        }
        for (int i = 0; i < n + 1; ++i) { 
            for (int j = 0; j < n + 1; ++j) {
                cout << dp[i][j] << " ";
            }
            cout << endl; 
        }
        return dp[0][0]; // if s can close with 0 open brackets on the left
    }
};

/*
how to break down into subproblem? 
goal: given s, is it possible to close s with 0 open brackets on its left
suppose i = (
f(i:) is true only if f(i+1:) can close with 1 open bracket on its left
suppose i = )
f(i:) is true only if f(i+1:) can close with 1 less open bracket on its left


base case: 
f(last idx) = "" can only close if have 0 brackets on the left
dp[idx][# number of open brackets on the left]?? 
*/ 