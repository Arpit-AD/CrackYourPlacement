//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	void dfs(vector<vector<int>> &adj,  vector<int> & visited, int node, bool withStack, stack<int> &st){
	    visited[node] = 1;
	    for(int i : adj[node]){
	        if(visited[i] == 0){
	            dfs(adj, visited, i, withStack, st);
	        }
	    }
	    if(withStack)
	        st.push(node);
	}
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        //code here
        stack<int> st_order;
        vector<int> visited(V, 0);
        for(int i = 0; i < V; i++){
            if(visited[i] == 0){
                dfs(adj, visited, i, true, st_order);
            }
        }
        
        vector<vector<int>> revAdj(V);
        for(int i = 0; i < V; i++){
            for(int j : adj[i]){
                revAdj[j].push_back(i);
            }
            visited[i] = 0;
        }
        int count = 0;
        while(!st_order.empty()){
            int node = st_order.top();
            st_order.pop();
            if(visited[node] == 0){            
                dfs(revAdj, visited, node, false, st_order);
                count++;
            }
        }
        
        return count;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends