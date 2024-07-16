class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        for(int i = 0; i < nums.size(); i++){
            int data = abs(nums[i]) -1;
            if(nums[data] < 0) res.push_back(abs(nums[i]));
            else nums[data] = -1*nums[data];
        }

        return res;
    }
};