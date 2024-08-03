class Solution {
public:
    int recursion(string &s, string &t, int i, int j, vector<vector<int>>& dp){
        if(j < 0) return 1;
        if(i < 0) return 0;
        if(dp[i][j] != 0)
            return dp[i][j];
        if(s[i] == t[j])
            return dp[i][j] = recursion(s,t,i-1,j-1, dp) + recursion(s,t,i-1,j, dp) ;
        
        return dp[i][j] = recursion(s,t,i-1,j, dp);
    }

    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        if(n < m) return 0;
        vector<vector<int>> dp(n, vector<int> (m, 0));
        return recursion(s, t, n-1, m-1, dp);
    }
};

// fastest solution 

class Solution {
public:
    long long numDistinct(string s, string t)
    {
        int n = s.size(), m = t.size();
        vector<unsigned long long> prev(m+1,0);
        vector<unsigned long long> curr(m+1,0);
        
        prev[0] = 1;
        curr[0] = 1;
        for(int i = 0; i <= n; i++)
        {
            if(i == 0) continue;
            for(int j = 1; j <= m; j++)
            {
                if(s[i-1] == t[j-1])
                {
                    curr[j] = prev[j] + prev[j-1];
                }
                else curr[j] = prev[j];
            }
            prev = curr;
        }
        
        
        return curr[m];
        
    }
};


