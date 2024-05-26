class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int> subseq; 
        for (int num : nums) {
            // if contains a larger value
            if (subseq.empty() || num > subseq.back()) {
                subseq.push_back(num); 
            } else { 
                auto lower = lower_bound(subseq.begin(), subseq.end(), num); 
                // finds the first value that is >= num
                // replace that with num, since num <= x
                // which num can be used to "represent" x for subsequences since <=
                subseq[std::distance(subseq.begin(), lower)] = num; 
            }
        }
        return subseq.size() >= 3; 
    }
};