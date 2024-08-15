class Solution {
public:
    void recursion(vector<vector<int>>& grid, int si, int sj, int n, int m, int target, int &res){
        if(!(si >= 0 && si < n && sj >= 0 && sj < m)){
            return ;
        }
        
        if(grid[si][sj] == 3 || grid[si][sj] == -1) return;

        if(grid[si][sj] == 2){
            if(target == 1) res++;
            return;
        }
        int val = grid[si][sj];
        grid[si][sj] = 3;
        recursion(grid, si+1, sj, n, m, target-1, res);
        recursion(grid, si-1, sj, n, m, target-1, res);
        recursion(grid, si, sj+1, n, m, target-1, res);
        recursion(grid, si, sj-1, n, m, target-1, res);
        grid[si][sj]  = val;

    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), targetStep = 0;
        int si = -1, sj = -1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == -1) continue;
                targetStep++;
                if(grid[i][j] == 1){
                    si = i;
                    sj = j;
                }
            }
        }
        int res = 0;
        recursion(grid, si, sj, n, m, targetStep, res);
        return res;
    }
};