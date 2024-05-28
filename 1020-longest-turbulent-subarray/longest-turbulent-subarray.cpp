class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int left = 0;
        int n = arr.size(); 
        int res = 1; // itself
        for (int right = 1; right < n; ++right) {
            cout << "left: " << left << " right: " << right << endl; 
            if (arr[right - 1] == arr[right]) {
                left = right; 
                continue; 
            }
            if (right == n- 1) {
                res = max(res, right - left + 1); 
                continue; 
            }
            if (arr[right - 1] < arr[right]) {
                if (arr[right] <= arr[right + 1]) {
                    res = max(res, right - left + 1); 
                    left = right; 
                    continue; 
                }
            }
            if (arr[right - 1 ] > arr[right]) {
                if (arr[right] >= arr[right + 1]) {
                    res = max(res, right - left + 1); 
                    left = right; 
                    continue; 
                }
            }
        }
        return res; 
    }
};


/*
12
left and right pointer to keep track of the window
122
right starts at index 1;
if i - 1 == i: # 112, move left pointer to current and continue
if i - 1 < i: 
    if i <= i + 1: # 123 or 122 reset window, move left to cur
if i - 1 > i: 
    if i >= i + 1: # 321 or 221 reset window, move left to cur

passes all this check -> update max window we have seen

*/ 