class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> lastPosition; 
        int n = s.size(); 
        for (int i = 0; i < n; ++i) { 
            lastPosition[s[i]] = i; 
        }
        int left = 0;
        vector<int> res; 
        while (left < n) {
            int cur = left; 
            int right = cur; 
            while (right < n && cur <= right) { 
                right = max(right, lastPosition[s[cur]]);
                cur++; 
            }
            res.push_back(right - left + 1);
            left = right + 1; // goes into new partition
        }
        return res; 
    }
};

/*
to know that a part contains all possible choice for that letter
, we need to create a hashmap beforehand
have 2 pointers, 
 the first pointer represent the start of every part
 the second pointer represents the furthest it must go within that window

*/