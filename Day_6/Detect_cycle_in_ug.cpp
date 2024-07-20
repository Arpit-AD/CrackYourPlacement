//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool checkForCycle_DFS(vector<int> adj[], vector<int> & vis, int node, int par){
        vis[node] = 1;
        
        for(int i : adj[node]){
            if(vis[i] == 0){
                if(checkForCycle_DFS(adj, vis, i, node)) return true;
            }
            else if(i != par) return true;
        }
        
        return false;
    }
    
    bool getByDFS(int n, vector<int> adj[]){
        vector<int> vis(n, 0);
        
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                if(checkForCycle_DFS(adj, vis, i, -1)) return true;
            }
        }
        
        return false;
    }
    
    bool getByBFS(int n, vector<int> adj[]){
        vector<int> vis(n, 0);
        
        queue<pair<int,int>> que;
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                que.push({i, -1});
                
                while(!que.empty()){
                    pair<int, int> pr = que.front();
                    int node = pr.first;
                    vis[node] = 1;
                    int parent = pr.second;
                    que.pop();
                    
                    for(int adjacentNode: adj[node]){
                        if(!vis[adjacentNode]){
                            vis[adjacentNode] = 1;
                            que.push({adjacentNode, node});
                        }
                        else if(adjacentNode != parent) return true;
                    }
                }
            }
        }
        
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        // return getByDFS(V, adj);
        return getByBFS(V, adj);
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends