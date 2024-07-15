class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // n2 is the best complexity possible code generally runs about 2*n2
        int n = matrix.size(), m = matrix[0].size(), row = 0, col = 0;
        for(int i = 0; i < n; i++){
            for(int j =0; j < m; j++){
                if(matrix[i][j] == 0){
                    if(i == 0) row = -1;
                    if(j == 0) col = -1;
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for(int i = 1; i < n; i++){
            for(int j = 1; j < m ; j++){
                if(matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }

        if(row == -1) {
            for(int j= 0; j <m; j++){
                matrix[0][j] =0;
            }
        }
        if(col == -1){
            for(int i = 0; i < n; i++){
                matrix[i][0] = 0;
            }
        }
    }
};