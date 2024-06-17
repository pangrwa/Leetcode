class Solution {
public:
    int numberOpen = 0;
    vector<vector<int>> memo; 
    vector<string> possible{ "(", "", ")"}; 

    bool backtrack(int idx, const string& s) {
        if (idx == s.size()) {
            if (numberOpen == 0) {
                return true; 
            }
            return false; 
        }
        if (memo[idx][numberOpen] != -1) {
            // cout << idx << " " << numberOpen << "used memo" << endl; 
            return memo[idx][numberOpen]; 
        }
        char cur = s[idx];
        bool result = false; 
        if (cur == '(') {
            numberOpen++; 
            result |= backtrack(idx + 1, s); 
            numberOpen--; 
        } else if (cur == ')') {
            // check if there's something to close with
            if (numberOpen > 0) { 
                numberOpen--; 
                result |= backtrack(idx + 1, s); 
                numberOpen++;
            }
        } else {
            numberOpen++; 
            result |= backtrack(idx + 1, s); 
            numberOpen--; 

            if (numberOpen > 0) {
                numberOpen--;
                result |= backtrack(idx + 1, s); 
                numberOpen++; 
            }

            result |= backtrack(idx + 1, s); 
        }
        memo[idx][numberOpen] = result;
        // if (result) {
        //     cout << memo[idx][numberOpen] << endl; 
        // } 
        return result;
    }

    bool checkValidString(string s) {
        memo = vector(s.size(), vector<int>(s.size(), -1));
        return backtrack(0, s);  
    }
};

/*
((*))
*/