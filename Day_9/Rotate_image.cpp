
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < i; j++)
            {
                swap(matrix[i][j],matrix[j][i]);   
            }
        } // TRANSPOSE OF MATRIX
        
        for(int i = 0; i < n; i++)
        {
            reverse(matrix[i].begin(),matrix[i].end());
        }
        
        
    }
};

/*

Transpose
1 4 7 -> 7 4 1
2 5 8 -> 8 5 2
3 6 9 -> 9 6 3
    
*/