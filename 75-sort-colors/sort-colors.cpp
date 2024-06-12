class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int left = 0, right = nums.size() - 1; 
        for (int i = 0; i < nums.size(); ++i) {
            while (i >= left && i <= right && (
                (nums[i] == 0 || nums[i] == 2)
            )) {
                if (nums[i] == 0) {
                    swap(nums[left++], nums[i]); 
                } else {
                    swap(nums[right--], nums[i]); 
                }
            }
        }
    }
};

/*
since it's a in-place algorithm we can write our own sorting algorithm in this case
    we could use merge sort but that will take up n space for combin
    we could use counting sort in O(1) space but that is not in 1 pass
How we could do it in 1 pass
    - identify 3 elements -> move 2 the back and 0 to the front
        the issue with appending element to the front is it take 
        O(n) space
    - use two pointers to guide where to swap 0s and 2s with
*/ 