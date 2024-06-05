class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> res(26, 100); 
        for (string s : words) { 
            vector<int> match(26, 0); 
            for (char c : s) { 
                if (res[c - 'a'] > 0) {
                    match[c - 'a']++; 
                    res[c - 'a']--;
                }
            }
            res = match; 
        }

        vector<string> sln;
        for (int i = 0; i < res.size(); ++i) {
            for (int j = 0; j < res[i]; ++j) {
                sln.push_back(string(1, i + 'a')); 
            }
        }
        return sln; 
    }
};