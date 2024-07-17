class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        int runningSum = 0, count = 0;
        for(int i = 0; i < n; i++){
            runningSum += nums[i];
            if(runningSum == k) count++;
            if(mp.find(runningSum - k) != mp.end()){
                count += mp[runningSum - k];
            }
            mp[runningSum]++;
        }
        return count;
    }
};