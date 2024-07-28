#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dfs(vector<vector<int>>& mat, vector<vector<int>>& dp, int r, int c) {
        if (dp[r][c] != -1) {
            return dp[r][c];
        }
        
        int drow[4] = {-1, 0, 1, 0};
        int dcol[4] = {0, 1, 0, -1};
        
        int maxPath = 1;  
        for (int i = 0; i < 4; i++) {
            int nr = r + drow[i];
            int nc = c + dcol[i];
            
            if (nr >= 0 && nc >= 0 && nr < mat.size() && nc < mat[0].size() && mat[nr][nc] > mat[r][c]) {
                maxPath = max(maxPath, 1 + dfs(mat, dp, nr, nc));
            }
        }
        
        dp[r][c] = maxPath;
        return dp[r][c];
    }

    int longestIncreasingPath(vector<vector<int>>& mat) {
        if (mat.empty()) return 0;

        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));  
        
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (dp[i][j] == -1) {  
                    ans = max(ans, dfs(mat, dp, i, j));
                }
            }
        }
        return ans;
    }
};