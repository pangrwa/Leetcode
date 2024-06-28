class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        unordered_map<int, vector<int>> adjList;
        for (vector<int> road : roads) {
            adjList[road[0]].push_back(road[1]);
            adjList[road[1]].push_back(road[0]);
        }
        struct custom {
            bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
                return a.second < b.second;
            }
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, custom> maxHeap;
        for (const auto pair : adjList) {
            maxHeap.push(make_pair(pair.first, pair.second.size()));
        }
        
        long long label = n; 
        long long res = 0; 
        while (!maxHeap.empty()) {
            const pair<int, int>& p = maxHeap.top();
            // cout << "This is node: " << p.first << " neighbours: " << p.second << " value: " << p.second * label << '\n';
            res += (p.second * label);
            maxHeap.pop();
            label--;
        }
        return res;
    }
};

/*
maximise total importance of roads
cities with the most roads attached to it should have the highest importance

*/