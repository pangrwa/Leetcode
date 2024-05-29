class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict; 
        for (string s : wordDict) {
            dict.insert(s); 
        }
        vector<vector<string>> dp(s.size() + 1, vector<string>(0, ""));
        dp[0].push_back(""); 
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= i; ++j) {
                string curWord = s.substr(j, i - j + 1); 
                if (!dict.contains(curWord)) {
                    continue; 
                }
                for (string stn : dp[j]) {
                    string copy = stn; 
                    if (copy != "") {
                        copy += " ";
                    }
                    copy += curWord; 
                    dp[i + 1].push_back(copy); 
                }
            }
        }
        return dp[n]; 
    }
};

/*



iterate across each char in s
    iterate from 0 -> s
        if there's a valid string
            dp[i] = for all valid sentences in dp[j - 1] add this word
// the reason why we can assume that we will have a full sentence 
    is because if we try to start from somewhere in the middle instead
    of the start for example d[j], the vector length is empty
        hence there is no valid sentence for you to extend
    so all sentences have to start from the beginnign. 

catsanddog, "sand, dog"

*/ 