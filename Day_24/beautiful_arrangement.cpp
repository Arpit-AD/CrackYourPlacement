class Solution {
public:
    void recursion(int n, int idx, vector<int>& nums, int &count){
        if(idx > n){
            count++;
            return;
        }
        for(int i = 1; i <= n; i++){
            if(nums[i] == 0 && (idx % i == 0 || i % idx == 0)){
                nums[i] = idx;
                recursion(n, idx+1, nums, count);
                nums[i] = 0;
            }
        }
    }
    int countArrangement(int n) {
        vector<int> nums(n+1, 0);
        int count = 0;
        recursion(n, 1, nums, count);
        return count;
    }
};