class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> counter; 
        for (char c : s) {
            counter[c] += 1;
        }
        vector<deque<pair<char, int>>> pali(2);
        for (const auto& p : counter) {
            if (p.second > 1) {
                pali[0].push_back(make_pair(p.first, p.second)); 
            } else {
                pali[1].push_back(make_pair(p.first, p.second)); 
            }
        }

        int res = 0; 
        while (pali[0].size() > 0) {
            pair<char, int> fnt = pali[0].front(); 
            pali[0].pop_front(); 
            res += 2; 
            fnt.second -= 2; 

            if (fnt.second == 1) {
                pali[1].push_back(fnt); 
            } else if (fnt.second > 1) {
                pali[0].push_back(fnt); 
            }
        }

        if (!pali[1].empty()) {
            res++; 
        }
        return res; 
    }
};

/*
for odd lengths-> only middle character can be 1 
for even lengths -> all charactesr must have a matching pair (even)

while possible charactesr with even length

*/