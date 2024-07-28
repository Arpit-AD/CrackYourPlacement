//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public: 
    
    bool recursion(int arr[], int n, int i, int target, vector<vector<int>>& dp){
        if(target == 0) return true;
        if(target < 0 || i == n) return false;
        
        if(dp[i][target] != -1) return dp[i][target] ? true: false;
        
        bool pick = recursion(arr, n, i+1, target-arr[i], dp);
        bool not_pick = recursion(arr, n, i+1, target, dp);
        
        dp[i][target] = pick | not_pick ? 1 : 0;
        
        return pick | not_pick;
    }
    int equalPartition(int N, int arr[])
    {
        // code here
        int sum = 0;
        for(int i = 0; i < N; i++) sum += arr[i];
        if(sum % 2) return false;
        int target = sum/2;
        vector<vector<int>> dp(N+1, vector<int>(target+1, -1));
        bool possible = recursion(arr, N, 0, sum/2, dp);
        return possible;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends