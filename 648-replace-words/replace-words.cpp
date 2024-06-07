class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        istringstream ss(sentence); 
        unordered_set<string> root(dictionary.begin(), dictionary.end());
        string token; 
        string res; 
        while (getline(ss, token, ' ')) {
            res += shortestRoot(token, root) + " "; 
        }
        res.pop_back(); // remove last white space
        return res; 
    }

    string shortestRoot(string token, unordered_set<string> root) { 
        string builder = "";
        for (int i = 0; i < token.size(); i++) {
            builder += token[i]; 
            if (root.find(builder) != root.end()) {
                return builder; 
            }
        }
        return token; 
    }
};