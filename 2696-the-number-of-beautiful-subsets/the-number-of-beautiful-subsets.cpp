class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        map<int, map<int, int>> groups; // group_num -> sorted order of (ele, freq)
        // automatically in sorted order due to bst
        for (int i = 0; i < nums.size(); ++i) {
            groups[nums[i] % k][nums[i]]++; 
        }
        int res = 1;
        for (const auto& group : groups) {
            vector<pair<int, int>> cur(group.second.begin(), group.second.end());
            vector<int> dp(cur.size() + 1, 0); 
            dp[cur.size()] = 1; // base case
            for (int i = cur.size() - 1; i >= 0; --i) {
                // dont take current element
                int skip = dp[i + 1];
                // take current element
                // 2^freq: num of possible subsets it can form with each unique element
                int take = (1 << cur[i].second) - 1;
                if (i + 1 < cur.size() && (cur[i + 1].first - cur[i].first != k)) {
                    take *= dp[i + 1];
                } else if (i + 2 < dp.size()) {
                    take *= dp[i + 2]; 
                }
                // total number of sets formed by i and the eleemnts on the right
                dp[i] = skip + take;
            }
            res *= dp[0];
        }
        return res - 1; // remove empty set
    }
};

/*
How to solve the problem without generating all the subarrays? 
form groups from the nums

what kind of groups can we form? 
groups, g1 ,g2 such that any element a from g1 and b from g2
    won't have an absolute difference to k 

how do we form such groups?
note the property of modulo
    - for values that have absolute difference of k
    - a % k = (a + k) % k = (a - k) % k 
    - we can put these values in the same group, then this will
        satisfy the property above
Find all the beautiful pairs of each group and then cross multiply to form 
    crossing subsets and this will stil be beautiful because of the condition we set

how to find beautiful pairs of each group?
supppose the values in the group are in sorted order (Similar concept to backtracking)
f(i) = 
    1. dont take current element to form beautiful pair, f(i + 1)
    2. take current element f(i + 1) only if it doesn't have abs diff of k or else f(i + 2) 
*/