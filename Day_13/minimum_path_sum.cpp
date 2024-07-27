class Solution {
    int dp[205][205];
public:
    int recursion(vector<vector<int>> & grid, int i, int j, int n, int m){
        if(i == n-1 && j == m-1){
            return grid[i][j];
        }
        if(dp[i][j] != -1) return dp[i][j];
        int right = j + 1 < m ? grid[i][j] + recursion(grid, i, j+1, n, m) : INT_MAX;
        int down =  i + 1 < n ? grid[i][j] + recursion(grid, i+1, j, n, m) : INT_MAX;
        
        return dp[i][j] = min(right, down);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        memset(dp, -1, sizeof(dp));
        int res = recursion(grid, 0, 0, n, m);

        return res;
    }
};