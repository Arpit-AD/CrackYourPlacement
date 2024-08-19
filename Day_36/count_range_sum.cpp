class SegmentTree{
private:
    int n;
    vector<int> arr;
public:
    SegmentTree(int size): n(size), arr(2*size){
        arr[0] = 0;
        for(int i = 0; i < n; ++i){
            arr[i+n] = 1;
        }
        for(int i = n-1; i > 0; --i){
            arr[i] = arr[2*i]+arr[2*i+1];
        }
    }
    void addValue(int idx, int val){
        idx += n;
        arr[idx] += val;
        while(idx > 1){
            if(idx%2){
                arr[idx/2] = arr[idx-1] + arr[idx];
            }else{
                arr[idx/2] = arr[idx] + arr[idx+1];
            }
            idx >>= 1;
        }
    }
    int getSum(int left, int right){
        int count = 0;
        left += n;
        right += n;
        while(left <= right){
            if(left%2){
                count += arr[left++];
            }
            if(right%2 == 0){
                count += arr[right--];
            }
            left >>= 1;
            right >>= 1;
        }
        return count;
    }
};
class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper){
    vector<long long> sum(nums.size()+1, 0);
    for(int i = 0; i < nums.size(); ++i){
        sum[i+1] = sum[i]+nums[i];
    }
    vector<long long> A(sum.begin(), sum.end());
    sort(A.begin(), A.end());
    SegmentTree tree(A.size());
    int count = 0;
    for(const auto &x : sum){
        int idx = lower_bound(A.begin(), A.end(), x)-A.begin();
        int lowerIdx = lower_bound(A.begin(), A.end(), x+lower)-A.begin();
        int upperIdx = upper_bound(A.begin(), A.end(), x+upper)-A.begin()-1;
        tree.addValue(idx, -1);
        count += tree.getSum(lowerIdx, upperIdx);
    }
    return count;
}
};