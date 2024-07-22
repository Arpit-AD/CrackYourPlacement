class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        queue<pair<int, int>> que;
        int n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j]) {
                    que.push({i, j});
                }
            }
        }
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};
        int moves = -1;
        if(que.size() == m*n) return moves;
        while (!que.empty()) {
            int size = que.size();
            moves++;
            while (size--) {
                pair<int, int> pr = que.front();
                int x = pr.first, y = pr.second;
                for (int i = 0; i < 4; i++) {
                    int _x = x + dx[i], _y = y + dy[i];
                    if (!(_x < 0 || _y < 0 || _x >= n || _y >= m ||
                          grid[_x][_y] == 1)) {
                        grid[_x][_y] = 1;
                        que.push({_x, _y});
                    }
                }
                que.pop();
            }
        }

        return moves;
    }
};