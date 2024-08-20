class NumMatrix {
    vector<vector<int>> a;
public:
    vector < vector <int>> dp;
   NumMatrix(vector<vector<int>>& matrix) {
      int n = matrix.size();
      if(!n) return;
      int m = matrix[0].size();
      dp = vector < vector <int>>(n, vector <int> (m));
      for(int i = 0; i < n; i++){
         for(int j = 0 ;j < m; j++){
            dp[i][j] = j - 1 < 0 ? matrix[i][j] : dp[i][j - 1] + matrix[i][j];
         }
      }
      for(int i = 1; i < n; i++){
         for(int j = 0; j < m; j++){
            dp[i][j] += dp[i - 1][j];
         }
      }
   }
   int sumRegion(int row1, int col1, int row2, int col2) {
      int ret = dp[row2][col2];
      int sub1 = row1 - 1 < 0 ? 0 : dp[row1 - 1][col2];
      int sub2 = col1 - 1 < 0 ? 0 : dp[row2][col1 - 1];
      int add = row1 - 1 < 0 || col1 - 1 < 0 ? 0 : dp[row1 - 1][col1 - 1];
      return ret - sub1 - sub2 + add;
   }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */