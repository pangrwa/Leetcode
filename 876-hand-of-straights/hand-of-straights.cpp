class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize) {
            return false; // impossible to split into those groups
        }
        // find all possible starting points
        unordered_map<int, int> freq;
        deque<pair<int , int>> startPoints; 
        for (int i : hand) {
            freq[i]++; 
        }
        for (const auto& pair : freq) {
            if (freq.find(pair.first - 1) == freq.end()) {
                startPoints.push_back(make_pair(pair.first, freq[pair.first]));
            }
        }
        while (!startPoints.empty()) {
            pair<int, int> p1 = startPoints.front(); 
            startPoints.pop_front(); 

            // generate hand
            int handValue = p1.first; 

            int count = 0;
            int hand[groupSize]; 

            while (freq.find(handValue) != freq.end() && 
                (freq[handValue] > 0) &&
                (count < groupSize)
            ) {
                hand[count] = handValue; 
                count++; 

                freq[handValue]--; // used up for hand
                handValue = handValue + 1; 
            }
            // not enough to generate a hand for this start point
            if (count < groupSize) {
                return false; 
            }

            // find the next start point
            int pnStart = p1.first;  
            while (freq.find(pnStart) != freq.end()) {
                if (freq[pnStart] > 0) {
                    startPoints.push_back(make_pair(pnStart, freq[pnStart]));
                    break; 
                }
                pnStart++; 
            }
        }
        return true;
    }
};

/*
note
- cards cant be reused
- base case, number of cards must be divisble by groupSize

brute force approach? 
- Multiple iterations to form groups:
    - doesn't work because each time you form a group you need to keep
        track of what remaining characters that you are left with
- backtracking
    - that only works if you're trying to find all possible 
        groupSize that consists of groupSize cards
    - Suppose: [1 2 3 4]: back track would give [1 2] and [2 3]
    - but these pairs while valid can't form a group 
    - if I try to do [2 3 1 4 4 5], I'll get [2 3] first and if I
        do some condtion to make sure i can form a group (only use 1 element once)
        that would prevent me from detecing [1 2] as a correct pair which is the sln

smarter approaches
- DP
    - can't find a suitable suboptimal solution, can't break the problem 
        into smaller problems
- greedy    
    - find all possible starting points within the hand
    - greedily form all possible hands with those starting points
        - motivation: because for sln to be possible all starting
            points have to be in the sln which means they must 
            be the starting points of each group too. 
*/ 