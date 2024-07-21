class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> graphRev[n];
        vector<int> safeNodes;
        vector<int> indegree(n, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < graph[i].size(); j++) {
                graphRev[graph[i][j]].push_back(i);
                indegree[i]++;
            }
        }
        queue<int> que;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0)
                que.push(i);
        }

        while (!que.empty()) {
            int node = que.front();
            que.pop();
            safeNodes.push_back(node);
            for (int it : graphRev[node]) {
                indegree[it]--;
                if (indegree[it] == 0)
                    que.push(it);
            }
        }
        sort(safeNodes.begin(), safeNodes.end());
        return safeNodes;
    }
};