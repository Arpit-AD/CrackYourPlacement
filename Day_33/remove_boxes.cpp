class Solution {
    vector<vector<vector<int>>> dp;
public:
    int recursion(vector<int>& boxes, int i, int j, int cnt){
        if(i > j) return 0;
        if(dp[i][j][cnt] != -1) return dp[i][j][cnt];

        int i0 = i, cnt0 = cnt;

        while(i+1 <= j && boxes[i] == boxes[i+1]) i++, cnt++;

        int ans = ((cnt+1) * (cnt+1)) + recursion(boxes, i+1, j, 0);

        for(int k = i+1; k <= j; k++){
            if(boxes[k] == boxes[i]){
                ans = max(ans, recursion(boxes, i+1, k-1, 0) + recursion(boxes, k, j, cnt+1));
            }
        }

        return dp[i0][j][cnt0] = ans;
    }

    int removeBoxes(vector<int>& boxes) {
        int n = boxes.size();
        dp.resize(n+1, vector<vector<int>>(n+1, vector<int>(n+1, -1)));

        return recursion(boxes, 0, n-1, 0);
    }
};  