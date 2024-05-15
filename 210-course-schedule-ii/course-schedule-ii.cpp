class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> graph; 
        for (int i = 0; i < numCourses; ++i) {
            graph[i] = vector<int>(); 
        }
        for (const auto& p : prerequisites) {
            graph[p[1]].push_back(p[0]); 
        }

        vector<int> ordering; 
        unordered_map<int, int> visited;
        for (int i = 0; i < numCourses; ++i) {
            if (dfs(i, graph, visited, ordering)) {
                ordering.clear();
                return ordering;
            }
        }
        reverse(ordering.begin(), ordering.end()); 
        return ordering; 
    }

    bool dfs(int course, unordered_map<int, vector<int>>& graph, unordered_map<int, int>& visited, vector<int>& ordering) {
        if (visited.contains(course) && visited[course] == 2) {
            return true; 
        }
        if (visited.contains(course) && visited[course] == 1) {
            return false; 
        }
        visited[course] = 2; 
        bool containsCycle = false;
        for (int neigh : graph[course]) {
            containsCycle |= dfs(neigh, graph, visited, ordering); 
        }
        ordering.push_back(course);
        visited[course] = 1; 
        return containsCycle; 
    }




};

/*
1 -> 0 -> 4 -> 

b -> a
*/ 