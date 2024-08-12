class Solution {
public:
    int recursion(vector<int> & prices, int k, int i, int buy, vector<vector<vector<int>>> & dp){
        if(i == prices.size() || k == 0) return 0;
        int profit = 0;
        if( dp[i][k][buy]  != -1) return  dp[i][k][buy] ;
        if(buy){
            profit = max(recursion(prices, k, i+1, 0, dp)-prices[i], recursion(prices, k, i+1, 1, dp));
        }
        else{
            profit = max(recursion(prices, k-1, i+1, 1, dp)+prices[i], recursion(prices, k, i+1, 0, dp));
        }

        return dp[i][k][buy] = profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        int z = 2, n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(k+1, vector<int>(z, -1)));
        return recursion(prices, k, 0, 1, dp);
    }
};