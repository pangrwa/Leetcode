class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int left = 0, right = 0; 
        int windowValue = 0;
        int res = 0; 
        while (right < s.size()) {
            if (s[right] != t[right]) {
                windowValue += abs(s[right] - t[right]);
                while (windowValue > maxCost) {
                    windowValue -= abs(s[left] - t[left]); 
                    left++;
                }
                
            }
            res = max(res, (right - left + 1));
            right++; 
        }
        return res; 
    }
};

/*
the order matters, so every character within the string has to change
for the best possible outcome
only interested in a substring of s, so we can do a sliding window

iterate across both strings
    if current is same: continue
    else:
        add cost to change
        while cost of window > maxCost: update left pointer
*/ 