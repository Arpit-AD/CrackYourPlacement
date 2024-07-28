//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of cuts.
            vector<int>dp;
    int recursion(int n, int x, int y, int z){
        if(n==0){
            return 0;
        }
        if(n<0){
            return INT_MIN;;
        }
        
        if(dp[n]!=-1){
            return dp[n];
        }
        
        int takex=INT_MIN;
        if(n-x>=0)
         takex=1+recursion(n-x,x,y,z);
         
         int takey=INT_MIN;
         if(n-y>=0)
         takey=1+recursion(n-y,x,y,z);
         
        int takez=INT_MIN;
         if(n-z>=0)
         takez=1+recursion(n-z,x,y,z);
         
        return dp[n]=max(takex,max(takey,takez));
    }
    
    int maximizeTheCuts(int n, int x, int y, int z)
    {
         int count=0;
         dp.resize(n+1,-1);
         
         int ans= recursion(n,x,y,z);
          return (ans<0) ?0: ans;
    }
};

//{ Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

    return 0;
}
// } Driver Code Ends