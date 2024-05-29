class Solution {
public:
    unordered_map<char, int> lettersUsed; 
    unordered_map<char, int> lettersHave;
    int scoreTracker = 0; 
    int res = 0; 

    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        for (char c : letters) {
            lettersHave[c]++; 
        }
        backtrack(0, words, score); 
        return res; 
    }

    void backtrack(int idx, vector<string>& words, vector<int>& score) { 
        if (idx == words.size()) {
            res = max(res, scoreTracker); 
            return; 
        }

        // don't use the current word
        backtrack(idx + 1, words, score); 

        // use the current word
        string cur = words[idx]; 
        for (char c : cur) { 
            lettersUsed[c]++;
            lettersHave[c]--; 
            scoreTracker += score[c - 'a']; 
        }
        // check if valid to use current word
        bool ready = true; 
        for (char c : cur)  {
            if (lettersHave[c] < 0) { // invalid use
                ready = false; 
            }
        }

        if (ready) {
            backtrack(idx + 1, words, score); 
        }

        // remove it
        for (char c : cur) {
            lettersUsed[c]--;
            lettersHave[c]++; 
            scoreTracker -= score[c - 'a']; 
        }
    }
};

/*
basically like forming subsets of the words
- either choose the current word or not
- how to know if we can choose the current word or not? 
    - keep track of the remaining letters, and check if the freq letters
        matches with the word
    
If we use DP, we have to track the remaining letters from the previous
subproblem 
*/ 
