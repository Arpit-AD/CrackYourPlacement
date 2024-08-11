class Solution {
public:
    int getMaxDivisionPossible(vector<int> & nums, int target){
        int runningSum = 0, cnt = 1;
        for(int i : nums){
            if(runningSum + i > target){
                cnt++;
                runningSum = i;
            }
            else {
                runningSum += i;
            }
        }

        return cnt;
    }

    int splitArray(vector<int>& nums, int k) {
        int _max = -1e9, sum = 0;
        for(int i : nums){
            _max = max(_max, i);
            sum += i;
        }
        
        int si = _max, ei = sum, ans = INT_MAX;

        while(si <= ei){
            int mid = si - (si - ei)/2;
            int cnt = getMaxDivisionPossible(nums, mid);

            if(cnt > k){
                si = mid + 1;
            }
            else {
                ans = mid;
                ei = mid - 1;
            }
        }
        return ans;
    }
};