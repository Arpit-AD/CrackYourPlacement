//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool cycleCheck_DFS(int V, vector<int> adj[], vector<int> & vis, vector<int> & pathVis, int node){
        vis[node] = 1;
        pathVis[node] = 1;
        
        for(int i : adj[node]){
            if(!vis[i]){
                if(cycleCheck_DFS(V, adj, vis, pathVis, i)) return true;
            }
            else if(pathVis[i]) return true;
        }
        
        pathVis[node] = 0;
        return false;
    }
    
    bool isCyclic(int V, vector<int> adj[]) {
        // code here 
        vector<int> vis(V, 0);
        vector<int> pathVis(V, 0);
        
        for(int i = 0; i < V;  i++){
            if(!vis[i]){
                if(cycleCheck_DFS(V, adj, vis, pathVis, i)) return true;
            }
        }
        
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends