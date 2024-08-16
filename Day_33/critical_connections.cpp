class Solution {
public:

 void dfs(int node,int parent,int &timer, vector<int> &disc,
 vector<int>&low,vector<vector<int>> &result, vector<int>adj[]    
 ,vector<bool>&visited)
{

    visited[node]=true ;
    disc[node]=low[node]=timer++ ;


    for(auto nbr:adj[node]) // avoid looping
    {
        if(nbr==parent)
            continue;

        if(!visited[nbr])
        {
            dfs(nbr ,  node, timer, disc, low, result,  adj,  visited);
            low[node]=min(low[node],low[nbr]) ;

            // if bridge 
            if(low[nbr]>disc[node])
            {
                vector<int>ans ;
                ans.push_back(node) ;
                ans.push_back(nbr) ;
                result.push_back(ans) ;
            }
        }
        else
        {
            //means backedge
            low[node]=min(low[node],disc[nbr]) ;

        }
    }


}
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& edges) {
        
        vector<int>adj[n] ;
   for(int i=0;i<edges.size();i++)
   {
       int u=edges[i][0] ;
       int v=edges[i][1] ;

       adj[u].push_back(v) ;
       adj[v].push_back(u) ;
       
   }

   int timer=0 ;
   vector<int>disc(n,-1) ;
    vector<int>low(n,-1) ;
   int parent=-1 ;
   vector<bool>visited(n) ;


   vector<vector<int>> result ;
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
    {
        dfs(i,parent,timer,disc,low,result,adj,visited) ;
    }

    }
   
   return result ;
        
    }
};