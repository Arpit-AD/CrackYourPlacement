class Solution {
    vector<vector<string>> ansVec;
    vector<string> strVec;
public:
    
    bool isPossible(int i_index, int j_index, int n){
        
        int i = i_index, j = j_index;
        while(i >= 0)
        {
            if(strVec[i][j] == 'Q')
                return false;
            i--;
        }
        
        i = i_index, j = j_index;
        while(i >= 0 && j >= 0)
        {
            if(strVec[i][j] == 'Q')
                return false;
            i--;
            j--;
        }
        
        i = i_index, j = j_index;
        while(i >= 0 && j < n)
        {
            if(strVec[i][j] == 'Q')
                return false;
            
            i--;
            j++;
        }
        
        return true;     
    }
    
    
    void NQueensHelper(int n, int row){
        if(row == n)
        {
            ansVec.push_back(strVec);
            return;
        }
        
        for(int i = 0; i < n; i++)
        {
            if(isPossible(row,i,n))
            {
                strVec[row][i] = 'Q';
                NQueensHelper(n, row+1);
                strVec[row][i] = '.';
            }
        }
        
        return;
    }
    
    vector<vector<string>> solveNQueens(int n) {
        int k = n;
        string s = "";
        while(k--) s += '.';
            
        for(int i = 0; i < n; i++)
        {
            strVec.push_back(s);
        }
        
        NQueensHelper(n,0);
        
        return ansVec;
    }
};