class Udfs {
public:
    vector<int> parents; 
    vector<int> rank;

    Udfs(int n) {
        for (int i = 0; i < n; ++i) {
            parents.push_back(i);
            rank.push_back(1); 
        }
    }

    int getParent(int node) {
        if (parents[node] == node) {
            return node;
        }
        parents[node] = getParent(parents[node]);
        return parents[node];
    }

    int isEqual(int x, int y) {
        return getParent(x) == getParent(y); 
    }

    bool merge(int x, int y) {
        int a = getParent(x);
        int b = getParent(y);
        if (a == b) {
            return false;
        }
        if (rank[a] < rank[b]) {
            parents[a] = b;
        } else {
            if (rank[a] == rank[b]) {
                rank[a] += 1;
            }
            parents[b] = a; 
        }
        return true;
    }

    bool isConnected() {
        for (int i = 0; i < parents.size() - 1; ++i) {
            if (getParent(i) != getParent(i + 1)) {
                return false;
            }
        }
        return true;
    }
    void print() {
        cout << "Parents: ";
        for (int i = 0; i < parents.size(); ++i) {
            cout << parents[i] << " ";
        }
        cout << endl;
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        Udfs alice{n};
        Udfs bob{n}; 
        // handle all the type 3 edges first
        int res = 0;
        for (const auto& edge : edges) {
            if (edge[0] != 3) {
                continue;
            }
            if (alice.merge(edge[1] - 1, edge[2] - 1)) {
                bob.merge(edge[1] - 1, edge[2] - 1);
                res++;
            }
        }
        for (const auto& edge : edges) {
            if (edge[0] == 1) {
                if (alice.merge(edge[1] - 1, edge[2] - 1)) {
                    res++;
                }
            }
            if (edge[0] == 2) {
                if (bob.merge(edge[1] - 1, edge[2] - 1)) {
                    res++;
                }
            }
        }
        // alice.print();
        // bob.print();
        if (!alice.isConnected() || !bob.isConnected()) {
            return -1;
        }
        return edges.size() - res; 
    }
};

/*
type 3 edge is the best, remove other edge if theres a contention with type 3
we can use the property of union find and check whether or not the nodes are connected
*/