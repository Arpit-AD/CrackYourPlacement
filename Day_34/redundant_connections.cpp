class DisjointSet{
    vector<int> parent, size;
public:
    DisjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1);

        for(int i = 0; i <= n; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findParent(int node){
        if(node == parent[node]) return node;
        return parent[node] = findParent(parent[node]);
    }

    bool findParentEqual(int u, int v){
        return findParent(u) == findParent(v);
    }

    void unionBySize(int u, int v){
        int pu = findParent(u);
        int pv = findParent(v);

        if(pu == pv) return;
        if(size[pu] > size[pv]){
            parent[pv] = pu;
            size[pu] += size[pv];
        } else { 
            parent[pu] = pv;
            size[pv] += pu;
        }
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        DisjointSet ds(n+1);
        vector<int> res;
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0], v = edges[i][1];
            if(!ds.findParentEqual(u, v)){
                ds.unionBySize(u, v);
            }
            else res = edges[i];
        }

        return res;
    }
};