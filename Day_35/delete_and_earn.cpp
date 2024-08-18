
class Solution {
    int dp[20001];
public:
    int recursion(vector<int> &nums, int i)
    {
        if(i >= nums.size()) return 0; 
        
        if(dp[i] != -1) return dp[i];
        
        int currValue = nums[i];  
        int currSum = nums[i]; 
        int idx = i + 1; 
        while(idx < nums.size() && nums[idx] == currValue)
        {
            currSum += nums[i];
            idx++;
        }
        
        while(idx < nums.size() && nums[idx] == currValue + 1)
        {
            idx++;
        }
        
        return dp[i] = max(currSum + recursion(nums, idx), recursion(nums, i + 1));
    }
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        
        memset(dp, -1, sizeof(dp));

        sort(nums.begin(), nums.end());
        return recursion(nums, 0);
    }
};