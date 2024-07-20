//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
    vector<string> res;
  public:
    bool dfs(vector<vector<int>> & mat, int i, int j, int n, string str){
        if(i == n-1 && j == n-1 && mat[i][j] == 1) {
            res.push_back(str);
            return true;
        }
        if(i < 0 || j < 0 || i >= n || j >= n || mat[i][j] == 0) return false;
        mat[i][j] = 0;
        string newStr = str + 'U';
        bool up = dfs(mat, i-1, j, n, newStr);
        newStr = str + 'D';
        bool down = dfs(mat, i+1, j, n, newStr);
        newStr = str + 'L';
        bool left = dfs(mat, i, j-1, n, newStr);
        newStr = str + 'R';
        bool right = dfs(mat, i, j+1, n, newStr);
        mat[i][j] = 1;
        return left | right | up | down;
    }
    
    vector<string> findPath(vector<vector<int>> &mat) {
        // Your code goes here
        string str = "";
        int n = mat.size();
        if(dfs(mat, 0, 0, n, str)) return res;
        return {"-1"};
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends