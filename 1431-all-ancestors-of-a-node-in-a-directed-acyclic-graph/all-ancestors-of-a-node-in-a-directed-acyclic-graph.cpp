class Solution {
public:
    vector<vector<int>> adjList;
    vector<vector<int>> reverseGraph; 
    void buildGraph(int n, vector<vector<int>>& edges) {
        adjList = vector(n, vector<int>());
        for (vector<int>& edge : edges) {
            adjList[edge[0]].push_back(edge[1]);
        }
    }

    void buildReverseGraph(int n, vector<vector<int>>& edges) {
        reverseGraph = vector(n, vector<int>()); 
        for (vector<int>& edge : edges) { 
            reverseGraph[edge[1]].push_back(edge[0]);
        }
    }

    void dfs(int node, vector<int>& ordering, vector<bool>& visited) {
        visited[node] = true;
        for (int neigh : adjList[node]) {
            if (visited[neigh]) { 
                continue; 
            }
            dfs(neigh, ordering, visited);
        }
        ordering.push_back(node);
    }

    vector<int> topoSort(int n) {
        // get start points
        vector<bool> visited(n, false);
        vector<int> ordering;
        for (int i = 0; i < n; ++i) {
            if (visited[i]) {
                continue;
            }
            dfs(i, ordering, visited); 
        }
        reverse(ordering.begin(), ordering.end());
        return ordering; 
    }
    // void printAncestors(int cur, vector<vector<int>>& ancs) {
    //     cout << "Current: " << cur << " Ancs: [";
    //     for (int neigh : ancs[cur]) {
    //         cout << neigh << " ";
    //     }
    //     cout << '\n';
    // }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        buildGraph(n, edges);
        vector<int> ordering = topoSort(n);
        // reversed graph
        buildReverseGraph(n, edges);
        vector<unordered_set<int>> ancestors(n, unordered_set<int>());
        for (int node : ordering) {
            unordered_set<int>&  cur = ancestors[node];
            for (int neigh : reverseGraph[node]) {
                cur.insert(neigh);
                for (int ancs : ancestors[neigh]) {
                    cur.insert(ancs);
                }
            }
            // printAncestors(node, res); 
        }
        vector<vector<int>> res(n, vector<int>());
        for (int i = 0; i < ancestors.size(); ++i) {
            for (int set : ancestors[i]) {
                res[i].push_back(set);
            }
            sort(res[i].begin(), res[i].end());
        }
        return res; 
    }
};

/*
topological sort? 
- gives us the ordering to visit the nodes
- since we want to know what are our ancestors
- reverse the graph and visit the nodes in the topological sort ordering
*/ 