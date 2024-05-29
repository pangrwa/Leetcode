class Solution {
public:
    vector<vector<int>> res; 
    vector<int> candidateBuilder;
    int scoreTracker = 0; 

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backtrack(0, candidates, target);
        return res; 
    }
    
    void backtrack(int idx, vector<int>& candidates, int target) {
        if (scoreTracker == target) {
            addResult(); 
            return; 
        }
        if (idx == candidates.size() || scoreTracker > target) {
            return; // bounds; 
        }
        // continue with this candidate
        scoreTracker += candidates[idx]; 
        candidateBuilder.push_back(candidates[idx]); 
        backtrack(idx, candidates, target); 

        // don't use this candidate at all
        scoreTracker -= candidates[idx];
        candidateBuilder.pop_back(); 
        backtrack(idx + 1, candidates, target); 
    }

    void addResult() {
        vector<int> copy = candidateBuilder; 
        res.push_back(copy); 
    }
};