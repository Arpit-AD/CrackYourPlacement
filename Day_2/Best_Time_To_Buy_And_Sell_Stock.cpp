class Solution {
public:
    int recursion(vector<int>& prices, int n, int idx, int buy, vector<vector<int>> &dp) {
        if (idx == n)
            return 0;

        if(dp[buy][idx] != -1) return dp[buy][idx];

        if (buy == 1)
            dp[buy][idx] = max(recursion(prices, n, idx + 1, 0, dp) - prices[idx],
                         recursion(prices, n, idx + 1, 1, dp));
        if (buy == 0)
            dp[buy][idx] = max(prices[idx] + recursion(prices, n, idx + 1, 1, dp),
                         recursion(prices, n, idx + 1, 0, dp));

        return dp[buy][idx];
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(2, vector<int>(n+1,-1));

        int _maxProfit = recursion(prices, n, 0, 1, dp);

        return _maxProfit;
    }
};