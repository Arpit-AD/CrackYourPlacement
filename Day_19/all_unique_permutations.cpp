//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
    void recursion(vector<int> & arr, int n, set<vector<int>> &st, int idx) {
        if(st.find(arr) == st.end() && idx == n)
            st.insert(arr);
        
        for(int i = idx; i < n; i++){
            if(i != idx && arr[i] == arr[idx]) continue;
            
            swap(arr[i], arr[idx]);
            recursion(arr, n, st, idx+1);
            swap(arr[i], arr[idx]);
        }
    }
  
    vector<vector<int>> uniquePerms(vector<int> &arr ,int n) {
        // code here
        set<vector<int>> st;
        
        recursion(arr, n, st, 0);
        
        vector<vector<int>> res(st.begin(), st.end());
        
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;
        vector<int> arr(n);
        
        for(int i=0 ; i<n ; i++)
            cin>>arr[i];

        Solution ob;
        vector<vector<int>> res = ob.uniquePerms(arr,n);
        for(int i=0; i<res.size(); i++)
        {
            for(int j=0; j<n; j++)
            {
                cout<<res[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends