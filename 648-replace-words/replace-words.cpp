class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        string token; 
        stringstream ss(sentence);
        vector<string> s;
        while (getline(ss, token, ' ')) {
            s.push_back(token); 
        }
        unordered_set<string> root(dictionary.begin(), dictionary.end()); 
        string res = ""; 

        for (int i = 0; i < s.size(); ++i) {
            string word = s[i]; 
            string builder = "";
            bool hasRoot = false; 
            for (char c : word) {
                builder += string(1, c); 
                if (root.find(builder) != root.end()) {
                    res += builder;
                    hasRoot = true; 
                    break; 
                }
            }
            if (!hasRoot) {
                res += builder; 
            }

            if (i < s.size() - 1) {
                res += " "; 
            }
        }

        return res; 
    }
};
/*
brute force approach iterate each word in the sentence
    the moment we find the first matching (also the shortest matchign)
    replace it
*/ 