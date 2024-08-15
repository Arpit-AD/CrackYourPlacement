//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to find the largest number after k swaps.
    void recursion(string & str, int k, int idx, string& ans){
        if(k == 0 || idx >= str.size()){
            ans = max(str, ans);
            return;
        }
        char mx = str[idx];
        for(int i = idx; i < str.length(); i++){
            if(i == idx) recursion(str, k, idx+1, ans);
            if(str[i] > mx){
                swap(str[i], str[idx]);
                recursion(str, k-1, idx + 1, ans);
                swap(str[i], str[idx]);
            }
        }
    }
    string findMaximumNum(string str, int k)
    {
       // code here.
       string ans = str;
       recursion(str, k, 0, ans);
       
       return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t, k;
    string str;

    cin >> t;
    while (t--)
    {
        cin >> k >> str;
        Solution ob;
        cout<< ob.findMaximumNum(str, k) << endl;
    }
    return 0;
}

// } Driver Code Ends