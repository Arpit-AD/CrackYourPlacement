class Solution {
    int dp[2505][2505];
public:
    int recursion(vector<int> & nums, int i, int prev_i){
        if(i == nums.size()){
            return 0;
        }
        if(dp[i][prev_i+1] != -1) return dp[i][prev_i+1];

        int take = 0;
        if(prev_i == -1 || nums[i] > nums[prev_i])
            take = 1 + recursion(nums, i + 1, i);
        int not_take = 0 + recursion(nums, i + 1, prev_i);
        
        return dp[i][prev_i+1] = max(take , not_take);
    }

    int lengthOfLIS(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        int res = recursion(nums, 0, -1);

        return res;
    }
};