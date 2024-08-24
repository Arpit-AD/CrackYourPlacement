class Solution {
public:
    int recursion(vector<int>& nums, vector<vector<int>> & dp, int i, int j) {
        if (i > j)
            return 0;
        if(dp[i][j] > 0) return dp[i][j];
        int res = 0;
        for (int idx = i; idx <= j; idx++) {
            int cost = nums[i - 1] * nums[idx] * nums[j + 1] +
                       recursion(nums, dp, i, idx - 1) + recursion(nums, dp, idx + 1, j);
            res = max(res, cost);
        }
        return dp[i][j] = res;
    }
    int maxCoins(vector<int>& nums) {
         int total = 0;
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        vector<vector<int>>  dp(nums.size(), vector<int>(nums.size(), 0));
        return recursion(nums, dp, 1, nums.size()-2);
    }
};