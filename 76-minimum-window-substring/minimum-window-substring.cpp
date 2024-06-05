class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> goal; 
        unordered_map<char, int> window; 
        int matches = 0;
        int resSize = numeric_limits<int>::max(); 
        int resPair[2] = {0, 0}; // base case

        for (char c : t) {
            goal[c]++; 
        }

        int left = 0;
        for (int right = 0; right < s.size(); ++right) {
            cout << right << endl; 
            char c = s[right];
            char leftC; 
            window[c]++; 

            if (goal.find(c) != goal.end()) {
                if (window[c] == goal[c]) {
                    matches++; 
                }
            }

            // if window matches the goal, shrink the window
            while (matches == goal.size()) {
                leftC = s[left]; 
                window[leftC]--; 
                // update res
                if (right - left + 1 < resSize) {
                    resSize = right - left + 1;
                    resPair[0] = left; 
                    resPair[1] = right; 
                }
                if (goal.find(leftC) != goal.end() && (window[leftC] < goal[leftC])) {
                    matches--; 
                }
                left++; 
            }
        }
        if (resSize == numeric_limits<int>::max()) {
            return ""; 
        }
        return s.substr(resPair[0], resPair[1] - resPair[0] + 1); 
    }
};

/*
1. keep track of the elements in the window
2. extend the right pointer of the window till all elements 
    satisfy in t
3. shrink the left pointer of the window until the minimum
    possible left pointer
4. update the result

how to determine whether or not the window matches t? e
*/ 