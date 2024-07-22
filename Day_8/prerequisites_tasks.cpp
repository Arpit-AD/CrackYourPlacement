class Solution {
public:
    bool isPossible(int N,int P, vector<pair<int, int> >& prerequisites) {
        // Code here
        vector<int> adj[N];
        for(auto it : prerequisites){
            adj[it.second].push_back(it.first);
        }
        
        int indegree[N] = {0};
        for(int i = 0; i < N; i++) {
            for(auto it : adj[i])
                indegree[it]++;
        }
        
        queue<int> q;
        for(int i = 0; i < N; i++) {
            if(indegree[i] == 0)
                q.push(i);
        }
        int finishedTask = 0;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            finishedTask++;
            for(auto it : adj[node]) {
                if(--indegree[it] == 0)
                    q.push(it);
            }
        }
        if(finishedTask != N) return false;
        return true;
    }
};

