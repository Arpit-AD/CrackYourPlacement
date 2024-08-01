class Solution {
public:
    int partition(vector<int> & nums, int si, int ei){
        int pivot = nums[si];
        int l = si + 1, r = ei;

        while(l <= r){
            if(nums[l] < pivot && nums[r] > pivot){
                swap(nums[l], nums[r]);
                l++;
                r--;
            }
            if(nums[l] >= pivot) l++;
            if(nums[r] <= pivot) r--;
        }

        swap(nums[si], nums[r]);
        return r;
    }
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        int si = 0, ei = n-1;
        int ans = -1;
        while(1){
            int idx = partition(nums,si, ei);
            if(k-1 == idx){
                ans = nums[idx];
                break;
            }
            if(idx >= k-1) ei = idx-1;
            else si = idx+1;
        }

        return ans;
    }
};