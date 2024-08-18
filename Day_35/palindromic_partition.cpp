//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    vector<vector<string>> res;
  public:
    void recursion(string s, vector<string> &vec){
        if(s.length() == 0){
            res.push_back(vec);
            return;
        }
        string s_copy = "";
        string rev = "";

        for(int i = 0; i < s.length(); i++){
            s_copy += s[i];
            rev = s_copy;
            reverse(rev.begin(), rev.end());
            if(s_copy == rev){
                vec.push_back(s_copy);
                recursion(s.substr(i+1), vec);
                vec.pop_back();
            }
        }
    }
    vector<vector<string>> allPalindromicPerms(string S) {
        // code here
        vector<string> vec;
        recursion(S, vec);
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        
        cin>>S;

        Solution ob;
        vector<vector<string>> ptr = ob.allPalindromicPerms(S);
        
        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                cout<<ptr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends