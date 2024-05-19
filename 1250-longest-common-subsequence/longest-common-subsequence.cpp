class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size() + 1, vector(text2.size() + 1, 0));
        for (int i = 0; i < text1.size(); ++i) {
            for (int j = 0; j < text2.size(); ++j) {
                if (text1[i] == text2[j]) {
                    dp[i + 1][j + 1] = dp[i][j] + 1; 
                } else {
                    dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]); 
                }
            }
        }
        return dp[text1.size()][text2.size()]; 
    }
};

/*
3 cases 
1. dp[i][j]  = dp[i - 1][j - 1] + 1 
2. dp[i][j] = max(dp[i][j], -1 of each)
*/