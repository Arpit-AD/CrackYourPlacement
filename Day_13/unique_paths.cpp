class Solution {
public:
    int recursion(vector<vector<int>>& dp, int m, int n, int i, int j){
        if(i > m-1 || j > n-1) return 0;

        if(i == m-1 && j == n-1) return 1;
        if(dp[i][j] != -1) return dp[i][j]; 
        int down = recursion(dp, m, n, i+1, j);
        int right = recursion(dp, m, n, i, j+1);

        return dp[i][j] = down + right;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        int res = recursion(dp, m, n, 0, 0);
        
        return res;
    }
};