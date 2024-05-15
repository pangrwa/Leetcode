class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int ROWS = mat.size();
        int COLS = mat[0].size(); 
        vector<int> rowSum(ROWS, 0); 
        vector<int> colSum(COLS, 0); 
        for (int i = 0; i < ROWS; ++i) {
            for (int j = 0; j < COLS; ++j) {
                rowSum[i] += mat[i][j]; 
                colSum[j] += mat[i][j]; 
            }
        }
        int res = 0;
        for (int i = 0; i < ROWS; ++i) {
            for (int j = 0; j < COLS; ++j) {
                if (mat[i][j] == 1 && rowSum[i] == 1 && colSum[j] == 1) {
                    res += 1; 
                }
            }
        }
        return res; 
    }
};