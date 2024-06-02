class Solution {
public:
    vector<int> parents; 
    vector<int> rank;

    int parent(int node) {
        if (parents[node] == node) {
            return node; // itself is the parent
        }
        // update to point to it's top most parent;
        parents[node] = parent(parents[node]); 
        return parents[node]; 
    }

    bool isSameSet(int a, int b) {
        return parent(a) == parent(b); 
    }

    bool unionSet(int a, int b) { 
        if (isSameSet(a, b)) return false; 
        a = parent(a); 
        b = parent(b); 
        if (rank[a] < rank[b]) { // connect tree of a to b;
            parents[a] = parent(b); 
        } else {
            parents[b] = parent(a); // connect tree of b to a; 
            if (rank[a] == rank[b]) {
                rank[a] += 1; // increase depth by 1
            }
        }
        return true; 
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        for (int i = 0; i < n; ++i) {
            parents.push_back(i); // each node represents itself
            rank.push_back(1); // rank of 1

        }

        for (const auto& edge :edges) {
            int a = edge[0] - 1, b = edge[1] - 1;
            if (!unionSet(a, b)) {
                return edge; // means a and b are already unioned
            }
        }
        return {}; // impossible
    }
};