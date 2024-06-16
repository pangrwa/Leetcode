class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size(); 
        if (n % groupSize != 0) { 
            return false; 
        }
        unordered_map<int, int> freq;
        for (int i = 0; i < n; ++i) { 
            freq[hand[i]] += 1;
        }

        for (int i = 0; i < n; ++i) {
            int startPoint = hand[i]; 
            while (freq.contains(startPoint - 1) && freq[startPoint - 1] > 0) {
                startPoint--; 
            }
            
            if (freq[startPoint] == 0) {
                continue; 
            }
            // form the hand
            for (int i = startPoint; i < startPoint + groupSize; ++i) { 
                if (!freq.contains(i) || freq[i] <= 0) { 
                    return false; // can't form the hand 
                }
                freq[i] -= 1; 
            }
        }
    
        return true; 
    }
};
/*
since all cards have to be in a particular group, easier to form hands
with the smallest possible starting points first 
*/