class Solution {
public:
    void dfsFloodFill(vector<vector<int>>& image, int sr, int sc, int color, int k, int n, int m) {
        if(image[sr][sc] != k)  return;
        image[sr][sc] = color;

        if(sr+1 < n) dfsFloodFill(image, sr+1, sc, color,k, n, m);
        if(sr-1 >= 0) dfsFloodFill(image, sr-1, sc, color, k, n, m);
        if(sc+1 < m) dfsFloodFill(image, sr, sc+1, color, k, n, m);
        if(sc-1 >= 0) dfsFloodFill(image, sr, sc-1, color, k, n, m);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        int k = image[sr][sc];
        if(k == color) return image;
        dfsFloodFill(image, sr, sc, color, k, n ,m);
        return image;
    }
};