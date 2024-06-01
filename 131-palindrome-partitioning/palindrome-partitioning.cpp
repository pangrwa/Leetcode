class Solution {
public:
    vector<vector<string>> res; 
    vector<string> tracker; 
    vector<vector<string>> partition(string s) {
        backtrack(s, 0); 
        return res; 
    }
    void backtrack(string s, int left) {
        if (left == s.size()) {
            vector<string> copy(tracker.begin(), tracker.end()); 
            res.push_back(copy); 
        }
        for (int i = left; i < s.size(); ++i) {
            if (isPalindrome(s, left, i)) {
                tracker.push_back(s.substr(left, i - left + 1)); 
                backtrack(s, i + 1); 
                tracker.pop_back(); 
            }
        }
    }

    bool isPalindrome(string s, int left, int right) {
        while (left <= right) {
            if (s[left] != s[right]) return false;
            left++;
            right--;
        }
        return true; 
    }
};

/*
how do we break the string into substrings? 
iterate from the start -> end
    start -> i if it's a palidrome -> solve the sbproblem of i -> e
    else ignore
*/ 