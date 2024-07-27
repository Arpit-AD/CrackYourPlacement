class Solution {

public:
    int recursion(vector<int>& coins, int amount, int i,  vector<vector<int>>& dp) {
        if (amount == 0)
            return 0;
        if (i < 0 || amount < 0) {
            return 1e9;
        }
        if(dp[i][amount] != -1) return dp[i][amount];
        int not_take = recursion(coins, amount, i - 1, dp);
        int take = INT_MAX;
        if (amount >= coins[i])
            take = 1 + recursion(coins, amount - coins[i], i, dp);
        return dp[i][amount] = min(take, not_take);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int>(amount+1, -1));
        int res = recursion(coins, amount, n - 1, dp);
        return res == 1e9 ? -1 : res;
    }
};