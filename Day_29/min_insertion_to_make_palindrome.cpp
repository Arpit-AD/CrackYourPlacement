class Solution {
public:
    int recursion(string s, string r, int n, int m, vector<vector<int>>& dp)
    {
        if(n < 0 || m < 0) return 0;
        
        if(dp[n][m] != -1) return dp[n][m];
        if(s[n] == r[m]) return dp[n][m] = 1+recursion(s,r,n-1,m-1,dp);
        
        return dp[n][m] = max(recursion(s,r,n-1,m,dp),recursion(s,r,n,m-1,dp));
         
    }    
    
    int minInsertions(string s) {
        string r = s;
        reverse(r.begin(),r.end());
        int n = s.size();
        
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int i = 1; i <= n ; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(s[i-1] == r[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        
        
        int lcs = dp[n][n];
        return n - lcs;
    }
};