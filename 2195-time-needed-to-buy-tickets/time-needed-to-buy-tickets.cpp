class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<int> people; 
        for (int i = 0; i < tickets.size(); ++i) {
            if (tickets[i] > 0) people.push(i); 
        }
        int time = 0;
        while (!people.empty()) {
            int curIdx = people.front(); 
            people.pop();
            tickets[curIdx] -= 1;
            time++; 
            if (curIdx == k && tickets[curIdx] == 0) {
                return time; 
            }
            if (tickets[curIdx] > 0) people.push(curIdx);
        }
        return -1; 
    }
};