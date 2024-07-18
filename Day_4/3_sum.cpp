class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>> st;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; i++){
            int sum = nums[i], si = i+1, ei = n-1;
            while(si < ei){
                int temp_sum = nums[si] + nums[ei];
                if(sum + temp_sum == 0){
                    st.insert({nums[i], nums[si], nums[ei]});
                    ei--; si++;
                }
                else if(sum + temp_sum > 0) ei--;
                else si++;
            }
        }

        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};