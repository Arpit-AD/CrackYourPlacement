class Solution {
    vector<vector<int>> dp;
public:

    int recursion(int k, int n){
        if(n == 0 || n == 1) return n;
        if(k == 1) return n;

        if(dp[n][k] != -1) return dp[n][k];

        int ans = 1e6, l = 1, h = n, temp = 0;

        while(l <= h){
            int mid = (l+h)/2;
            int left = recursion(k-1, mid -1);
            int right = recursion(k, n-mid);
            temp = 1 + max(left, right);
            if(left < right){
                l = mid + 1;
            }
            else{
                h = mid - 1;
            }
            ans = min(temp, ans);
        }

        return dp[n][k] = ans;
    }

    int superEggDrop(int k, int n) {
        dp = vector<vector<int>>(n+1, vector<int>(k+1, -1));
        return recursion(k, n);
    }
};