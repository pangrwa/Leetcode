class Solution {
    public int maxSatisfied(int[] customers, int[] grumpy, int minutes) {
        int baseScore = 0; 
        int n = customers.length;
        for (int i = 0; i < n; ++i) {
            if (grumpy[i] == 0) {
                baseScore += customers[i]; 
            }
        }
        int left = 0;
        int right = 0;
        int res = baseScore;
        int window = 0;
        while (right < n) {
            if (grumpy[right] == 1) {
                window += customers[right]; 
            }
            if ((right - left + 1) == minutes) {
                res = Math.max(res, baseScore + window); 
                if (grumpy[left] == 1) {
                    window -= customers[left]; 
                }
                left++; 
            }
            right++; 
        }
        return res; 
    }
}