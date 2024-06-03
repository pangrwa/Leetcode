class Solution {
public:
    int appendCharacters(string s, string t) {
        int ps = 0, pt = 0; 
        while (ps < s.size()) {
            if (pt == t.size()) 
                return 0; // t is within s
            if (s[ps] == t[pt]) {
                ps++;
                pt++; 
            } else {
                ps++; 
            }
        }
        return t.size() - pt; 
    }
};