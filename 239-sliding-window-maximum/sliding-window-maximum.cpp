class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> maxValues;
        vector<int> res; 
        int left = 0;
        for (int right = 0; right < nums.size(); ++right) { // act as right pointer
            int cur = nums[right];
            // keep decreasing stack 
            while (!maxValues.empty() && nums[maxValues.back()] <= cur) {
                maxValues.pop_back(); 
            }
            maxValues.push_back(right); // guarentees a singe max value 
            // clear out of bounds 
            while (maxValues.front() < left) {
                maxValues.pop_front(); 
            }

            if (right - left + 1 == k) { // possible window
                res.push_back(nums[maxValues.front()]); // max value of the window
                left++; 
            }
        }
        return res; 
    }
};

/*
keep track of the possible max values we can use for each window
we create a decreasing stack that stores all the max values that we have
    seen, this acts as a possible max value for the current window
the reason why we store a decreasing stack is because we need to clear
    the elements on the left in case if its not within the window and
    the remaining values are "backup" max values
*/ 