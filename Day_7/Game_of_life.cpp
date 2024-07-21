

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> x= board;
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[i].size();j++)
            {
                int countlive=liveneighbors(board,i,j);
                if(board[i][j] && countlive<2)
                    board[i][j]=-1;
                if(board[i][j] && countlive>3)
                    board[i][j]=-1;
                if(board[i][j]==0 && countlive==3)
                    board[i][j]=2;
                }
        }
         for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[i].size();j++)
            {
                if(board[i][j]==-1)
                    board[i][j]=0;
                else if(board[i][j]==2)
                    board[i][j]=1;
            }
         }
    }
    
    
    int liveneighbors(vector<vector<int>>& board,int i,int j){
        int count=0;
        int b=board.size();
        int c=board[i].size();
        if(i-1>=0 && i-1<b && j-1>=0 && j-1<c)
        {
            if(board[i-1][j-1]==-1 || board[i-1][j-1]==1)
                count++;
        }
        if(i-1>=0 && i-1<b && j>=0 && j<c)
        {
            if(board[i-1][j]==-1 || board[i-1][j]==1)
                count++;
        }
        if(i-1>=0 && i-1<b && j+1>=0 && j+1<c)
        {
            if(board[i-1][j+1]==-1 || board[i-1][j+1]==1)
                count++;
        }
        if(i>=0 && i<b && j-1>=0 && j-1<c)
        {
            if(board[i][j-1]==-1 || board[i][j-1]==1)
                count++;
        }
        if(i>=0 && i<b && j+1>=0 && j+1<c)
        {
            if(board[i][j+1]==-1 || board[i][j+1]==1)
                count++;
        }
        if(i+1>=0 && i+1<b && j-1>=0 && j-1<c)
        {
            if(board[i+1][j-1]==-1 || board[i+1][j-1]==1)
                count++;
        }
        if(i+1>=0 && i+1<b && j>=0 && j<c)
        {
            if(board[i+1][j]==-1 || board[i+1][j]==1)
                count++;
        }
        if(i+1>=0 && i+1<b && j+1>=0 && j+1<c)
        {
            if(board[i+1][j+1]==-1 || board[i+1][j+1]==1)
                count++;
        }
        return count;
    }
};