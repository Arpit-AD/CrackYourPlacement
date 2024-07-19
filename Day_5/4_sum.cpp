class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        set<vector<int>> st;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                long long sum = nums[i] + nums[j];
                int si = j+1, ei = n-1;
                while(si < ei){
                    long long temp_sum = nums[si] + nums[ei];
                    if(sum + temp_sum == target){
                        st.insert({nums[i], nums[j], nums[si], nums[ei]});
                        ei--; si++;
                    }
                    else if (sum + temp_sum > target) ei--;
                    else si++;
                }
            }
        }

        vector<vector<int>> vec(st.begin(), st.end());
        return vec;
    }
};