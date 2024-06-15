class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size(); 
        priority_queue<int, vector<int>, std::less<int>> bestProject; 
        vector<pair<int, int>> projects; 
        int idx = 0; // projects tracker; 
        int count = 0; 
        
        for (int i = 0; i < n; ++i) {
            projects.push_back(make_pair(profits[i], capital[i])); 
        }
        sort(projects.begin(), projects.end(), [](
            const pair<int, int>& p1, const pair<int, int>& p2
        ) {
            return p1.second < p2.second; // sort increasing order by capital value
        });

        while (count < k) {
            // fill in the best projects first
            while (idx < n && (projects[idx].second <= w)) {
                bestProject.push(projects[idx].first); 
                idx++; 
            }

            if (bestProject.empty()) {
                break; // no more project left to use
            }

            int v = bestProject.top();
            bestProject.pop(); 
            w += v; 
            
            count++; 
        }
        return w; 
    }
};