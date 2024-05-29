class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> counter;
        int res = 0;
        int maxfreq = 0; 
        for (int i : nums) {
            counter[i]++; 
            if (counter[i] > maxfreq) {
                maxfreq = counter[i]; 
                res = 0; 
            }
            if (counter[i] == maxfreq) res+=maxfreq; 
        }
        return res; 
    }
};

/*
iterate once
if encontered a higher freq that we have seen
    reset solution to 0
*/