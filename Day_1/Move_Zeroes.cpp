class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size(), i = 0, j = 0;
        while(j < n){
            if(nums[i] == 0 && nums[j] != 0){
                swap(nums[i], nums[j]);
            }
            if(nums[i] != 0) i++;
            j++;
        }
    }
};