class Solution {
public:
    void print(deque<int> temp) {
        while (!temp.empty()) {
            cout << temp.front() << " ";
            temp.pop_front(); 
        }
        cout << endl; 
    }
    int longestSubarray(vector<int>& nums, int limit) {
        int left = 0;
        int right = 0;
        int n = nums.size(); 
        int res = 0;
        deque<int> maxElements;
        deque<int> minElements;
        while (right < n) {
            int cur = nums[right];
            while (!maxElements.empty() && cur >= nums[maxElements.back()]) {
                maxElements.pop_back();
            }
            maxElements.push_back(right);
            while (!minElements.empty() && cur <= nums[minElements.back()]) {
                minElements.pop_back();
            }
            minElements.push_back(right);
            while (left <= right && abs(nums[maxElements.front()] - nums[minElements.front()]) > limit) {
                left++; 
                // clear the of bounds stack idx
                while (maxElements.front() < left) {
                    maxElements.pop_front();
                }
                while (minElements.front() < left) {
                    minElements.pop_front(); 
                }
            }
            res = max(res, right - left + 1);
            right++;
        }
        return res;
    }
};