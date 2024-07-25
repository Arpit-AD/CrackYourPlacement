class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size(); 
        int res = 0;
        sort(nums.begin(), nums.end());
        int l = nums[n/2];
        for(int it: nums){
            res += abs(it - l);
        }

        return res;
    }
};