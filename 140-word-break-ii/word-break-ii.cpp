class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict; 
        for (const auto& s : wordDict) {
            dict.insert(s); 
        }

        vector<vector<string>> dp(s.size() + 1, vector<string>(0, ""));
        unordered_set<int> validIdx;
        dp[0].push_back(""); 
        validIdx.insert(-1); 
        
        for (int i = 0; i < s.size(); ++i) {
            for (int j = 0; j <= i; ++j) {
                string cur = s.substr(j, i - j + 1); 
                if (dict.contains(cur) && validIdx.contains(j - 1)) {
                    for (const auto& s : dp[j]) {
                        string stn = s; // make a copy
                        if (s != "") {
                            stn += " "; 
                        }
                        stn += cur; 
                        dp[i + 1].push_back(stn); 
                    }
                    validIdx.insert(i); 
                }
            }
        }
        return dp[s.size()]; 
    }
};

/*
how do we break the problem down? 
catsand         dog 
(subproblem)    (if this is in dict, add to subproblem) 
the subproblem must also contains a valid sentence
example: catsan ddo if ddo is a valid word but catsan didnt form a 
    valid sentence, this would be invalid

f(i) = all(f(j) + s[j..i]) where j: 0 -> i and s[j..i] in dict and f(j) 
    contains valid sentences 
base case: f(0) = ""
and valid.insert(0)

how to to know if f(j) contains valid sentences? 
we keep track of the indices where it's possible to break into valid 
    sentences

iterate across the string
for each char i, represents the end of a possible word we're forming
    iterate from start to that char, j
        if the word s[j..i] is in the dicitonary
            for  all the sentences in the subproble dp[j] (valid.contains(j))
                dp[i].append(setence + " "  + s[j..i])
return dp[n] 

*/ 