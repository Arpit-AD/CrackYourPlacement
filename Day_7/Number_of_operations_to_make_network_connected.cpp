class Solution {
public:
    int findParent(vector<int>& par, int node) {
        if (node == par[node])
            return node;
        return par[node] = findParent(par, par[node]);
    }

    void unionByRank(vector<int>& par, vector<int>& rank, int nodeA,
                     int nodeB) {
        int rootA = findParent(par, nodeA);
        int rootB = findParent(par, nodeB);

        if (rootA != rootB) {
            if (rank[rootA] < rank[rootB]) {
                par[rootB] = rootA;
            } else if (rank[rootB] < rank[rootA]) {
                par[rootA] = rootB;
            } else {
                par[rootA] = rootB;
                rank[rootB]++;
            }
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1)
            return -1;

        vector<int> par(n + 1);
        vector<int> rank(n + 1, 0);

        for (int i = 0; i <= n; i++)
            par[i] = i;

        for (auto it : connections) {
            int u = it[0], v = it[1];

            if (findParent(par, u) != findParent(par, v)) {
                unionByRank(par, rank, u, v);
            }
        }

        int count = 0;
        for (int i = 0; i < n; i++) {
            if (par[i] == i)
                count++;
        }

        return count - 1;
    }
};