class Solution {
public:
    bool canJump(vector<int>& nums) {
        int canJumpTo = 0;
        int n = nums.size();
        for(int i = 0; i <= canJumpTo; i++){
            if(i == n-1) return true;
            canJumpTo = max(canJumpTo, nums[i] + i);
        }

        return false;
    }
};