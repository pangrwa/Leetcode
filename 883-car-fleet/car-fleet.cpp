class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> car;
        for (int i = 0; i < position.size(); ++i) {
            car.push_back(make_pair(position[i], speed[i])); 
        }
        sort(car.begin(), car.end(), [](const auto& p1, const auto& p2) {
            return p1.first > p2.first; 
        });
        printCar(car); 
        stack<double> fleetTime; 
        for (int i = 0; i < car.size(); ++i) {
            double time = ((double) target - car[i].first) / car[i].second;
            if (fleetTime.size() != 0 && fleetTime.top() >= time) {
                continue; 
            }
            fleetTime.push(time); 
        }
        return fleetTime.size(); 
    }

    void printCar(vector<pair<int, int>>& car) {
        for (int i = 0; i < car.size(); ++i) {
            cout << "Position: " << car[i].first << " Speed: " << car[i].second << endl; 
        }
    }
};

/*
determine which cars are closer to the target first, if the car behind
is able to which the car infront in a shorter time, then they merge

1. sort in decreasing order of position
2. iterate i and i - 1 
    if i faster than i - 1, means will defo merge along the way
    need a way to keep of speed of the fleet, hence increasing stack
*/ 