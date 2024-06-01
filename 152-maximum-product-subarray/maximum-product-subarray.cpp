class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = numeric_limits<int>::min(); 
        int big = 1;
        int small = 1;
        for (int num : nums) {
            if (num < 0) {
                int temp = big; 
                big = small; 
                small = temp; 
            }
            big = max(num, big * num); 
            small = min(num, small * num); 
            res = max(res, big); 
        }
        return res; 
    }
};

/*
don't even need to find the subarray, just need the product

f(i) = max(f(i - 1) * current, current)
but take note that value can be negative, so we need to keep
track of the smallest product that we have too
*/ 