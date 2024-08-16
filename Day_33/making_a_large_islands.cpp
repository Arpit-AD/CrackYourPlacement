class DisjointSet {
    vector<int> parent, size;
public: 
    DisjointSet(int n){
        parent.resize(n + 1);
        size.resize(n + 1);

        for(int i = 0; i < n + 1; i++){
            size[i] = 1;
            parent[i] = i;
        }   
    }

    int findParent(int node){
        if(node == parent[node]) return node;
        return parent[node] = findParent(parent[node]);
    }

    void unionBySize(int u, int v){
        int pu = findParent(u);
        int pv = findParent(v);

        if(pu == pv) return;
        if(size[pv] > size[pu]){
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }

    int getSize(int node){
        return size[node];
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n*n);
        
        vector<int> dr = {-1,0,1,0};
        vector<int> dc = {0,-1,0,1};

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    for(int k = 0; k < 4; k++){
                        int r = i + dr[k];
                        int c = j + dc[k];

                        if(r >= 0 && r < n && c >= 0 && c < n && grid[r][c] == 1){
                            int node = n*i + j;
                            int adj_node = n*r + c;
                            ds.unionBySize(node, adj_node);
                        }
                    }
                }
            }
        }

        int ans = 1;

        for(int i = 0; i < n*n; i++){
            ans = max(ans, ds.getSize(i));
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0){

                    unordered_set<int> st;
                    for(int k = 0; k < 4; k++){
                        int r = i + dr[k];
                        int c = j + dc[k];
                        
                        if(r >= 0 && r < n && c >= 0 && c < n && grid[r][c] == 1){
                            int adj_node = n*r + c;
                            st.insert(ds.findParent(adj_node));
                        } 
                    }

                    int temps = 1;
                    for(auto it: st){
                        temps += ds.getSize(it);
                    }

                    ans = max(ans, temps);
                }
            }
        }

        return ans;
    }
};