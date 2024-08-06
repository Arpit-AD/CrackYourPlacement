class Solution {
    vector<vector<int>> res;
public:
    void recursion(vector<int> & nums, int idx, vector<int> & vec){
        res.push_back(vec);
        for(int i = idx; i < nums.size(); i++){
            if(i != idx && nums[i] == nums[i-1]) continue;
            vec.push_back(nums[i]);
            recursion(nums, i+1, vec);
            vec.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> vec;
        recursion(nums, 0, vec);
        return res;
    }
};