class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> distance(n + 1, vector<int>(n + 1, 1e9));

        for (int i = 0; i < edges.size(); i++) {
            distance[edges[i][0]][edges[i][1]] = edges[i][2];
            distance[edges[i][1]][edges[i][0]] = edges[i][2];
        }

        for(int i = 0; i < n; i++){
            distance[i][i] = 0;
        }

        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (distance[i][j] > distance[i][k] + distance[k][j] &&
                        distance[i][k] != 1e9 && distance[k][j] != 1e9) {
                        distance[i][j] = distance[i][k] + distance[k][j];
                    }
                }
            }
        }

        int citiesVisit = 1e9, node = -1;
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (distance[i][j] <= distanceThreshold) {
                    cnt++;
                }
            }
            if (cnt <= citiesVisit) {
                citiesVisit = cnt;
                node = i;
            }
        }

        return node;
    }
};