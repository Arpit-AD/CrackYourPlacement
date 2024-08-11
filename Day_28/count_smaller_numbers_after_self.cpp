class Solution {
public:
    void merge(int left, int mid, int right, vector<pair<int,int>> & arr, vector<int> &count){
        vector<pair<int,int>> temp(right - left + 1);
        int i = left, j = mid+1, k = 0;
        while(i <= mid && j <= right){
            if(arr[j].first >= arr[i].first){
                temp[k] = arr[j];
                j++;
            }
            else{
                count[arr[i].second] += right-j+1;
                temp[k] = arr[i];
                i++;
            }
            k++;
        }

        while(i <= mid){
            temp[k] = arr[i];
            i++;
            k++;
        }

        while(j <= right){
            temp[k] = arr[j];
            j++;
            k++;
        }

        i = left, j = right;
        while(i <= j){
            arr[i] = temp[i-left];
            i++;
        }
    }

    void mergeSort(int left, int right, vector<pair<int,int>>& arr, vector<int> &count){
        if(left >= right) return;

        int mid = left + (right - left)/2;
        mergeSort(left, mid, arr, count);
        mergeSort(mid+1, right, arr, count);

        merge(left, mid, right, arr, count);
    }
    // count of i < j and a[i] > a[j] for each index 
    // count inversion type.
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();

        vector<pair<int,int>> arr(n);
        for(int i = 0; i < n; i++){
            arr[i] = {nums[i], i};
        }
        vector<int> count(n, 0);
    
        mergeSort(0, n-1, arr, count);

        return count;
    }
};