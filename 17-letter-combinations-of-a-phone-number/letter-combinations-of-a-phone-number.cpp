class Solution {
public:
    unordered_map<int ,vector<string>> mappings = 
    {
        {2, {"a", "b", "c"}},
        {3, {"d", "e", "f"}},
        {4, {"g", "h", "i"}},
        {5, {"j", "k", "l"}},
        {6, {"m", "n", "o"}},
        {7, {"p", "q", "r", "s"}},
        {8, {"t", "u", "v"}}, 
        {9, {"w", "x", "y", "z"}}
    };
    vector<string> res; 
    vector<string> tracker; 

    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) {
            return {};
        }
        backtrack(0, digits); 
        return res; 
    }
    
    void backtrack(int idx, string digits) {
        if (idx == digits.size()) {
            string s = ""; 
            for (string c : tracker) {
                s += c; 
            }
            res.push_back(s); 
            return; 
        }

        for (string a : mappings[digits[idx] - '0']) {
            tracker.push_back(a);
            backtrack(idx + 1, digits); 
            tracker.pop_back(); 
        }
    }
};