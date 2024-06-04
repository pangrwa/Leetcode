class Solution {
public:
    int longestPalindrome(string s) {
        unordered_set<char> tracker;
        int res = 0; 
        for (char c : s) {
            if (tracker.contains(c)) {
                tracker.erase(c);
                res += 2; 
            } else {
                tracker.insert(c); 
            }
        }
        return tracker.size() > 0 ? res + 1 : res; 
    }
};

/*
iterate through the string, if there's match in the tracker
- means we have matching pair

at the end if tracker have elements inside means, we can use it
    for our middle element
*/