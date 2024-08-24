class Solution {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> mat(n+1, vector<int>(n+1, 0));
        for(int i = 0; i <=n; i++){
            for(int j = 0; j <= n; j++){
                if(i == j) mat[i][j] = 0;
                else mat[i][j] = 1e7;
            }
        }

        for(int i = 0; i < edges.size(); i++){
            mat[edges[i][0]][edges[i][1]] = 1;
            mat[edges[i][1]][edges[i][0]] = 1;
        }

        vector<int> res(n+1, 0);

        for(int k = 0; k <= n; k++){
            for(int i = 0; i <= n; i++){
                int val = 0;
                for(int j = 0; j <= n; j++){
                    if(mat[i][j] > mat[i][k] + mat[k][j] && mat[k][j] != 1e7 && mat[i][k] != 1e7)
                    {
                        mat[i][j] = mat[i][k] + mat[k][j];
                    }
                }
                for(int j : mat[i]){
                    if(j != 1e7) val += j;
                }
                res[i] = val;
            }
        }

        res.pop_back();
        return res;
    }
};