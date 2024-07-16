class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int element = nums[0];
        int cnt = 0;
        for(int i : nums){
            if(element == i){
                cnt++;
            }
            else cnt--;
            if(cnt == 0){
                candidate = z;
                cnt = 1;
            }  
        }

        return candidate;
    }
};