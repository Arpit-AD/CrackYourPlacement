class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        int runningSum = 0;
        unordered_map<int,int> mp;
        mp[0] = 1;
        int count = 0;
        
        for(int i = 0; i < n; i++){
            runningSum += nums[i];
            int remainder = runningSum % k;
            remainder = remainder < 0 ? remainder + k : remainder;
            if(mp.find(remainder) != mp.end()){
                count += mp[remainder];
            }
            mp[remainder]++;
        }
 
        return count;
    }
};