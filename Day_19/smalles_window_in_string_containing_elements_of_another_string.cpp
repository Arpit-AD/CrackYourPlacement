//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        // Your code here
        int n = s.length(), m = p.length();
        
        if(n < m) return "-1";
        
        int cnt = 0, minLen = 1e9, idx = -1;
        vector<int> mp(26, 0);
        
        int l = 0, r = 0;
        
        for(int i = 0; i < m; i++){
            mp[p[i] - 'a']++;
        }
        
        while(l < n && r < n){
            if(mp[s[r] - 'a'] > 0) cnt++;
            
            mp[s[r] - 'a']--;
            while(cnt == m){
                if(r-l+1 < minLen){
                    minLen = r-l+1;
                    idx = l;
                }
                
                mp[s[l] - 'a']++;
                if(mp[s[l] - 'a'] > 0){
                    cnt--;
                }
                
                l++;
            }
            r++;
        }
        
        if(idx == -1) return "-1";
        
        string res = s.substr(idx, minLen);
        
        return res;
    }
};

//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends