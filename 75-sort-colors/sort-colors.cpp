class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> count(3, 0);
        for (int num : nums) {
            count[num]++; 
        }
        nums.clear();
        for (int i = 0; i < count.size(); ++i) {
            while (count[i] > 0) {
                nums.push_back(i);
                count[i]--; 
            }
        }
    }
};

/*
since it's a in-place algorithm we can write our own sorting algorithm in this case
    we could use merge sort but that will take up n space for combin
    we could use counting sort 
*/ 