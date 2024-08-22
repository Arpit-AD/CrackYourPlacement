class Solution {
public:
    int findMaxSquare(vector<vector<char>>& matrix, int row, int col, int &maxSideLength,vector<vector<int>>&memo) {
        if (row >= matrix.size() || col >= matrix[0].size()) return 0;
        if(memo[row][col]!=-1) return memo[row][col];
        int right = findMaxSquare(matrix, row, col + 1, maxSideLength,memo);
        int diagonal = findMaxSquare(matrix, row + 1, col + 1, maxSideLength,memo);
        int down = findMaxSquare(matrix, row + 1, col, maxSideLength,memo);

        if (matrix[row][col] == '1') {
            int currentSideLength = 1 + min({right, diagonal, down});
            memo[row][col] = currentSideLength ;
            maxSideLength = max(maxSideLength, currentSideLength);
            return memo[row][col] ;
        }
        return 0;
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        int maxSideLength = 0;
        vector<vector<int>>memo(matrix.size(),vector<int>(matrix[0].size(),-1));
        findMaxSquare(matrix, 0, 0, maxSideLength,memo);
        return maxSideLength * maxSideLength;
    }
};