class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        int n = nums.size(); 
        vector<vector<long long>> dp(n + 1, vector<long long>(2, 0)); 
        // base case
        dp[n][1] = 0; // 1: implies even number of nodes 
        dp[n][0] = numeric_limits<long long>::min();
        for (int i = n - 1; i >= 0; --i) {
            // j: 0 odd number of nodes XORed
            // j: 1 even number of nodes XORed
            for (int j = 0; j < 2; ++j) {
                // dont activate the node
                long long value = dp[i + 1][j] + nums[i]; 
                // activate the node
                long long actValue = dp[i + 1][1 - j] + (nums[i] ^ k);
                dp[i][j] = max(value, actValue); 
            }
        }
        return dp[0][1]; 
    }
};

/*
Note
- XOR is commutative
since the tree is a connected set of nodes, if we choose any pair of nodes 
to do XOR, all the nodes in between are effectively untouched
At the end only an even number of nodes will be affected by XOR

Solve the subproblem, at every node
1. we decide to activate the edge
2. don't activate the edge
dp[i][j] ith: nth node, jth: number of nodes XORed even(1) or not (0)
dp[x][1] = max(dp[x + 1][0] + value ^k, dp[x + 1][1])
dp[x][0] = max(dp[x + 1][1] + value ^k ,dp[x + 1][0])
base case:
# of nodes XORed is odd -> min_value (represent invalid case)

*/