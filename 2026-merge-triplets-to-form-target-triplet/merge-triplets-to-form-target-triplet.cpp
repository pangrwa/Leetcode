class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        unordered_set<int> matches; 
        for (int i = 0; i < triplets.size(); ++i) {
            if (
                triplets[i][0] > target[0] ||
                triplets[i][1] > target[1] ||
                triplets[i][2] > target[2]
            ) {
                continue; // ignore these triplets
            }
            for (int j = 0; j < 3; ++j) {
                if (triplets[i][j] == target[j]) {
                    matches.insert(j); 
                }
            }
        }
        return matches.size() == 3; 
    }
};

/*
any triple that contains a value that is greater than target shouldnt 
be used at all not, cant reach the goal, because of the max property
only consider triples that have <= target value
*/