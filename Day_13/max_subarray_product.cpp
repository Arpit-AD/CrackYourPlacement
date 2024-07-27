class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int minProduct = nums[0], maxProduct = nums[0];
        int ansMax = nums[0];
        int maxPossible = nums[0];

        for(int i = 1; i < n; i++){
            maxPossible = max({nums[i], nums[i]*minProduct, nums[i]*maxProduct});
            minProduct = min({nums[i], nums[i]*minProduct, nums[i]*maxProduct});
            maxProduct = maxPossible;
            ansMax = max(maxPossible, ansMax);
        }

        return ansMax;
    }
};