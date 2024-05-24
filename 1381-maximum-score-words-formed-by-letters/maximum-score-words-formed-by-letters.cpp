class Solution {
public:
    unordered_map<char, int> letterCount;
    unordered_map<char, int> wordCounter; 
    int res = numeric_limits<int>::min(); 
    int scoreTracer = 0; 

    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        for (int i = 0; i < letters.size(); ++i) {
            letterCount[letters[i]]++; 
        }

        backtrack(0, words, score);
        return res; 
    }

    void backtrack(int idx, vector<string>& words, vector<int>& score) {
        if (idx == words.size()) {
            res = max(res, scoreTracer); 
            return; 
        }
        // don't take current word
        backtrack(idx + 1, words, score); 

        // check if it's possible to take current word
        for (char c : words[idx]) {
            wordCounter[c]++; 
            scoreTracer += score[c - 'a'];
        }
        
        if (validToRemove()) {
            backtrack(idx + 1, words, score); 
        }

        // rollback
        for (char c : words[idx]) {
            wordCounter[c]--; 
            scoreTracer -= score[c - 'a']; 
        }
    }

    bool validToRemove() {
        for (const auto& pair : wordCounter) {
            if (letterCount[pair.first] < pair.second) {
                return false;
            }
        }
        return true; 
    }
};

/*

either take the word or dont take the word
- if possible, take the word and remove corresopnding letters
- else don't take the word 
basicaly form all the possible subsets of the words if possible
how do we determine if we have enough letters to give out? count
the letters we have left 
*/ 