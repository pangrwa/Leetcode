class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res; 
        int top = 0, btm = matrix.size() - 1;  
        int left = 0, right = matrix[0].size() - 1; 
        
        while (top <= btm && left <= right) {
            cout << top << btm << left << right << endl; 
            for (int i = left; i <= right; ++i) {
                res.push_back(matrix[top][i]); 
            }
            top++; // handled top row
            for (int i = top; i <= btm; ++i) {
                res.push_back(matrix[i][right]); 
            }
            right--; // handle right column
            // check if completed to prevent duplicate reads
            if (top > btm || left > right) {
                break; 
            }
            for (int i = right; i >= left; --i) {
                res.push_back(matrix[btm][i]); 
            }
            btm--; // handle btm row
            for (int i = btm; i >= top; --i) {
                res.push_back(matrix[i][left]);
            }
            left++; // handle left column
        }
        return res; 

    }
};

/*
1
1
*/ 