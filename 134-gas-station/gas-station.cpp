class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size(); 
        int totalNetCost = 0;
        int tripNetCost = 0;
        int startPoint = 0; 
        for (int i = 0; i < n; ++i) {
            tripNetCost += gas[i] - cost[i]; 
            totalNetCost += gas[i] - cost[i];
            if (tripNetCost < 0) { 
                startPoint = i + 1; // take the next start point
                // doesn't matter if it exceeds n, because at that point
                // if it exists totalNetCost would be < 0
                tripNetCost = 0; 
            }
        }
        return totalNetCost >= 0 ? startPoint : -1; 
    }
};

/*
GENERAL APPROACH
-> find the last station with the highest net cost
-> from there go backwards and check if there's a station with another
    gas to bring the car to the highest net cost
-> that gas station should be the starting point to accumulate as
    much gas as possible

SMARTER approach
for a car to cycle around, the net gas for the entire trip must be
    >= 0 
for the best starting point, the cumulative trip should be positive. 
we can track the small trip net cost of gas and the total net cost
    -> at the end if total net cost >= 0 possible to cycle around
    -> 



can start at any of the gas stations
which station would you want to start? 
since you can store unlimited fuel in the car, you to accumulate as much
gas in the car as you possible can, you can't rearange the position 
    of the gas stations

start at a gas station where you you can top up fuel more than you
    consume to reach the next gas station
    -> can't just assume that first gas station we see this will work
        because it could be the case where it's only enough to bring to
            the next station and thn can't carry on afterwards  
    -> rather we have to start from the first gas station then gives us the
        highest net cost. but this doesn't gurantee too
        consider the case where a high net cost only brings you to a station
            then you not enough gas
        but if there exists a small +ve net gas station before the highest net
            it could be used to "boost it"
*/