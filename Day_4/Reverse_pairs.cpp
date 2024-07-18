class Solution {
public:
    int merge(vector<int> &nums, int si, int mid, int ei){
        int count = 0;
        int j = mid+1;
        for(int i = si; i <= mid; i++){
            while(j <= ei && nums[i] > 2*nums[j]){
                j++;
            }
            count += (j- (mid+1));
        }
        vector<int> temp;
        int idx  = si, jdx = mid + 1;
        while(idx <= mid && jdx <= ei){
            if(nums[idx] < nums[jdx]) {
                temp.push_back(nums[idx]);
                idx++;
            }
            else{
                temp.push_back(nums[jdx]);
                jdx++;
            }
        }

        while(idx <= mid){
            temp.push_back(nums[idx]);
            idx++;
        }

        while(jdx <= ei){
            temp.push_back(nums[jdx]);
            jdx++;
        }

        j = 0;
        for(int i = si; i <= ei; i++, j++){
            nums[i] = temp[j];
        }

        return count;        
    }

    int mergeSort(vector<int> & nums, int si, int ei){
        if(si >= ei) return 0;
        int mid = (si + ei)/2;

        int count = mergeSort(nums, si, mid);
        count += mergeSort(nums, mid+1, ei);

        count += merge(nums, si, mid, ei);

        return count;
    } 

    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        return mergeSort(nums, 0, n-1);
    }
};