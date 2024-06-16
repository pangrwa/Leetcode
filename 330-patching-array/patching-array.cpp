class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        unsigned int goal = 1; 
        int res = 0;
        int idx = 0;
        // include goal == n, because we need to hit the goal
        // which to get n, goal (is just the target)
        while (goal <= n) { 
            if (idx < nums.size() && goal >= nums[idx]) {
                // our current range of values is from 
                // [1, goal - 1], with nums[i], we can increase
                // our range to [1, goal - 1 + nums[i]]
                goal += nums[idx]; 
                idx++; 
            } else { 
                // goal < nums[i] -> can't derive that goal
                // so we add patch the value goal 
                goal += goal;
                res++;
            }
        }
        return res; 
    }
};

/*
[1] n =1 
from 1 -> n, we have a goal, the reason why we can times 2 everytime 
    we have that particular number, n, is because
    for all numbers before n, we could get 1 -> n -1, that
    means with n, we can get till n - 1
while if goal >= nums[i]
    we add the current number to form a new goal, because we know
    that we can derive all the numbers from 1 -> goal - 1

suppoes 1 5 10
goal: 
1
2 +1
4 +1
8
*/