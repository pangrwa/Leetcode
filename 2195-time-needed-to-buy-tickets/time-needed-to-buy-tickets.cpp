class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int numTickets = tickets[k]; // minimally number of rounds; 
        int time = 0; 
        for (int i = 0; i < tickets.size(); ++i) {
            if (i <= k) {
                time += min(numTickets, tickets[i]); 
            }
            else {
                time += min(numTickets - 1, tickets[i]); 
            } 
        }
        return time; 
    }
};
/*
if person infront me has >= tickets as me, then i need to wait
the same number of rounds as me
but if the person infront of me < tickets then me, then i only
need to wait his number of rounds (while he is in the queue) 

what about the person behind me? 
if they have more tickets than me, then i only need to wait numTickets -1
round since on the last round, i'll be infornt of them and it'll be over
if they have less tickets than me, then it just their tickets
*/