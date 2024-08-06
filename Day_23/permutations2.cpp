class Solution {
    vector<vector<int>> res;
public:
    void recursion(vector<int> nums, int idx){
        if(idx == nums.size()){
            res.push_back(nums);
            return;
        }
        for(int i = idx; i < nums.size(); i++){
            if(i == idx || nums[idx] != nums[i]){
                swap(nums[idx], nums[i]);
                recursion(nums, idx+1);
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        recursion(nums, 0);
        return res;
    }
};